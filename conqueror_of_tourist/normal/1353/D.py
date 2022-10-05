import sys
input = sys.stdin.readline
rInt = lambda: int(input())
mInt = lambda: map(int, input().split())
rLis = lambda: list(map(int, input().split()))

from heapq import *

t = rInt()
for _ in range(t):
    n = rInt()
    out = [0] * n

    q = []
    heappush(q, (-n, 0))

    curr = 0

    while q:
        curr += 1
        nex = heappop(q)

        #print(nex)
        
        length = -nex[0]
        start = nex[1]
        if length % 2:
            out[start + length//2] = curr
            if length//2:
                heappush(q, (-(length//2), start))
                heappush(q, (-(length//2), start + length//2 + 1))
        else:
            half = length // 2
            out[start + length//2 - 1] = curr
            heappush(q, (-(length//2), start + length//2))
            if length > 2:
                heappush(q, (-(length//2 - 1), start))
    print(*out, sep = ' ')