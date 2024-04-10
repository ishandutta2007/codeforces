import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())

    out = 0
    l = list(map(int, input().split()))
    for i in range(n - 1):
        out += max(0, l[i] - l[i + 1])
    print(out)