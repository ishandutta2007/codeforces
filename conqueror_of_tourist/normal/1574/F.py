import sys
input = sys.stdin.readline

n,m,k = map(int, input().split())
nex = [-1] * k
prev = [-1] * k
bad = [0] * k

for _ in range(n):
    l = list(map(int, input().split()))
    nn = l.pop(0)
    tg = True
    for i in range(nn - 1):
        u, v = l[i] - 1, l[i+1] - 1
        tg = tg and (prev[v] == -1 or prev[v] == u)
        prev[v] = u
        tg = tg and (nex[u] == -1 or nex[u] == v)
        nex[u] = v
    if not tg:
        for v in l:
            bad[v - 1] = 1

MOD = 998244353
b = 500
ct = [0] * b
ot = []
dp = [1]

for i in range(k):
    ib = False
    curr = i
    val = 0
    if prev[i] == -1:
        while curr != -1:
            ib = ib or bad[curr]
            if ib:
                break
            curr = nex[curr]
            val += 1
        if not ib:
            if val < b:
                ct[val] += 1
            else:
                    ot.append(val)
            
for i in range(1, m + 1):
    curr = 0
    for j in range(1, b):
        if j <= i:
            curr += (ct[j] * dp[i - j])
            curr %= MOD
    for j in ot:
        if j <= i:
            curr += dp[i - j]
    curr %= MOD
    dp.append(curr)
    
print(dp[m])