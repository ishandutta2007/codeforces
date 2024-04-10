import sys
from math import gcd
input = sys.stdin.readline
out = []
for _ in range(int(input())):
    n, k = map(int, input().split())
    l = list(map(int, input().split()))
    kk = k - l[0]
    g = 0
    for v in l:
        g = gcd(g, v - l[0])
    if kk == 0 and g == 0 or g != 0 and kk % g == 0:
        out.append('YES')
    else:
        out.append('NO')
print('\n'.join(out))