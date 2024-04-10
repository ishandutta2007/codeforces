import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    l.sort()
    out = 1
    for i in range(n):
        if l[i] <= (i + 1):
            out = i + 2
    print(out)