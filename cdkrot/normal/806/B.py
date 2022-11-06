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

def get_price(a, b):
    # a / b
    if 2 * a > b:
        return 500
    if 4 * a > b:
        return 1000
    if 8 * a > b:
        return 1500
    if 16 * a > b:
        return 2000
    if 32 * a > b:
        return 2500
    return 3000

def main():
    n = int(input())
    we = list(map(int, input().split()))
    fr = list(map(int, input().split()))

    ratio = [0, 0, 0, 0, 0]
    for i in range(5):
        if we[i] != -1:
            ratio[i] += 1
        else:
            we[i] = 250
        
        if fr[i] != -1:
            ratio[i] += 1
        else:
            fr[i] = 250

    for part in range(n - 2):
        lst = list(map(int, input().split()))
        for i in range(5):
            if lst[i] != -1:
                ratio[i] += 1

                
    for mi in range(0, 4500):
        s1 = 0
        s2 = 0

        for i in range(5):
            if we[i] < fr[i]:
               pr = get_price(ratio[i] + 0, n + mi)
               
               s1 += pr - pr * we[i] // 250
               s2 += pr - pr * fr[i] // 250
            elif we[i] > fr[i] and we[i] != 250: # submit as much OK as we can
                pr = get_price(ratio[i] + mi, n + mi)

                s1 += pr - pr * we[i] // 250
                s2 += pr - pr * fr[i] // 250
            elif we[i] > fr[i] and we[i] == 250:
                pr = get_price(ratio[i] + 0, n + mi)

                s1 += pr - pr * we[i] // 250
                s2 += pr - pr * fr[i] // 250
                
        if s1 > s2:
            print(mi)
            return

    lo = 4450
    hi = 10 ** 9 + 8 # OK

    while hi - lo > 1:
        mi = lo + (hi - lo) // 2
        
        s1 = 0
        s2 = 0

        for i in range(5):
            if we[i] < fr[i]:
               pr = get_price(ratio[i] + 0, n + mi)
               
               s1 += pr - pr * we[i] // 250
               s2 += pr - pr * fr[i] // 250
            elif we[i] > fr[i] and we[i] != 250: # submit as much OK as we can
                pr = get_price(ratio[i] + mi, n + mi)

                s1 += pr - pr * we[i] // 250
                s2 += pr - pr * fr[i] // 250
            elif we[i] > fr[i] and we[i] == 250:
                pr = get_price(ratio[i] + 0, n + mi)

                s1 += pr - pr * we[i] // 250
                s2 += pr - pr * fr[i] // 250
                
        if s1 > s2:
            hi = mi
        else:
            lo = mi
    
    print(-1 if hi == 10 ** 9 + 8 else hi)
main()