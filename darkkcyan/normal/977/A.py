from __future__ import print_function, division
from sys import stdin

dec = lambda a: a - 1 if a % 10 != 0 else a // 10
a, k = map(int, stdin.readline().split())
for _ in range(k):
    a = dec(a)
print(a)