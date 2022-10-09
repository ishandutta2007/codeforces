n, m = map(int, input().split())
gr = [[] for i in range(n + 1)]
for _ in range(m):
    u, v = map(int, input().split())
    gr[u].append(v)
    gr[v].append(u)

vis = [False] * (n + 1)
def dfs(x):
    vis[x] = True
    ans = [1, len(gr[x]) != 2]
    for u in gr[x]:
        if vis[u]:
            continue
        a, b = dfs(u)
        ans[0] += a
        if b:
            ans[1] = True
    return ans

t = []
for i in range(1, n + 1):
    if vis[i]:
        continue
    a, b = dfs(i)
    if not b and a % 2 == 1:
        a -= 1
    t.append([a // 2, a - a// 2])

dp = [[False] * n for i in range(n)]
dp[0][0] = True
for i in t:
    for f in range(n - 1, -1, -1):
        for g in range(n - 1, -1, -1):
            if not dp[f][g]:
                continue
            if g + i[1] <= n and f + i[0] < n:
                dp[f + i[0]][g + i[1]] = True
            if g + i[0] <= n and f + i[1] < n:
                dp[f + i[1]][g + i[0]] = True

ans = n
for i in range(n):
    for f in range(n):
        if dp[i][f]:
            ans = min(ans, n - 2 * min(i, f))

print(ans )