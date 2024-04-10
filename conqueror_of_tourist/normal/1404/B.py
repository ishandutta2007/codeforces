import sys
input = sys.stdin.readline
from collections import deque

t = int(input())
for _ in range(t):
    n,a,b,da,db = map(int, input().split())
    a -= 1
    b -= 1
    adj = [[] for i in range(n)]
    for _ in range(n-1):
        u,v = map(int, input().split())
        adj[u-1].append(v-1)
        adj[v-1].append(u-1)
    
    if db <= 2 * da:
        print('Alice')
    else:
        works = True
        
        dist = [-1] * n
        q = deque()
        q.append(a)
        dist[a] = 0
        while q:
            v = q.popleft()
            for u in adj[v]:
                if dist[u] == -1:
                    dist[u] = dist[v] + 1
                    q.append(u)
        if dist[b] <= da:
            works = False
                    
        last = v
        
        dist = [-1] * n
        q = deque()
        q.append(last)
        dist[last] = 0
        while q:
            v = q.popleft()
            for u in adj[v]:
                if dist[u] == -1:
                    dist[u] = dist[v] + 1
                    q.append(u)
        lorg = max(dist)
        if lorg >= 2 * da + 1 and works:
            print('Bob')
        else:
            print('Alice')