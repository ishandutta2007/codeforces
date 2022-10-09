from __future__ import print_function, division
import sys

n, k = map(int, raw_input().split())
a = list(map(int, raw_input().split()))

r = 0
ans = -1
for l in xrange(n):
    while r + 1 < n and a[r + 1] - a[l] <= k:
        r += 1
    if r - l + 1 < 3:
        continue
    ans = max(ans, (a[r] - a[l + 1]) / (a[r] - a[l]))

if ans < 0:
    print(-1)
else:
    print("{:.09f}".format(ans))