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

import math

a, b, c = map(int, input().split())
v1 = (a ** 3) * (2 ** 0.5) / 12
v2 = (b ** 3) * (2 ** 0.5) / 6

phi = 2 * math.pi / 5
L = c / ((2 - 2 * math.cos(phi)) ** 0.5)
v3 = 2.5 * L * L * math.sin(phi) * ((c * c - L * L) ** 0.5) / 3

print(v1 + v2 + v3)