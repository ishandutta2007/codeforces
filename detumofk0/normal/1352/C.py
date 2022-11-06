import math

t = int(input())

while t > 0:
    t = t - 1
    n, k = map(int, input().split())
    k = k - 1
    block = k // (n - 1)
    m = n * (block)
    print(m + k % (n - 1) + 1)