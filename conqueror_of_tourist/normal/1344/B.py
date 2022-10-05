import sys
input = sys.stdin.readline

n, m = map(int, input().split())
l = [''] * n
for i in range(n):
    l[i] = input().strip()

works = True

rows = [False] * n
cols = [False] * m
for i in range(n):
    for j in range(m):
        if l[i][j] == '#':
            rows[i] = True
            cols[j] = True
if all(rows) ^ all(cols):
    works = False

for i in range(n):
    s = l[i]
    left = -1
    right = -1
    for j in range(m):
        if s[j] == '#':
            if left == -1:
                left = j
            right = j
    for j in range(left + 1, right):
        if s[j] != '#':
            works = False
    

for j in range(m):
    left = -1
    right = -1
    for i in range(n):
        if l[i][j] == '#':
            if left == -1:
                left = i
            right = i
    for i in range(left + 1, right):
        if l[i][j] != '#':
            works = False

if works:
    visited = [[False] * m for i in range(n)]
    out = 0

    for i in range(n):
        for j in range(m):
            if l[i][j] != '#':
                visited[i][j] = True

    for startX in range(n):
        for startY in range(m):
            if not visited[startX][startY]:
                out += 1
                visited[startX][startY] = True
                queue = [(startX, startY)]
                while queue:
                    x, y = queue.pop()
                    for d in range(4):
                        nX = x + [0,0,-1,1][d]
                        nY = y + [1,-1,0,0][d]
                        if 0 <= nX < n and 0 <= nY < m and not visited[nX][nY]:
                            visited[nX][nY] = True
                            queue.append((nX, nY))

    print(out)
else:
    print(-1)