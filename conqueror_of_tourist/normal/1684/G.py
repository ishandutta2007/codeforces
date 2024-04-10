INF = float("inf")


class Dinic:
    def __init__(self, n):
        self.lvl = [0] * n
        self.ptr = [0] * n
        self.q = [0] * n
        self.adj = [[] for _ in range(n)]

    def add_edge(self, a, b, c, rcap=0):
        self.adj[a].append([b, len(self.adj[b]), c, 0])
        self.adj[b].append([a, len(self.adj[a]) - 1, rcap, 0])

    def dfs(self, v, t, f):
        if v == t or not f:
            return f

        for i in range(self.ptr[v], len(self.adj[v])):
            e = self.adj[v][i]
            if self.lvl[e[0]] == self.lvl[v] + 1:
                p = self.dfs(e[0], t, min(f, e[2] - e[3]))
                if p:
                    self.adj[v][i][3] += p
                    self.adj[e[0]][e[1]][3] -= p
                    return p
            self.ptr[v] += 1

        return 0

    def calc(self, s, t):
        flow, self.q[0] = 0, s
        for l in range(31):  # l = 30 maybe faster for random data
            while True:
                self.lvl, self.ptr = [0] * len(self.q), [0] * len(self.q)
                qi, qe, self.lvl[s] = 0, 1, 1
                while qi < qe and not self.lvl[t]:
                    v = self.q[qi]
                    qi += 1
                    for e in self.adj[v]:
                        if not self.lvl[e[0]] and (e[2] - e[3]) >> (30 - l):
                            self.q[qe] = e[0]
                            qe += 1
                            self.lvl[e[0]] = self.lvl[v] + 1

                p = self.dfs(s, t, INF)
                while p:
                    flow += p
                    p = self.dfs(s, t, INF)

                if not self.lvl[t]:
                    break

        return flow

n, m = map(int, input().split())

#t = [1, 7] * (n // 2)
t = list(map(int, input().split()))
out = []


l = []
r = []
for v in t:
    if 3 * v > m:
        l.append(v)
    else:
        r.append(v)

ls = len(l)
rs = len(r)

sr = n
sn = n + 1

MF = Dinic(n + 2)
for i in range(ls):
    MF.add_edge(sr, i, 1)
for i in range(ls, n):
    MF.add_edge(i, sn, 1)

for i in range(ls):
    for j in range(rs):
        if l[i] % r[j] == 0 and r[j] <= m - 2 * l[i]:
            MF.add_edge(i, ls + j, 1)

flow = MF.calc(sr, sn) 

if flow != ls:
    print(-1)
else:
    used = [False] * rs

    for i in range(ls):
        al = MF.adj[i]
        nex = -1
        for e in al:
            if e[3] == 1:
                assert nex == -1
                nex = e[0] - ls

        assert nex != -1
        used[nex] = True

        a, b = 2 * l[i] + r[nex], l[i] + r[nex]
        out.append(f'{a} {b}')

    for i in range(rs):
        if not used[i]:
            a, b = 3 * r[i], 2 * r[i]
            out.append(f'{a} {b}')

    print(len(out))
    print('\n'.join(out))