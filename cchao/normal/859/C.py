n, a = input(), map(int, raw_input().split())

dp = [[0, 0] for i in xrange(n + 1)]

for i in xrange(n - 1, -1, -1):
    dp[i][0] = max(a[i] - dp[i + 1][1], dp[i + 1][0] - a[i])
    dp[i][1] = max(a[i] - dp[i + 1][0], dp[i + 1][1] - a[i])

s = sum(a)
y = (dp[i][0] + s) / 2
x = s - y

print x, y