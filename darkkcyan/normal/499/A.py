from __future__ import print_function, division
import sys

n, x = map(int, raw_input().split())
cur = 1
ans = 0
for i in xrange(n):
    l, r = map(int, raw_input().split())
    ans += (l - cur) % x + (r - l + 1)
    cur = r + 1
print(ans)