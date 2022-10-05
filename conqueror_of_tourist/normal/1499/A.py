import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n,k1,k2 = map(int, input().split())
    w,b = map(int, input().split())
    if k1 + k2 >= 2 * w and (n - k1 - k2 + n) >= 2 * b:
        print('YES')
    else:
        print('NO')