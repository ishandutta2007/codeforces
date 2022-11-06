#!/usr/bin/python3
# Copyright (C) 2017 Sayutin Dmitry.
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

import sys

def main():
    k, a, b = map(int, input().split())

    if a == 0 or b == 0:
        if (a + b) % k == 0:
            print((a + b) // k)
        else:
            print(-1)
    elif a % k == 0 or b % k == 0:
        print(a // k + b // k)
    elif a // k >= 1 and b // k >= 1:
        print(a // k + b // k)
    else:
        print(-1)

main()