from math import gcd
import sys,io,os;input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

g = 0
for i in range(n - 1):
    g = gcd(g, a[i] - a[i+1])

out = []
for v in b:
    out.append(gcd(v + a[0] ,g))
print(' '.join(map(str,out)))