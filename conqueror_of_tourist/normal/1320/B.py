import sys
input = sys.stdin.readline

n, m = map(int, input().split())

edges = [[] for i in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    edges[b-1].append(a-1)

k = int(input())
p = list(map(lambda x: int(x) - 1, input().split()))
pset = set(p)
prev = dict()
for i in range(k - 1):
    prev[p[i + 1]] = p[i]
prev[p[0]] = -1
s = p[0]
t = p[-1]

from collections import deque

d = deque()
d.append((t, 0))

LARGE = n + 100

firstP = [LARGE] * n
firstNP = [LARGE] * n

seen = set()
seen.add(t)

while d:
    nex, time = d.popleft()
    for adj in edges[nex]:
        if adj not in seen:
            seen.add(adj)
            d.append((adj, time + 1))

        if nex in pset and prev[nex] == adj:
            if firstP[adj] == LARGE:
                firstP[adj] = time
        else:
            if firstNP[adj] == LARGE:
                firstNP[adj] = time

smol = 0
tol = 0

for i in range(k - 1):
    #print(i)
    #print(firstP[p[i]], firstNP[p[i]])
    if firstP[p[i]] > firstNP[p[i]]:
        smol += 1
    if firstP[p[i]] >= firstNP[p[i]]:
        tol += 1
        
print(smol, tol)