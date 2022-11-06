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

def main():
    t = int(input())
    for tc in range(t):
        x, y, p, q = map(int, input().split())

        k0 = (y + (q - 1)) // q

        lo = -1
        hi = 10 ** 15
        while hi - lo > 1:
            mi = lo + (hi - lo) // 2

            if x <= p * (k0 + mi) <= x + (q * (k0 + mi) - y):
                hi = mi
            else:
                lo = mi
        #print(hi, x, y, p, q, k0)
        print(-1 if hi == 10 ** 15 else q * (k0 + hi) - y)

main()