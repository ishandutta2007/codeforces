def main():
    n = int(input())
    gr = list([] for i in range(n + 1))
    for i in range(n - 1):
        u, v = map(int, input().split())
        gr[u].append(v)
        gr[v].append(u)
        
    topo = [1]
    par = [1] * (n + 1)
    it = 0
    while it < len(topo):
        u = topo[it]
        for v in gr[u]:
            if v == par[u]:
                continue
            par[v] = u
            topo.append(v)
        it += 1
    # print(topo) 
    
    subsize = [1] * (n + 1)
    dp = list([0, 1] for i in range(n + 1))
    
    def combine(u, v):
        ans = [0] * (len(u) + len(v) - 1)
        for i in range(len(u)):
            for f in range(len(v)):
                ans[i + f] = max(ans[i + f], u[i] * v[f])
        return ans
    
    for u in reversed(topo):
        for sz in range(len(dp[u])):
            dp[u][0] = max(dp[u][0], dp[u][sz] * sz)
        if par[u] != u:
            dp[par[u]] = combine(dp[par[u]], dp[u])
    print(dp[1][0])
    
main()