import sys
input = sys.stdin.readline

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
ret  = []
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())

    UF = UnionFind(n)

    out = m
    for i in range(m):
        x, y = map(int, input().split())
        x -= 1; y -= 1
        if x == y:
            out -= 1
        else:
            l = UF.find(x)
            r = UF.find(y)
            if l == r:
                out += 1
            else:
                UF.union(l, r)
    ret.append(out)

print('\n'.join(map(str,ret)))