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
    mod = 10 ** 9 + 7
    pws = [None for i in range(4 * (10 ** 5))]
    pws[0] = 1
    for i in range(1, (4 * (10 ** 5))):
        pws[i] = 2 * pws[i - 1] % mod
    
    n = int(input())
    seq = list(map(int, input().split()))

    seq.sort()
    
    ans = 0
    for i in range(n):
        ans += seq[i] * (pws[i] - 1)
        ans -= seq[i] * (pws[n - i - 1] - 1)
        ans = ans % mod
    print(ans)

main()