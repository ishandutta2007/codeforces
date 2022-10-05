n = int(input())
l = list(map(lambda x: int(x) - 1, input().split()))
f = list(map(int, input().split()))

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

UF = UnionFind(n)
for i in range(n):
    if 0 <= i - f[i]:
        UF.union(i, i - f[i])
    if i + f[i] < n:
        UF.union(i, i + f[i])

works = True

for i in range(n):
    if UF.find(i) == UF.find(l[i]):
        pass
    else:
        works = False
        break

if works:
    print('YES')
else:
    print('NO')