def find_SCC(graph):
    SCC, S, P = [], [], []
    depth = [0] * len(graph)
 
    stack = list(range(len(graph)))
    while stack:
        node = stack.pop()
        if node < 0:
            d = depth[~node] - 1
            if P[-1] > d:
                SCC.append(S[d:])
                del S[d:], P[-1]
                for node in SCC[-1]:
                    depth[node] = -1
        elif depth[node] > 0:
            while P[-1] > depth[node]:
                P.pop()
        elif depth[node] == 0:
            S.append(node)
            P.append(len(S))
            depth[node] = len(S)
            stack.append(~node)
            stack += graph[node]
    return SCC[::-1]

import sys
input = sys.stdin.readline

n,m = map(int, input().split())
adj = [[] for _ in range(n)]
a2 = [[] for _ in range(n)]

edges = []
for _ in range(m):
    a,b,l = map(int, input().split());a-=1;b-=1
    edges.append((a,b,l))
    adj[a].append(b)
    a2[a].append((b,l))

SCCs = find_SCC(adj)
SCC_ind = [-1] * n
for i in range(len(SCCs)):
    for v in SCCs[i]:
        SCC_ind[v] = i

from math import gcd

dist = [-1] * n
SCC_gcd = []
for l in SCCs:
    root = l[0]
    ind = SCC_ind[root]
    dist[root] = 0
    g = 0
    stack = [root]
    while stack:
        u = stack.pop()
        for v, l in a2[u]:
            if SCC_ind[v] == ind:
                if dist[v] == -1:
                    stack.append(v)
                    dist[v] = dist[u] + l
                else:
                    d1 = dist[u] + l
                    diff = (dist[v] - d1)
                    g = gcd(g, diff)
    SCC_gcd.append(g)

q = int(input())
out = []
for _ in range(q):
    v,s,t = map(int, input().split());v-=1
    g = gcd(SCC_gcd[SCC_ind[v]], t)
    if s % g == 0:
        out.append('YES')
    else:
        out.append('NO')
print('\n'.join(out))