import sys
input = sys.stdin.readline

from math import gcd

t = int(input())
outL = []
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    poss = [1]
    curr = []
    for i in range(n - 1):
        d = abs(a[i+1] - a[i])
        nc = []

        for v, c in curr:
            g = gcd(d, v)
            if g > 1:
                nc.append((g, c + 1))
                poss.append(c+1)
                d //= g
        if d > 1:
            nc.append((d, 2))
            poss.append(2)
        curr = nc
    outL.append(max(poss))
        

print('\n'.join(map(str,outL)))