from queue import Queue

n, m = map(int, input().split())
M = 10 ** 5
g = [[] for i in range(M)]
for i in range(1, M):
    y = i - 1
    if y > 0:
        g[i].append(y)
    y = i * 2
    if y < M:
        g[i].append(y)
d = [10 ** 9 for i in range(M)]
d[n] = 0
q = Queue()
q.put(n)
while not q.empty():
    k = q.get()
    for y in g[k]:
        if d[y] > d[k] + 1:
            q.put(y)
            d[y] = d[k] + 1
print(d[m])