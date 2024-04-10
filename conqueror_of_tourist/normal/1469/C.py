import sys
input = sys.stdin.readline

t = int(input())
outL = []
for _ in range(t):
    n, k = map(int, input().split())
    h = map(int, input().split())
    lo = hi = next(h)
    works = True
    for v in h:
        lo, hi = max(lo - (k - 1), v), min(hi + (k - 1), v + (k - 1))
        if hi < lo:
            works = False
    
    if works and lo == v:
        outL.append('YES')
    else:
        outL.append('NO')
print('\n'.join(outL))