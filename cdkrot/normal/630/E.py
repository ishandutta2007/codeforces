#!/usr/bin/python3
# Copyright (C) 2016 Sayutin Dmitry.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; version 3
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; If not, see <http://www.gnu.org/licenses/>.

def calc(y1, y2, r):
    if y1 % 2 != r:
        y1 -= 1
    if y2 % 2 != r:
        y2 += 1
    return (y2 - y1) // 2

x1, y1, x2, y2 = map(int, input().split())
x2, y2, x1, y1 = x2 - x1, y2 - y1, 0, 0

xlen = x2 - x1 + 1
odd, even = xlen // 2, xlen // 2
if xlen % 2 == 1:
    if x1 % 2 == 1:
        odd += 1
    else:
        even += 1
print(odd * calc(y1, y2, 0) + even * calc(y1, y2, 1))