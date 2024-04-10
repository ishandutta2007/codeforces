import sys
input = sys.stdin.readline
res = []
t = int(input())
for _ in range(t):
    n = int(input())
    l = map(int, input().split())
    c = [0] * n
    for v in l:
        c[v-1] += 1
    c.sort()
    c.reverse()
    while c[-1] == 0:
        c.pop()
    
    best = n
    for i in range(2, c[-1] + 2):
        out = 0
        for v in c:
            smol = (-v) % i
            tol = (v + smol)//i - smol
            if tol >= 0:
                out += smol + tol
            else:
                out += n
        best = min(best, out)
    res.append(best)
print('\n'.join(map(str,res)))