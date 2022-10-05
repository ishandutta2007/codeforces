import sys
input = sys.stdin.readline

from math import gcd

t = int(input())
out = []
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    x = int(input())

    a = [v - x for v in a]

    o = 0
    last = -1

    for i in range(n):
        if i == last + 1:
            o += 1
        elif i == last + 2:
            if a[i] + a[i-1] < 0:
                last = i
            else:
                o += 1
        else:
            if a[i] + a[i-1] < 0 or a[i] + a[i-1] + a[i-2] < 0:
                last = i
            else:
                o += 1
    out.append(o)
print('\n'.join(map(str,out)))