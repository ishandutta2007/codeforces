def solve(n, debug=False):
    global curr
    global seen
    global last
    big = []
    small = []

    for i in range(1,1+n):
        l = list(map(int, input().split()))
        if l[0] > 600:
            big.append((i,l[1:]))
        else:
            small.append((i,l[1:]))

    s1 = len(big)
    s2 = len(small)

    if debug:
        print(s1,s2)
        return ''

    for s, l1 in big:
        care = set(l1)
        for t, l2 in big + small:
            if s == t: continue
            count = 0
            for v in l2:
                if v in care:
                    count += 1
            if count >= 2:
                return str(s) + ' ' + str(t)

    mapD = dict()
    curr = 0
    seen = []
    last = []
    
    def mapV(x):
        global curr
        global seen
        global last
        
        if x in mapD:
            return mapD[x]
        else:
            mapD[x] = curr
            curr += 1
            seen.append([])
            last.append((-1,-1))
            return curr - 1

    msmall = []
    
    for i in range(s2):
        u, l = small[i]
        new = []
        for v in l:
            seen[mapV(v)].append(i)
            new.append(mapV(v))
        msmall.append(new)

    for v1 in range(len(seen)):
        for i in seen[v1]:
            for v2 in msmall[i]:
                if v1 == v2: continue
            
                lastV = last[v2]
                if lastV[0] == v1:
                    return str(lastV[1]) + ' ' + str(small[i][0])
                else:
                    last[v2] = (v1, small[i][0])

    return '-1'

import sys,io,os;input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
t = int(input())
o = []
for _ in range(t):
    n = int(input())
    
    if n > 80000:
        o.append(solve(n))
        continue
    
    seen = dict()
    out = (-1,-1)

    for s in range(n):
        adj = set()
        adjL = set()
        l = list(map(int, input().split()))
        for v in l[1:]:
            if v in seen:
                ot = seen[v]
                if len(ot) > len(adjL) and len(ot) > len(adj):
                    adj |= adjL
                    adjL = ot
                    for u in adj:
                        if u in adjL:
                            out = (u, s)
                            break
                else:
                    for u in ot:
                        if u in adj or u in adjL:
                            out = (u, s)
                            break
                        else:
                            adj.add(u)
                            
                    

                if out[0] == -1:
                    seen[v].add(s)
                else:
                    break
            else:
                seen[v] = set([s])
                
        if out[0] != -1:
            while s < n-1:
                input()
                s += 1
            break


    if out[0] == -1:
        o.append('-1')
    else:
        o.append(str(out[0] + 1) + ' ' + str(out[1] + 1))
print('\n'.join(o))