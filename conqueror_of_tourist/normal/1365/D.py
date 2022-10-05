t = int(input())
dX = [1,-1,0,0]
dY = [0,0,-1,1]
for _ in range(t):
    n, m = map(int, input().split())
    l = []
    for i in range(n):
        l.append(list(input().strip()))

    gCount = 0
    for i in range(n):
        for j in range(m):
            if l[i][j] == 'G':
                gCount += 1
            elif l[i][j] == 'B':
                for d in range(4):
                    x = i + dX[d]
                    y = j + dY[d]
                    if 0 <= x < n and 0 <= y < m and l[x][y] == '.':
                        l[x][y] = '#'

    visited = [[False] * m for i in range(n)]
    gVisit = 0
    stack = []
    if l[n-1][m-1] != '#':
        stack.append((n-1,m-1))
        visited[n-1][m-1] = True
    works = True
    while stack:
        nexX, nexY = stack.pop()
        c = l[nexX][nexY]
        if c == 'G':
            gVisit += 1
        elif c == 'B':
            works = False
            break

        for d in range(4):
            x = nexX + dX[d]
            y = nexY + dY[d]
            if 0 <= x < n and 0 <= y < m and l[x][y] != '#' and not visited[x][y]:
                visited[x][y] = True
                stack.append((x,y))
    if works and gVisit == gCount:
        print('Yes')
    else:
        print('No')