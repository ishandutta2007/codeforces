import sys
from collections import deque
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, m, a, b, c = map(int,input().split())
    p = list(map(int, input().split()))
    p.sort()
    
    pref = [0]
    curr = 0
    for i in range(m):
        curr += p[i]
        pref.append(curr)

    adj = [[] for i in range(n)]
    for _ in range(m):
        u, v = map(int,input().split())
        adj[u - 1].append(v - 1)
        adj[v - 1].append(u - 1)

        
    aD = [-1] * n
    bD = [-1] * n
    cD = [-1] * n

    for i in range(3):
        q = deque()
        q.append(([a,b,c][i]-1,0))
        l = [aD,bD,cD][i]
        l[q[0][0]] = 0
        while q:
            v, d = q.popleft()
            for nex in adj[v]:
                if l[nex] == -1:
                    l[nex] = d + 1
                    q.append((nex,d+1))
    poss = []
    for i in range(n):
        if aD[i] + bD[i] + cD[i] <= m:
            poss.append(pref[aD[i] + bD[i] + cD[i]] + pref[bD[i]])
    print(min(poss))