import sys
input = sys.stdin.readline

def find_SCC(graph):
    SCC, S, P = [], [], []
    depth = [0] * len(graph)
 
    stack = list(range(len(graph)))
    while stack:
        node = stack.pop()
        if node < 0:
            d = depth[~node] - 1
            if P[-1] > d:
                SCC.append(S[d:])
                del S[d:], P[-1]
                for node in SCC[-1]:
                    depth[node] = -1
        elif depth[node] > 0:
            while P[-1] > depth[node]:
                P.pop()
        elif depth[node] == 0:
            S.append(node)
            P.append(len(S))
            depth[node] = len(S)
            stack.append(~node)
            stack += graph[node]
    return SCC[::-1]

n, m = map(int, input().split())
board = []
for _ in range(n):
    board.append(input())
l = list(map(int, input().split()))

adj = [[] for _ in range(n * m)]

last = [-1] * m

for i in range(n-1,-1,-1):
    for j in range(m):
        if board[i][j] == '#':
            if last[j] != -1:
                adj[m * i + j].append(m*last[j] + j)
                if last[j] == i + 1:
                    adj[m * (i+1) + j].append(m*i + j)
            last[j] = i

            if j != 0 and last[j-1] != -1:
                adj[m * i + j].append(m*last[j-1] + j-1)
                if last[j-1] == i:
                    adj[m * i + j - 1].append(m * i + j)

            if j != m - 1 and last[j + 1] != -1:
                adj[m * i + j].append(m*last[j+1] + j+1)

tar = find_SCC(adj)
comp = [-1] * (m * n)
curr = 0
for l in tar:
    for v in l:
        comp[v] = curr
    curr += 1
outB = [True] * curr
for i in range(m * n):
    for v in adj[i]:
        if comp[i] != comp[v]:
            outB[comp[v]] = False

for i in range(n):
    for j in range(m):
        if board[i][j] == '.':
            outB[comp[m * i + j]] = False

out = 0
for b in outB:
    if b:
        out += 1
        
print(out)