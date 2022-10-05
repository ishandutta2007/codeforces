import sys
input = sys.stdin.readline
rInt = lambda: int(input())
mInt = lambda: map(int, input().split())
rLis = lambda: list(map(int, input().split()))

t = rInt()
for _ in range(t):
    n = rInt()
    center = n//2
    out = 0
    for i in range(1, n // 2 + 1):
        out += i * i * 8
    print(out)