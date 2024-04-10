def dfs(i, j):
  vis[i][j] = True
  global cells
  cells += 1
  adj = [(i - 1, j), (i, j + 1), (i + 1, j), (i, j - 1)]
  adj.reverse()
  c = box[i][j]
  for x, y in adj:
    if 0 <= x < n and 0 <= y < m and not vis[x][y] and not (c % 2):
      dfs(x, y)
    c //= 2

n, m = (int(x) for x in input().split())
box = [[int(x) for x in input().split()] for _ in range(n)]
vis = [[False] * m for _ in range(n)]
sizes = []
for i in range(n):
  for j in range(m):
    if not vis[i][j]:
      cells = 0
      dfs(i, j)
      sizes.append(cells)
sizes.sort(reverse=True)
for x in sizes:
  print(x, end=' ')