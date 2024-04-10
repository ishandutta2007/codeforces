from __future__ import print_function, division
from sys import stdin

u, v = map(int, stdin.readline().split())

cnt = len([1 for i in range(1, 7) if i >= max(u, v)])
gcd = lambda u, v: u if v == 0 else gcd(v, u % v)
g = gcd(cnt, 6)
n = cnt // g
d = 6 // g
print("%d/%d" % (n, d))