import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input()) + 2
    l = [0] + list(map(int, input().split()))+ [0]
    out = l[0] + l[-1]
    for i in range(n - 1):
        out += abs(l[i] - l[i+1])
    for i in range(1, n - 1):
        sub = l[i] - max(l[i-1], l[i+1])
        if sub > 0:
            out -= sub
    print(out)