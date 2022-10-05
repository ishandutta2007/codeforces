import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    adj = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        adj[u-1].append(v-1)
        adj[v-1].append(u-1)

    leaf = 0
    bud = 0
    below = [0] * n
    stack = [0]
    vis = [False] * n
    vis[0] = True

    par = [-1] * n

    while stack:
        cur = stack[-1]
        if adj[cur]:
            nex = adj[cur].pop()
            if not vis[nex]:
                vis[nex] = True
                par[nex] = cur
                stack.append(nex)
        else:
            if below[cur] == 0:
                leaf += 1
                if cur:
                    below[par[cur]] += 1
            else:
                if cur:
                    bud += 1
            stack.pop()
    print(leaf - bud)