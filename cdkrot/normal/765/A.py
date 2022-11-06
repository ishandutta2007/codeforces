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
    n = int(input())
    home = input().strip()

    cnt_fr, cnt_to = 0, 0
    for i in range(n):
        fr, to = input().strip().split('->')
        if fr == home:
            cnt_fr += 1
        if to == home:
            cnt_to += 1

    if cnt_fr == cnt_to + 1:
        print("contest")
    elif cnt_fr == cnt_to:
        print("home")
    else:
        sys.exit(1)
main()