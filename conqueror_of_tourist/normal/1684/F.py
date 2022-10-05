import sys
input = sys.stdin.readline

out = []

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = input().split()

    seg = []
    for _ in range(m):
        u, v = map(int, input().split())
        
        u -= 1; v -= 1
        
        seg.append((u, -v))

    seg.sort()

    best = -1
    segs = []
    for u, nv in seg:
        v = -nv

        if v > best:
            best = v
            segs.append((u, v))

    left = [-1] * n
    right = [n + 100] * n

    seen = dict()

    for i in range(n):
        v = a[i]
        if v in seen:
            left[i] = seen[v]
            right[seen[v]] = i
        seen[v] = i

    #print(segs)
        
    lint = [-1] * n
    rint = [-1] * n
    
    l, r = 0, -1
    for u, v in segs:
        if u > r:
            r = u - 1
        for i in range(r + 1, v + 1):
            lint[i] = u
        r = v

    l = n + 10
    for u, v in segs[::-1]:
        if v < l:
            l = v + 1
        for i in range(u, l):
            rint[i] = v
        l = u

    pairs = []
    guar = []

    used = [False] * n
    for i in range(n):
        if used[i]:
            continue

        curr = i
        while right[curr] <= rint[curr]:
            if curr != i:
                guar.append(curr)

            curr = right[curr]
            used[curr] = True


        if curr != i and rint[i] >= curr:
            pairs.append((i, curr))
    pairs.sort()

    if len(pairs) == 0:
        out.append(0)
        continue

    lp = len(pairs)

    lub = guar[::]
    rlb = guar[::]
    for u, v in pairs:
        lub.append(v)
        rlb.append(u)

    poss = []

    low = min(lub)
    hi = max(rlb)

    conds = [0] * (n + 1)
    pnum = 0
    
    for i in range(low + 1):
        poss.append(hi - i + 1)

        #for u, v in pairs:
        #    assert (i <= u <= hi) or (i <= v <= hi)
        
        while pnum < lp and pairs[pnum][0] == i:
            hi = max(hi, pairs[pnum][1])
            pnum += 1

    #print(poss)
    out.append(min(poss))
        

        

print('\n'.join(map(str, out)))