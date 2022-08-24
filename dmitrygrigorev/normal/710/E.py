def recursion(n):
    if n == 1:
        return x
    if n == 2:
        return x + min(x , y)
    if n % 2 == 0:
        return recursion(n // 2) + min(y, x * (n - n//2))
    else:
        return min(recursion(n + 1), recursion(n - 1)) + x


import sys
sys.setrecursionlimit(10000000)
n, x, y = list(map(int, input().split()))
print(recursion(n))