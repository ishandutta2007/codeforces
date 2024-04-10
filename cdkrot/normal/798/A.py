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
    s = input().strip()

    l = 0
    r = len(s) - 1
    num = 0
    while l < r:
        if s[l] != s[r]:
            num += 1
        l += 1
        r -= 1

    if num == 1 or (num == 0 and len(s) % 2 == 1):
        print("YES")
    else:
        print("NO")

main()