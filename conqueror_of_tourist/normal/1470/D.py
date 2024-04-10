import sys, io, os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
out = []

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    adj = [[] for _ in range(n)]
    color = [-1]*n
    
    color[0] = 0
    
    for _ in range(m):
        u, v= map(int, input().split())
        adj[u-1].append(v-1)
        adj[v-1].append(u-1)
        
    stack = [0]
    while stack:
        nex = stack.pop()
        for v in adj[nex]:
            if color[nex] == 1:
                if color[v] == -1:
                    stack.append(v)
                color[v] = 0
            elif color[v] == -1:
                color[v] = 1 - color[nex]
                stack.append(v)
    
    for v in color:
        if v == -1:
            out.append('NO')
            break
    else:
        out.append('YES')
        final = [i + 1 for i in range(n) if color[i]]
        out.append(str(len(final)))
        out.append(' '.join(map(str,final)))
print('\n'.join(out))