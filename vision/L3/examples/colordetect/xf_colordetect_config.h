/***************************************************************************
Copyright (c) 2018, Xilinx, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

***************************************************************************/

#ifndef _XF_COLORDETECT_CONFIG_H_
#define _XF_COLORDETECT_CONFIG_H_

#include "hls_stream.h"
#include "ap_int.h"
#include "common/xf_common.h"
#include "common/xf_utility.h"
#include "imgproc/xf_channel_combine.hpp"
#include "imgproc/xf_colorthresholding.hpp"
#include "imgproc/xf_bgr2hsv.hpp"
#include "imgproc/xf_erosion.hpp"
#include "imgproc/xf_dilation.hpp"
//#include "xf_config_params.h"

//#define MAXCOLORS 3

/* Set the image height and width */
#define HEIGHT 2160
#define WIDTH 3840

/* Color thresholding parameters */
#define MAXCOLORS 3

/* Erode and Dilate parameters */
#define FILTER_SIZE 3
#define KERNEL_SHAPE 0 // 0 - rectangle, 1 - ellipse, 2 - cross
#define ITERATIONS 1

// Set the optimization type:
#define NPC1 XF_NPPC1

// Set the input and output pixel depth:
#define IN_TYPE XF_8UC3
#define OUT_TYPE XF_8UC1
#define PTR_IN_WIDTH 32
#define PTR_OUT_WIDTH 8

// Resolve mask shape:
#if KERNEL_SHAPE == 0
#define XF_KERNEL_SHAPE XF_SHAPE_RECT
#elif KERNEL_SHAPE == 1
#define XF_KERNEL_SHAPE XF_SHAPE_ELLIPSE
#elif KERNEL_SHAPE == 2
#define XF_KERNEL_SHAPE XF_SHAPE_CROSS
#else
#define XF_KERNEL_SHAPE XF_SHAPE_RECT
#endif

#endif