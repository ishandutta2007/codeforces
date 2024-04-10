inf = -1

def _min(a, b):
    return a if b == inf or inf != a < b else b

class DistanceKeeper:
    def __init__(self, n):
        self.m = 1
        while self.m < n: self.m *= 2
        self.data = 2 * self.m * [inf]
        self.dist = n * [inf]
        self.__getitem__ = self.dist.__getitem__

    def __setitem__(self, ind, x):
        self.dist[ind] = x
        ind += self.m
        self.data[ind] = x
        ind >>= 1
        while ind:
            self.data[ind] = _min(self.data[2 * ind], self.data[2 * ind + 1])
            ind >>= 1


    def __getitem__(self, ind):
        return self.dist[ind]

    def trav(self):
        while self.data[1] != inf:
            x = self.data[1]

            ind = 1
            while ind < self.m:
                ind = 2 * ind + (self.data[2 * ind] != x)
            ind -= self.m

            self[ind] = inf
            self.dist[ind] = x
            yield ind

def dijkstra(graph, start):
    n = len(graph)

    P = [-1] * n
    D = DistanceKeeper(n)
    D[start] = 0

    for node in D.trav():
        for nei, weight in graph[node]:
            new_dist = D[node] + weight
            if D[nei] == inf or new_dist < D[nei]:
                D[nei] = new_dist
                P[nei] = node

    return D.dist, P


import sys
input = sys.stdin.readline

n, m = map(int, input().split())
sz = n * m
p, q = map(int, input().split())
b = [input().strip() for _ in range(n)]

adj = [[] for _ in range(sz + 2)]
so = sz
si = sz + 1

dX = [-1, 1, 0, 0]
dY = [0, 0, -1, 1,]

for i in range(n):
    for j in range(m):
        c = b[i][j]
        if c == '.':
            '''
            if (i + j) % 2:
                adj[so].append((m * i + j, 0))
            else:
                adj[m * i + j].append((si, 0))'''
            adj[so].append((m * i + j, 0))
        elif c == 'R':
            assert j > 0
            dest = m * i + (j - 1)
            
            #From Up
            if i > 0:
                adj[m * (i - 1) + j].append((dest, p))
            #From Down
            if i < n - 1:
                adj[m * (i + 1) + j].append((dest, p))
            #From Right
            if j < m - 1:
                adj[m * i + (j + 1)].append((dest, q))
        elif c == 'L':
            assert j < m - 1
            dest = m * i + (j + 1)
            
            #From Up
            if i > 0:
                adj[m * (i - 1) + j].append((dest, p))
            #From Down
            if i < n - 1:
                adj[m * (i + 1) + j].append((dest, p))
            #From Left
            if j > 0:
                adj[m * i + (j - 1)].append((dest, q))
        elif c == 'U':
            assert i < n - 1
            dest = m * (i + 1) + j

            #From Right
            if j < m - 1:
                adj[m * i + (j + 1)].append((dest, p))
            #From Left
            if j > 0:
                adj[m * i + (j - 1)].append((dest, p))
            #From Up
            if i > 0:
                adj[m * (i - 1) + j].append((dest, q))
        elif c == 'D':
            assert i > 0
            dest = m * (i - 1) + j

            #From Right
            if j < m - 1:
                adj[m * i + (j + 1)].append((dest, p))
            #From Left
            if j > 0:
                adj[m * i + (j - 1)].append((dest, p))
            #From Down
            if i < n - 1:
                adj[m * (i + 1) + j].append((dest, q))
        else:
            assert c == '#'

dist, _ = dijkstra(adj, so)
poss = []


for i in range(n):
    for j in range(m):
        if (i + j) % 2:
            continue
        if b[i][j] == '#':
            continue

        d1 = dist[m * i + j]
        if d1 == -1:
            continue

        for d in range(4):
            ii = i + dX[d]
            jj = j + dY[d]

            if 0 <= ii < n and 0 <= jj < m:
                if b[ii][jj] == '#':
                    continue
                d2 = dist[m * ii + jj]
                if d2 == -1:
                    continue
                
                poss.append(d1 + d2)

if poss:
    print(min(poss))
else:
    print(-1)