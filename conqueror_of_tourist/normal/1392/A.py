import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    if min(l) == max(l):
        print(n)
    else:
        print(1)