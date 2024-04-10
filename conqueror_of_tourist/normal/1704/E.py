import sys
input = sys.stdin.readline

MOD = 998244353 

out = []
t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    a =  list(map(int, input().split()))

    adj = [[] for _ in range(n)]
    #rev = [[] for _ in range(n)]
    ind = [0] * n
    od = [0] * n
    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1; v -= 1
        adj[u].append(v)
        #rev[v].append(u)
        ind[v] += 1
        od[u] += 1

    for snk in range(n):
        if od[snk] == 0:
            break

    sim = 0
    for ti in range(n):
        if sum(a) == 0:
            break
        sim += 1
        nex = [0] * n
        for i in range(n):
            for v in adj[i]:
                nex[v] += a[i]
                if nex[v] > MOD:
                    nex[v] %= MOD
                    nex[v] += MOD

        nex[snk] += max(0, a[snk] - 1)
        a = nex
        if sum(a) == 0:
            break
        
    out.append((sim + a[snk]) % MOD)
        

'''
    first = [0] * n

    st = []
    for i in range(n):
        if ind[i] == 0:
            st.append(i)
        if a[i] == 0:
            first[i] = n + 1000

    while st:
        nex = st.pop()
        for v in adj[nex]:
            ind[v] -= 1
            if ind[v] == 0:
                st.append(v)
            a[v] += a[nex]
            a[v] %= MOD
            first[v] = min(first[v], first[nex] + 1)
    

    for i in range(n):
        if len(adj[i]) == 0:
            out.append(a[i] + first[i])'''
    

print('\n'.join(map(str, out)))