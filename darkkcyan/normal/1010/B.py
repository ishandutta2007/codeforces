from __future__ import print_function, division
import sys

m, n = map(int, raw_input().split())

p = []
def ask(x):
    print(x)
    sys.stdout.flush()
    ans = int(raw_input())
    assert(ans != -2)
    if ans == 0:
        sys.exit(0)
    return ans

for i in xrange(n):
    t = ask(m)
    p.append(t == 1)

l, r = 1, m
step = 0
while l < r:
    mid = (l + r) // 2
    t = ask(mid)
    if not p[step]:
        t = -t
    if t == -1:
        l = mid + 1
    else:
        r = mid - 1
    step = (step + 1) % n

if r == l:
    ask(l)