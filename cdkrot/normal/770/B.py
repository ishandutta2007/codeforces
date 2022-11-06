#!/usr/bin/python3
# Copyright (C) Sayutin Dmitry, 2k17

def sslow(x):
    ans = -1, -1
    for i in range(1, x + 1):
        this = sum([int(ch) for ch in str(i)])
        ans = max(ans, (this, i))
    return ans[1]

def sfast(x):
    ans = -1, -1
    for i in range(x, x + 1):
        this = sum([int(ch) for ch in str(i)])
        ans = max(ans, (this, i))
    sx = str(x)
    csum = 0
    for com in range(0, len(sx) - 1):
        csum += int(sx[com])
        if sx[com] != '0':
            ch = str(int(sx[com]) - 1)
            ans = max(ans, (csum - 1 + 9 * (len(sx) - 1 - com), int(sx[:com] + ch + '9' * (len(sx) - 1 - com))))
    return ans[1]

print(sfast(int(input())))
import sys
sys.exit(0)
    
for x in range(1, 1000):
    if sslow(x) != sfast(x):
        print(x, sslow(x), sfast(x))
        break