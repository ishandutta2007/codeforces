class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def union(self, a, b):
        self.parent[self.find(b)] = self.find(a)

import sys
input = sys.stdin.readline

n, m1, m2 = map(int, input().split())
uf1 = UnionFind(n)
uf2 = UnionFind(n)
out = []
for _ in range(m1):
    u, v = map(int, input().split())
    uf1.union(u-1,v-1)
for _ in range(m2):
    u, v = map(int, input().split())
    uf2.union(u-1,v-1)

t10 = set()
t01 = set()

for i in range(1, n):
    f0 = uf1.find(0) == uf1.find(i)
    s0 = uf2.find(0) == uf2.find(i)
    if f0 and s0: pass
    elif f0: t01.add(i)
    elif s0: t10.add(i)
    else: 
        out.append((0,i))
        uf1.union(0,i)
        uf2.union(0,i)
    
    a = b = -1
    while t01 and a == -1:
        a = t01.pop()
        if uf2.find(a) == uf2.find(0):
            a = -1
    
    while t10 and b == -1:
        b = t10.pop()
        if uf1.find(b) == uf1.find(0):
            b = -1
            
    if a != -1 and b != -1:
        out.append((a,b))
        uf1.union(a,b)
        uf2.union(a,b)
    else:
        if a != -1:
            t01.add(a)
        if b != -1:
            t10.add(b)
    
print(len(out))
l = []
for u, v in out:
    l.append(str(u+1)+' '+str(v+1))
print('\n'.join(l))