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

theset = [2, 3, 5, 7]
def brute(cur, i, n):
    res = 0
    if i < len(theset):
        res += brute(cur, i + 1, n)
        cur.append(theset[i])
        res += brute(cur, i + 1, n)
        cur.pop()
    else:
        k = 1
        for elem in cur:
            k *= elem
        res += (+1 if len(cur) % 2 == 0 else -1) * (n // k)
    return res

n = int(input())
print(brute([], 0, n))