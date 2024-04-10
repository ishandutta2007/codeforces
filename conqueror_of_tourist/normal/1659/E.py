import sys
input = sys.stdin.readline

class DisjointSetUnion:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.num_sets = n
        self.cool = [0] * n

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def union(self, a, b, cupd):
        a, b = self.find(a), self.find(b)
        if a != b:
            if self.size[a] < self.size[b]:
                a, b = b, a

            self.num_sets -= 1
            self.parent[b] = a
            self.size[a] += self.size[b]
            self.cool[a] |= self.cool[b]
        #if cupd:
        #    print(a, b, cupd)
        self.cool[a] |= cupd

    def set_size(self, a):
        return self.size[self.find(a)]

    def __len__(self):
        return self.num_sets
        
n, m = map(int, input().split())
things = [DisjointSetUnion(n) for _ in range(30)]
out = []

for _ in range(m):
    a, b, w = map(int, input().split()); a -= 1; b -= 1
    cool = 1 if (w & 1 == 0) else 0
    
    for i in range(30):
        if (w & (1 << i)) > 0:
            things[i].union(a, b, cool)
        elif i:
            things[i].cool[things[i].find(a)] |= cool
            things[i].cool[things[i].find(b)] |= cool
            
q = int(input())
for _ in range(q):
    u, v = map(int, input().split()); u -= 1; v -= 1
    z = 0
    o = 0
    for UF in things:
        a = UF.find(u)
        b = UF.find(v)
        
        if a == b:
            z = 1
        if UF.cool[a]:
            o = 1
            
    if z:
        out.append(0)
    elif o:
        out.append(1)
    else:
        out.append(2)
        
print('\n'.join(map(str, out)))