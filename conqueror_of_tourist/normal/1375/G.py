import sys
input = sys.stdin.readline

n = int(input())
adj = [[] for i in range(n)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    adj[u-1].append(v-1)
    adj[v-1].append(u-1)

depth = [-1] * n
depth[0] = 0
    
odd = 0
even = 1

q = [0]
while q:
    nex = q.pop()
    for v in adj[nex]:
        if depth[v] == -1:
            depth[v] = depth[nex] + 1
            if depth[v] & 1:
                odd += 1
            else:
                even += 1
            q.append(v)

print(min(odd,even) - 1)