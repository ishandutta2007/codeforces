from __future__ import print_function, division
from sys import stdin

r, d = map(int, stdin.readline().split())
n = int(stdin.readline())
ans = 0
for i in range(n):
    x, y, dr = map(int, stdin.readline().split())
    if x ** 2 + y**2 < (r - d + dr) ** 2:
        continue
    if x ** 2 + y ** 2 > (r - dr) ** 2:
        continue
    ans += 1

print(ans)