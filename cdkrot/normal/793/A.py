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
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    m = min(a)
    ans = 0
    for elem in a:
        if (elem - m) % k != 0:
            print("-1\n")
            sys.exit(0)
        else:
            ans += (elem - m) // k
    print(ans)
main()