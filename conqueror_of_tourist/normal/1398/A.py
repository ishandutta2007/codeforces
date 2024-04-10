import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    if l[0] + l[1] <= l[n - 1]:
        print(1,2,n)
    else:
        print(-1)