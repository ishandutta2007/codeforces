import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())

    p = [0] + list(map(lambda x: int(x) - 1, input().split()))
    s = list(map(int, input().split()))

    ind = [0] * n
    for v in p[1:]:
        ind[v] += 1

    topo = []
    indc = ind[:]
    st = []
    for i in range(n):
        if ind[i] == 0:
            st.append(i)

    ch = [[] for _ in range(n)]
    while st:
        u = st.pop()
        topo.append(u)

        if u == 0:
            continue
        
        indc[p[u]] -= 1
        if indc[p[u]] == 0:
            st.append(p[u])

        ch[p[u]].append(u)
    assert topo[-1] == 0

    dep = [0] * n
    for u in topo[::-1]:
        dep[u] = dep[p[u]] + s[u]

    #lar = dep[:]
    #for u in topo:
    #    lar[p[u]] = max(lar[p[u]], lar[u])


    c = [0] * n
    c[0] = k
    ex = [0] * n
    nex = [0] * n

    out = 0

    for u in topo[::-1]:
        if ind[u] == 0:
            #nex[u] = dep[u]
            continue

        ex[u] = c[u] % ind[u]
        drip = c[u] // ind[u]
        for v in ch[u]:
            c[v] = drip

    for u in topo:
        if ind[u] == 0:
            out += dep[u] * c[u]
            nex[u] = dep[u]
            continue

        poss = [nex[v] for v in ch[u]]
        poss.sort(reverse = True)

        out += sum(poss[:ex[u]])
        nex[u] = poss[ex[u]]

    print(out)