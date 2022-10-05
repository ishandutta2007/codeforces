import sys
input = sys.stdin.readline

n, m = map(int, input().split())

class DisjointSetUnion:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.num_sets = n

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

            self.num_sets -= 1
            self.parent[b] = a
            self.size[a] += self.size[b]

    def set_size(self, a):
        return self.size[self.find(a)]

    def __len__(self):
        return self.num_sets


l = []
for i in range(n):
    l.append(input().strip())

UF = DisjointSetUnion(n * m)
for i in range(n):
    for j in range(m):
        if i < n - 1:
            if l[i][j] == '.' and l[i+1][j] == '.':
                UF.union(m * i + j, m * i + m + j)
        if j < m - 1:
            if l[i][j] == '.' and l[i][j+1] =='.':
                UF.union(m * i + j, m * i + j + 1)

out = []
for i in range(n):
    curr = []
    for j in range(m):
        if l[i][j] == '.':
            curr.append('.')
        else:
            dx = [0,0,-1,1]
            dy = [-1,1,0,0]
            adj = set()
            for d in range(4):
                nx = i + dx[d]
                ny = j + dy[d]
                if 0 <= nx < n and 0 <= ny < m and l[nx][ny] == '.':
                    adj.add(UF.find(m * nx + ny))
                    
            outV = 1
            for v in adj:
                outV += UF.set_size(v)
            curr.append(str(outV % 10))
    out.append(''.join(curr))
print('\n'.join(out))