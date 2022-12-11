import math
import sys

n, k = map(int, raw_input().split())

def check(div):
    return div * k * (k + 1) // 2 <= n and n % div == 0

if k * (k + 1) // 2 > n:
    print('-1')
else:
    ans = -1
    for i in range(1, int(math.sqrt(n)) + 4):
        if n % i == 0:
            if check(i): ans = max(ans, i)
            if check(n // i): ans = max(ans, n // i)
    for i in range(k - 1):
        sys.stdout.write(str((i + 1) * ans))
        sys.stdout.write(' ')
        n -= (i + 1) * ans
    print(n)