import sys
input = sys.stdin.readline

from heapq import *

n, m = map(int, input().split())

inf = 15 * 10 ** 8

norm = []
rev = []
slow = set()
for _ in range(n):
    x, y = map(int, input().split())
    heappush(norm, (x,y))
    heappush(rev, (y,x))
    slow.add((x,y))

cx = cy = 0

skipX=[]
skipY=[]

for i in range(2 * n):
    tl = tr = inf
    tlp = trp = (inf, inf)
    
    if norm:
        tl = norm[0][0] - cx
        tlp = (norm[0][0] - cx, norm[0][1] - cy)

    if rev:
        tr = rev[0][0] - cy
        trp = (rev[0][0] - cy, rev[0][1] - cx)

    if tlp < trp:
        x, y = heappop(norm)
        if tl < 0:
            continue
        cx+=tl;cy+=tl
        assert x == cx
        if y < cy:
            skipX.append(x)
            cx += 1
    else:
        y, x = heappop(rev)
        if tr < 0:
            continue
        cx+=tr;cy+=tr
        assert y == cy
        if x < cx:
            skipY.append(y)
            cy += 1

out = []
from bisect import bisect_left
for _ in range(m):
    x, y = map(int, input().split())
    if (x, y) in slow:
        out.append('LOSE')
        continue
    csx = bisect_left(skipX, x)
    csy = bisect_left(skipY, y)

    if csx < len(skipX) and skipX[csx] == x:
        out.append('WIN')
        continue
    if csy < len(skipY) and skipY[csy] == y:
        out.append('WIN')
        continue

    if x-csx==y-csy:
        out.append('LOSE')
    else:
        out.append('WIN')
print('\n'.join(map(str,out)))