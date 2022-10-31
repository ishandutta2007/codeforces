ri = lambda: map(int, raw_input().split())

dp = [[0] * 5 for i in xrange(1010)]

for i in xrange(1010):
    for j in xrange(5):
        if j > i or j == 1:
            continue
        if j == 0:
            dp[i][j] = 1
            continue
        dp[i][j] = dp[i-1][j]
        dp[i][j] += dp[i-1][j-1] * (j - 1)
        dp[i][j] += dp[i-1][j-2] * ((i - 1) - (j - 2))

a, b = ri()
print sum(dp[a][:b+1])