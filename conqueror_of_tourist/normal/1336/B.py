import sys
import bisect
input = sys.stdin.readline

out = []
t = int(input())
for _ in range(t):
    nr, ng, nb = map(int, input().split())
    r = list(map(int,input().split()))
    g = list(map(int,input().split()))
    b = list(map(int,input().split()))

    r.sort()
    g.sort()
    b.sort()

    best = 10 ** 24
    for x, y, z in ((r,g,b),(g,r,b),(b,g,r)):
        for i in range(len(x)):
            new = 0
            v = []
            for l in (y,z):
                ind = bisect.bisect(l, x[i])
                add = (l[ind-1] - x[i])**2
                v.append(l[ind-1])
                if ind < len(l):
                    if (l[ind] - x[i])**2 < add:
                        v[-1] = l[ind]
                        add = (l[ind] - x[i])**2
                new += add
            new += (v[0] - v[1]) ** 2
            if new < best:
                best = new
    
    out.append(best)
print('\n'.join(map(str,out)))