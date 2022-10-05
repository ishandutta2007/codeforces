import sys
import heapq
input = sys.stdin.readline

n, k = map(int, input().split())
l = []
for i in range(n):
    a, b = map(int, input().split())
    l.append((a,b))
l.sort(key = lambda x: x[1], reverse = True)
best = 0
curr = 0
q = []

for i in range(k):
    curr += l[i][0]
    heapq.heappush(q,l[i][0])
    best = max(best, curr * l[i][1])
for i in range(k,n):
    curr += l[i][0]
    heapq.heappush(q,l[i][0])
    curr -= heapq.heappop(q)
    best = max(best, curr * l[i][1])
print(best)