import sys,heapq
input = sys.stdin.readline

out = []

t = int(input())
for _ in range(t):
    n,m,x = map(int, input().split())
    h = list(map(int, input().split()))
    out.append('YES')
    lis = [-1] * n
    q = [(0,i+1) for i in range(m)]
    heapq.heapify(q)
    for i in range(n):
        v = h[i]
        curr, ind = heapq.heappop(q)
        lis[i] = ind
        heapq.heappush(q, (curr + v, ind))
    out.append(' '.join(map(str,lis)))
print('\n'.join(out))