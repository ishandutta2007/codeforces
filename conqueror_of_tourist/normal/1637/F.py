import sys
input = sys.stdin.readline

n = int(input())
h = list(map(int, input().split()))

adj = [[] for _ in range(n)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    u -= 1; v -= 1

    adj[u].append(v)
    adj[v].append(u)

tot = [0] * n
mx = [0] * n
p = [-1] * n
ch = [[] for _ in range(n)]
ch2 = [[] for _ in range(n)]

vis = [False] * n
vis[0] = True

st = [0]
while st:
    u = st.pop()
    for v in adj[u]:
        if not vis[v]:
            p[v] = u
            ch[u].append(v)
            ch2[u].append(v)
            st.append(v)
            vis[v] = True

st = [0]
while st:
    u = st[-1]
    if ch2[u]:
        st.append(ch2[u].pop())
    else:
        st.pop()

        for v in ch[u]:
            tot[u] += tot[v]
            mx[u] = max(mx[u], mx[v])

        tot[u] -= mx[u]
        mx[u] = max(mx[u], h[u])
        tot[u] += mx[u]

totdn = [0] * n
mxdn = [0] * n
st = [0]
while st:
    u = st.pop()

    toto = totdn[u]
    vals = [mxdn[u]]

    for v in ch[u]:
        toto += tot[v]
        vals.append(mx[v])
        st.append(v)

    mxo = max(vals)
    mx2 = 0
    seen = False
    for v in vals:
        if v == mxo and not seen:
            seen = True
        else:
            mx2 = max(v, mx2)

    for v in ch[u]:
        totdn[v] = toto - tot[v]
        if mx[v] == mxo:
            mxdn[v] = mx2
        else:
            mxdn[v] = mxo

        totdn[v] -= mxdn[v]
        mxdn[v] = max(mxdn[v], h[u])
        totdn[v] += mxdn[v]

poss = []
for i in range(n):
    toto = totdn[i]
    mxo = mxdn[i]

    for v in ch[i]:
        toto += tot[v]
        mxo = max(mx[v], mxo)

    if h[i] > mxo:
        pass
    else:
        poss.append(toto + mxo)

print(min(poss))