import sys, io, os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

MAX = 10 ** 6 + 5
find = list(range(MAX))
for i in range(1,1001):
    for j in range(0,MAX,i*i):
        find[j] = j//i//i
        
t = int(input())
out = []
for _ in range(t):
    n = int(input())

    counts = dict()
    best = 0
    
    for v in map(int, input().split()):
        u = find[v]
        if u not in counts:
            counts[u] = 0
        counts[u] += 1
        best = max(best, counts[u])
    
    tol = 0
    for u in counts:
        if u == 1 or counts[u] % 2 == 0:
            tol += counts[u]
    
    q = int(input())
    for _ in range(q):
        v = int(input())
        if v == 0:
            out.append(best)
        else:
            out.append(max(best,tol))
print('\n'.join(map(str,out)))