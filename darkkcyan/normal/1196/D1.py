from sys import stdin
import math

rgb = 'RGB'

for query in range(int(stdin.readline())):
    n, k = map(int, stdin.readline().split())
    s = stdin.readline()

    ans = math.inf
    for start in range(3):
        dp = [0 for i in range(n + 1)] 
        for i in range(n):
            cur = rgb[(start + i) % len(rgb)]
            dp[i + 1] = dp[i] + int(s[i] != cur)
        for i in range(n - k + 1):
            ans = min(ans, dp[i + k] - dp[i])
    print(ans)