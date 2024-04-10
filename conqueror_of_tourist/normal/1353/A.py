import sys
input = sys.stdin.readline
rInt = lambda: int(input())
mInt = lambda: map(int, input().split())
rLis = lambda: list(map(int, input().split()))

t = int(input())

for _ in range(t):
    n, m = mInt()
    if n == 1:
        print(0)
    elif n == 2:
        print(m)
    else:
        print(2 * m)