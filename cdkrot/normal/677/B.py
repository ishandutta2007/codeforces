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
    n, h, k = map(int, input().split())
    dat = list(map(int, input().split()))

    ptr = 0
    t = 0
    cur = 0
    while ptr != len(dat):
        if cur + dat[ptr] > h:
            mindecr = cur + dat[ptr] - h
            dt = (mindecr + k - 1) // k
            t += dt
            
            cur = max(0, cur - dt * k)
            continue
        
        while ptr != len(dat) and cur + dat[ptr] <= h:
            cur += dat[ptr]
            ptr += 1
        cur = max(0, cur - k)
        t += 1
    t += (cur + k - 1) // k
    print(t)
main()