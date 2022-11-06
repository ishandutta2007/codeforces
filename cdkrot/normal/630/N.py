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

a, b, c = map(int, input().split())
dsqrt = (b * b - 4 * a * c) ** 0.5
sol1 = (-b + dsqrt) / (2.0 * a)
sol2 = (-b - dsqrt) / (2.0 * a)
if not (sol1 > sol2):
    sol1, sol2 = sol2, sol1
print("%10.10f" % sol1)
print("%10.10f" % sol2)