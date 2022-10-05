import sys
input = sys.stdin.readline

t = int(input())

out = []
for _ in range(t):
    n = int(input())

    a = []
    b = []

    for i in range(n):
        aa, bb = map(int, input().split())
        a.append(aa)
        b.append(bb)
    
    lo = 0
    hi = n + 1

    while hi - lo > 1:
        lim = (lo + hi)//2
        curr = 0
        for i in range(n):
            if curr <= b[i] and lim - (curr + 1) <= a[i]:
                curr += 1
        if curr >= lim:
            lo = lim
        else:
            hi = lim


    out.append(lo)

print('\n'.join(map(str,out)))