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
1
def main():
    n, a = map(int, input().split())
    a -= 1
    
    arr = list(map(int, input().split()))
    ans = 0
    for d in range(1, 150):
        b1 = (a + d) < len(arr)
        c1 = b1 and arr[a + d] == 1
        b2 = (a - d) >= 0
        c2 = b2 and arr[a - d] == 1

        if b1 and b2:
            ans += 2 * int(c1 and c2)
        else:
            ans += int(c1) + int(c2)
            
    ans += arr[a]
    print(ans)
main()