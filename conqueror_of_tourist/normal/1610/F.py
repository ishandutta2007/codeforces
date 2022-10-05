import sys
input = sys.stdin.readline

n, m = map(int, input().split())
adj1 = [[] for _ in range(n)]
adj2 = [[] for _ in range(n)]

edges = []

outv = 0
outvv = 0

deg1 = [0] * n
deg2 = [0] * n
parO = []
parP = []
for e in range(m):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1

    parO.append(u)
    parP.append(v)
    
    if w == 1:
        adj1[u].append((v,e))
        adj1[v].append((u,e))
        deg1[u] += 1
        deg1[v] += 1
    else:
        adj2[u].append((v,e))
        adj2[v].append((u,e))
        deg2[u] += 1
        deg2[v] += 1

used = [False] * m

# w = 1
p1 = []
p1e = []
for curr in range(n):
    if deg1[curr] % 2 == 0:
        continue
    else:
        outvv += 1
    
    u = curr
    path = [u]
    pe = []
    while adj1[u]:
        v, e = adj1[u].pop()
        if not used[e]:
            path.append(v)
            pe.append(e)
            u = v
            used[e] = True
    if len(path) > 1:
        outv += 1
        p1.append(path)
        p1e.append(pe)

curr = 0
while curr < n:
    u = curr
    path = [u]
    pe = []
    while adj1[u]:
        v, e = adj1[u].pop()
        if not used[e]:
            path.append(v)
            pe.append(e)
            u = v
            used[e] = True
    if len(path) > 1:
        p1.append(path)
        p1e.append(pe)
    else:
        curr += 1

# w = 2
p2 = []
p2e = []
for curr in range(n):
    if deg2[curr] % 2 == 0:
        continue
    u = curr
    path = [u]
    pe = []
    while adj2[u]:
        v, e = adj2[u].pop()
        if not used[e]:
            path.append(v)
            pe.append(e)
            u = v
            used[e] = True
    if len(path) > 1:
        p2.append(path)
        p2e.append(pe)
        
curr = 0
while curr < n:
    u = curr
    path = [u]
    pe = []
    while adj2[u]:
        v, e = adj2[u].pop()
        if not used[e]:
            path.append(v)
            pe.append(e)
            u = v
            used[e] = True
    if len(path) > 1:
        p2.append(path)
        p2e.append(pe)
    else:
        curr += 1

assert(all(used))

adj3 = list(range(n))
adj4 = list(range(n))
for p in p1:
    if p[0] != p[-1]:
        adj3[p[0]] = p[-1]
        adj3[p[-1]] = p[0]
for p in p2:
    if p[0] != p[-1]:
        adj4[p[0]] = p[-1]
        adj4[p[-1]] = p[0]

colors = [0] * n
for i in range(n):
    if colors[i] == 0:
        stack = [i]
        colors[i] = 1
        while stack:
            nex = stack.pop()
            if colors[adj3[nex]] == 0:
                colors[adj3[nex]] = -colors[nex]
                stack.append(adj3[nex])
            if colors[adj4[nex]] == 0:
                colors[adj4[nex]] = -colors[nex]
                stack.append(adj4[nex])

par = [-1] * m
for i in range(len(p1)):
    p = p1[i]
    pe = p1e[i]
    
    assert p[0] == p[-1] or colors[p[0]] != colors[p[-1]]
    
    if colors[p[0]] == 1:
        for v, e in zip(p[:-1], pe):
            par[e] = v
    else:
        for v, e in zip(p[1:], pe):
            par[e] = v

for i in range(len(p2)):
    p = p2[i]
    pe = p2e[i]

    assert p[0] == p[-1] or colors[p[0]] != colors[p[-1]]
    
    if colors[p[0]] == -1:
        for v, e in zip(p[:-1], pe):
            par[e] = v
    else:
        for v, e in zip(p[1:], pe):
            par[e] = v

out = []
for i in range(m):
    assert par[i] != -1
    if par[i] == parO[i]:
        out.append(1)
    else:
        assert par[i] == parP[i]
        out.append(2)

assert outvv == 2 * outv
print(2 * outv)
print(''.join(map(str,out)))