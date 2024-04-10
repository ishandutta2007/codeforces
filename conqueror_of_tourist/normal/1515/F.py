  
class DisjointSetUnion:
    def __init__(self, n, A):
        self.parent = list(range(n))
        self.size = [1] * n
        self.asp = A[:]
        self.num_sets = n
        self.adj = [[] for i in range(n)]
        self.bad = 0

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        if a != b:
            if self.size[a] < self.size[b]:
                a, b = b, a

            if len(self.adj[a]) < len(self.adj[b]):
                self.adj[a],self.adj[b] = self.adj[b],self.adj[a]
            self.adj[a].extend(self.adj[b])

            self.num_sets -= 1
            self.parent[b] = a
            self.size[a] += self.size[b]
            self.asp[a] += self.asp[b]
            self.asp[a] -= x

    def set_size(self, a):
        return self.size[self.find(a)]

    def __len__(self):
        return self.num_sets
import sys
input = sys.stdin.readline
n,m,x = map(int, input().split())
x = float(x)
a = list(map(float, input().split()))
if sum(a) < (n - 1) * x:
    print('NO')
    exit()
print('YES')
UF = DisjointSetUnion(n,a)

q = [i for i in range(n) if a[i] >= x]
edges = []
for i in range(m):
    u, v = map(int, input().split());u-=1;v-=1
    edges.append((u,v))
    UF.adj[u].append(i)
    UF.adj[v].append(i)

#for i in range(100):
#    print(len(UF.adj[i]))

out = []
curr = 0
for run in range(n - 1):
    done = False
    while q:
        ind = q.pop()
        if UF.parent[ind] == ind and UF.asp[ind] >= x:
            done = True
            while True:
                e = UF.adj[ind].pop()
                u, v = edges[e]
                if UF.find(u) == ind:
                    u,v=v,u
                if UF.find(u) == ind:
                    continue
                out.append(e)
                UF.union(u,v)
                w = UF.find(u)
                if UF.asp[w] >= x:
                    q.append(w)
                break
        if done:
            break
    if not done:
        while curr < m:
            u, v = edges[curr]
            curr += 1
            u = UF.find(u); v = UF.find(v)
            if u != v:
                assert UF.asp[u] + UF.asp[v] >= x
                out.append(curr-1)
                UF.union(u,v)
                w = UF.find(u)
                if UF.asp[w] >= x:
                    q.append(w)
                break
print('\n'.join(map(lambda x:str(x+1),out)))