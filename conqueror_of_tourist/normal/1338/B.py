import sys
input = sys.stdin.readline

n = int(input())

neigh = [[] for i in range(n)]
l = []
for i in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    neigh[a].append(b)
    neigh[b].append(a)
    l.append((a,b))

#Max
edges = set()
for a, b in l:
    if len(neigh[a]) == 1:
        a = -1
    if len(neigh[b]) == 1:
        b = -1
    if a > b:
        a, b = b, a
    edges.add((a,b))

MAX = len(edges)

#Min
leafDepth = []
visited = [False] * n
from collections import deque
q = deque()
q.append((0,0))
while q:
    nex, d = q.popleft()
    if not visited[nex]:
        visited[nex] = True

        if len(neigh[nex]) == 1:
            leafDepth.append(d)
        for v in neigh[nex]:
            q.append((v,d+1))

MIN = 1
corr = leafDepth.pop() % 2
for d in leafDepth:
    if d % 2 != corr:
        MIN = 3 
        


#Out
print(MIN, MAX)