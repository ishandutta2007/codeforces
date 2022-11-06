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

def main():
    n = int(input())
    ans = False
    for a in range(0, 1001):
        for b in range(0, 1001):
            left = n - 1234567 * a - 123456 * b
            if left >= 0 and left % 1234 == 0:
                ans = True
    print("YES" if ans else "NO")

main()