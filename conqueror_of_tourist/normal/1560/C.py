from math import isqrt
t = int(input())
for _ in range(t):
    n = int(input())
    x = isqrt(n - 1)
    v = n - x * x
    if v <= x:
        print(v, x + 1)
    else:
        print(x + 1, 2 + x + x - v)