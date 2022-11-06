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

def solve(a, l):
    if l == 0:
        return 0

    if l == 1:
        return a[0]
    
    k = 0
    while (2 ** k) < l:
        k += 1
    
    return min(a[k], a[k - 1] + solve(a, l - (2 ** (k - 1))))
    

def main():
    n, l = map(int, input().split())
    a = list(map(int, input().split()))

    for i in range(n - 2, -1, -1):
        if a[i] > a[i + 1]:
            a[i] = a[i + 1]
    
    for i in range(1, n):
        if a[i] > 2 * a[i - 1]:
            a[i] = 2 * a[i - 1]

    while len(a) < 35:
        a.append(2 * a[len(a) - 1])

    #print(a)

    print(solve(a, l))
            
main()