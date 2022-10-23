from bisect import bisect

import sys
input = sys.stdin.readline

n, b, p, m = map(int, input().split())


adds = []
curr = []
mults = []

i = 0
for _ in range(n):
    t, v = input().split()
    v = int(v)
    
    if t == '*':
        if v == 1:
            continue
        curr.sort()

        adds.append(curr)
        mults.append(v)
        curr = []
    else:
        curr.append(v)
        
curr.sort()
adds.append(curr)

pref = []
for l in adds:  
    np = [0]
    for v in l[::-1]:
        np.append(v + np[-1])
    pref.append(np)

y = len(mults)
un_m = sorted(set(mults))
z = len(un_m)
ct_m = [0] * z
for v in mults:
    for i in range(z):
        if un_m[i] == v:
            ct_m[i] += 1

from itertools import product
poss = []

assert len(adds) == y + 1

for tup in product(*[range(ct + 1) for ct in ct_m]):
    rem_adds = (b - m * sum(tup))//p
    
    if rem_adds < 0:
        continue

    d = {}
    for i in range(z):
        d[un_m[i]] = tup[i]

    end = 1
    used = [0] * y

    for i in range(y):
        if d[mults[i]]:
            used[i] = 1
            d[mults[i]] -= 1
            end *= mults[i]

    seg_mult = [1]
    for i in range(y - 1, -1, -1):
        if used[i] == 0:
            seg_mult.append(seg_mult[-1] * mults[i])
        else:
            seg_mult.append(seg_mult[-1])
    seg_mult.reverse()

    exc = [seg_mult[0] - v for v in seg_mult]

    init_tot = 0
    for j in range(y + 1):
        if exc[j] != 0:
            init_tot += len(adds[j])

    lo = 0 #Ct value provided >= lo >= rem_adds
    hi = 10 ** 18 + 100 #Too high
    while hi - lo > 1:
        mid = lo + (hi - lo) // 2

        tot = init_tot
        for j in range(y + 1):
            if exc[j] == 0:
                continue
            
            limit = (mid - 1) // exc[j]

            #ct = len(adds[j]) - bisect(adds[j], limit - 1)
            #tot += ct

            diff = bisect(adds[j], limit)
            tot -= diff
            #print(mid, j, diff) 

        if tot >= rem_adds:
            lo = mid
        else:
            hi = mid

    tot = seg_mult[0]
    ct = 0
    for j in range(y + 1):
        tot += pref[j][-1] * seg_mult[j]

        if exc[j] == 0:
            continue
        
        limit = (lo - 1) // exc[j]

        s_ct = len(adds[j]) - bisect(adds[j], limit)

        tot += pref[j][s_ct] * exc[j]
        ct += s_ct

    if lo != 0:
        assert ct >= rem_adds
        tot -= lo * (ct - rem_adds)

    #print(tup, lo, tot, end)
    poss.append(tot * end)
    #break
    




print(max(poss))