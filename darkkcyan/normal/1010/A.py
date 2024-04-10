from __future__ import print_function, division
import sys

n = int(raw_input())
m = int(raw_input())
a = list(map(int, raw_input().split()))
b = list(map(int, raw_input().split()))

def ok(f):
    f += m
    for i in xrange(n):
        g = (i + 1) % n
        t = f / a[i]
        f -= t
        if f < m:
            return False
        t = f / b[g]
        f -= t
        if f < m:
            return False
    return True

l, r = 0, 10**10
for i in xrange(100):
    mid = (l + r) / 2
    if ok(mid):
        r = mid
    else:
        l = mid
if not ok(r):
    print(-1)
else:
    print("{:.08f}".format(l))