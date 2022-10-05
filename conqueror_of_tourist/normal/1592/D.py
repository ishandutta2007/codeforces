import sys
input = sys.stdin.readline

n = int(input())
adj = [[] for _ in range(n)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    adj[u - 1].append(v - 1)
    adj[v - 1].append(u - 1)
    
edges = []
vis = [False] * n
vis[0] = True
st = [0]
while st:
    curr = st[-1]
    if adj[curr]:
        nex = adj[curr].pop()
        if not vis[nex]:
            vis[nex] = True
            edges.append((curr,nex))
            st.append(nex)
    else:
        st.pop()

def query(l):
    print('?', len(l),' '.join(map(lambda x: str(x + 1),l)))
    sys.stdout.flush()
    return int(input())

mx = query(list(range(n)))

lo = 0
hi = n - 1
#mx in [lo, hi)
while hi - lo > 1:
    cut = (lo + hi)//2
    s = set()
    for u, v in edges[lo:cut]:
        s.add(u)
        s.add(v)
    v = query(list(s))
    if v == mx:
        hi = cut
    else:
        lo = cut

o1, o2 = edges[lo]
print('!', o1 + 1, o2 + 1)