import sys
input = sys.stdin.readline

from math import gcd

t = int(input())
out = []
for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    g = b[0]
    for v in b:
        g = gcd(v, g)

    ct = [0] * g
    mn = [10 ** 9 + 1] * g
    tt = 0
    for i in range(n):
        v = a[i]
        ind = i % g

        ct[ind] += 1 if v < 0 else 0
        mn[ind] = min(mn[ind], abs(v))
        tt += abs(v)
        
    tt -= sum(mn)
    s = 0
    for i in range(g):
        if ct[i] % 2:
            s -= mn[i]
        else:
            s += mn[i]
    out.append(tt + abs(s))
print('\n'.join(map(str,out)))