import sys
input = sys.stdin.readline

out = []

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    base = sum(v * v for v in a) + sum(v * v for v in b)
    base *= n - 2

    s = sum(a) + sum(b)

    dp = [False] * (10010)
    dp[0] = True

    for i in range(n):
        ndp = [False] * (10010)
        aa, bb = a[i], b[i]
        for i in range(10010 - aa):
            ndp[i+aa] |= dp[i]
        for i in range(10010 - bb):
            ndp[i+bb] |= dp[i]
        dp = ndp

    poss = []
    for i in range(10010):
        if dp[i]:
            poss.append(i * i + (s - i) * (s - i))

    out.append(base + min(poss))
    

print('\n'.join(map(str,out)))