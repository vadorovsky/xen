/******************************************************************************
 * coco.c
 */

#include <xen/types.h>
#include <public/hvm/coco.h>
#include <xen/errno.h>
#include <xen/domain.h>
#include <xen/guest_access.h>

long
do_dom_coco_op(unsigned int cmd, XEN_GUEST_HANDLE_PARAM(void) arg)
{
#ifdef CONFIG_X86
    sev_launch_update_data_t data = {};

    if ( unlikely(copy_from_guest(&data, arg, 1)) )
        return -EFAULT;

    return arch_dom_coco_op(cmd, data.domid, data.address, data.len);
#else
    return -ENOSYS;
#endif
}
