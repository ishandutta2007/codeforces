import sys
input = sys.stdin.readline

n, k = map(int, input().split())

begin = [-1] * n
end = [-1] * n
hurt = [-1] * n

adj = [[] for i in range(n)]
for _ in range(n-1):
    u ,v = map(int, input().split())
    adj[u-1].append(v-1)
    adj[v-1].append(u-1)

hurt[0] = 1
begin[0] = 0
stack = [0]
curr = 1
while stack:
    nex = stack[-1]
    if adj[nex]:
        v = adj[nex].pop()
        if begin[v] == -1:
            begin[v] = curr
            curr += 1
            stack.append(v)
            hurt[v] = len(stack)
    else:
        end[nex] = curr
        stack.pop()

desc = [end[i] - begin[i]-hurt[i] for i in range(n)]
desc.sort(reverse = True)
out = 0
for i in range(n - k):
    out += desc[i]
print(out)