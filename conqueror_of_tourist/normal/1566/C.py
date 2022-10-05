import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    a = input()
    b = input()

    dp = [0]

    h0 = [a[i] == '0' or b[i] == '0' for i in range(n)]
    h1 = [a[i] == '1' or b[i] == '1' for i in range(n)]

    for i in range(n):
        poss = [dp[i]]

        if h0[i]:
            poss.append(1 + dp[i])
            if h1[i]:
                poss.append(2 + dp[i])

        if i:
            if h0[i] or h0[i - 1]:
                poss.append(1 + dp[i - 1])
                if h1[i] or h1[i - 1]:
                    poss.append(2 + dp[i - 1])
        dp.append(max(poss))
    print(dp[-1])