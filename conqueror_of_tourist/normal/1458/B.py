n = int(input())

inf = 10**8

dp = []
for k in range(n + 1):
    dp.append([-inf] * 10005)

dp[0][0] = 0
w = 0
for _ in range(k):
    a, b = map(int, input().split())

    w += b

    for k in range(n-1,-1,-1):
        for i in range(10005 - a):
            dp[k+1][i+a] = max(dp[k+1][i+a], dp[k][i] + b)

out = []
for line in dp[1:]:
    poss = []
    for i in range(10005):
        cap = i
        con = line[i]
        poss.append(min(cap, (con + w)/2))
    out.append(max(poss))
print(' '.join(map(str,out)))