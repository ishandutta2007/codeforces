for testcase in range(int(input())):
    n, x = map(int, input().split())
    a = list(sorted(int(i) for i in input().split()))
    dp = [0] * (n + 2)
    for i in range(1, n + 1):
        dp[i] = max(dp[i], dp[i - 1])
        required = (x + a[i - 1] - 1) // a[i - 1]
        # print(i, required, i + required) 
        if i + required <= n + 1:
            dp[i + required] = max(dp[i + required], dp[i] + 1)
    dp[n + 1] = max(dp[n], dp[n + 1])
    print(dp[n + 1])