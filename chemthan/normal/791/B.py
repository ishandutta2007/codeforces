import random

n, m = map(int, input().split())
g = [set([x]) for x in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].add(b)
    g[b].add(a)
vis = [0 for i in range(n)]
for i in range(n):
    if vis[i] == 1:
        continue
    for j in g[i]:
        vis[j] = 1
        if g[i] != g[j]:
            print("NO")
            exit(0)
    
print("YES")

exit(0)