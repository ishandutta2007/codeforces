import sys
input = sys.stdin.readline
rInt = lambda: int(input())
mInt = lambda: map(int, input().split())
rList = lambda: list(map(int, input().split()))

n, k = mInt()
inp = []
for i in range(n):
    inp.append(rList())

avail = k

from heapq import *
events = []

from collections import deque
queue = deque()

out = [-1] * n

heappush(events, (inp[0][0], 1, 0))
while events:
    nex = heappop(events)
    if nex[1]:
        queue.append(nex[2])
        if nex[2] < n - 1:
            heappush(events, (inp[nex[2] + 1][0], 1, nex[2] + 1))
    else:
        avail += 1

    t = nex[0]
    while avail and queue:
        avail -= 1
        nex = queue.popleft()
        end = t + inp[nex][1]
        out[nex] = end
        heappush(events, (end, 0))
        
print(*out, sep='\n')