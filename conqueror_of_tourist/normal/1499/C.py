import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))

    so = 0
    me = mo = float('inf')
    se = 0
    co = ce = 0

    poss = []
    
    for i in range(n):
        v = l[i]
        if i % 2 == 0:
            so += v
            mo = min(mo, v)
            co += 1
        else:
            se += v
            me = min(me, v)
            ce += 1
        poss.append(so + se + (n - co) * mo + (n - ce) * me)
    print(min(poss))