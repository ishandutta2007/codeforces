t = int(input())
for _ in range(t):
    s = input().strip()

    dp = [0,0]
    for c in s:
        if c == '0':
            dp = [2 * min(dp), dp[0]]
        elif c == '1':
            dp = [2 if min(dp) >= 2 else 1, dp[0]]
    if min(dp) < 2:
        print('YES')
    else:
        print('NO')