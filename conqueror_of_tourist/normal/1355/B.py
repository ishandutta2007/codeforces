import sys
input = sys.stdin.readline

out = []

T = int(input())
for _ in range(T):
    N = int(input())
    l = list(map(int, input().split()))
    l.sort(reverse = True)

    dp = [0] * (N + 1)

    for i in range(N):
        dp[i + 1] = max(dp[i + 1], dp[i])
        if i + l[i] <= N:
            dp[i + l[i]] = max(dp[i + l[i]], dp[i] + 1)
    
    out.append(dp[N])

print(*out, sep = '\n')