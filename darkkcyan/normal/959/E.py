from __future__ import print_function, division
import sys
n = int(raw_input())

ans = 0
p2 = 1
while p2 < n:
    num = (n + p2 - 1) // p2
    num //= 2
    ans += p2 * num
    p2 *= 2

print(ans)