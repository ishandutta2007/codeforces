import sys
input = sys.stdin.readline
rInt = lambda: int(input())
mInt = lambda: map(int, input().split())
rLis = lambda: list(map(int, input().split()))

outs = []

t = rInt()
for _ in range(t):
    n, k = mInt()
    s = input()

    pref = [0]
    for c in s:
        if c == '1':
            pref.append(pref[-1] + 1)
        else:
            pref.append(pref[-1])

    best = pref[-1]

    dp = []
    for i in range(n):
        cost = pref[i]
        if i >= k:
            case2 = dp[i - k] + pref[i] - pref[i - k + 1]
            if case2 < cost:
                cost = case2
        if s[i] == '0':
            cost += 1

        dp.append(cost)
        actual = cost + pref[-1] - pref[i + 1]
        if actual < best:
            best = actual

    outs.append(best)


print(*outs, sep = '\n')