import sys, io, os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
out = []
for _ in range(t):
    out.append(0)
    
    n, m = map(int, input().split())
    l = sorted(map(lambda x: int(x) - 1, input().split()))[::-1]
    c = list(map(int, input().split()))
    
    curr = 0
    for v in l:
        if curr < m:
            out[-1] += min(c[v], c[curr])
        else:
            out[-1] += c[v]
        curr += 1
print('\n'.join(map(str,out)))