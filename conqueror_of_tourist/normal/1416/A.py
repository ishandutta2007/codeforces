import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))

    last = [-1] * (n + 1)
    best = [1] * (n + 1)
    for i in range(n):
        v = l[i]
        diff = i - last[v]
        best[v] = max(best[v], diff)
        last[v] = i
    for v in range(n + 1):
        diff = n - last[v]
        best[v] = max(best[v], diff)
    rev = [n+1] * (n + 2)
    for i in range(n,-1,-1):
        rev[best[i]] = i
    soFar = n + 1
    out = []
    for i in range(1, n + 1):
        soFar = min(soFar, rev[i])
        if soFar > n:
            out.append(-1)
        else:
            out.append(soFar)
    print(' '.join(map(str,out)))