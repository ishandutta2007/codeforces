import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    poss = []
    for i in range(n - 1):
        poss.append((a[i] - a[i + 1], i + 2))

    poss.sort()

    out = [1]
    for _, v in poss:
        out.append(v)

    print(' '.join(map(str, out)))