from __future__ import print_function, division
import sys

n = int(raw_input())
gr = [[] for i in xrange(n)]
rgr = [[] for i in xrange(n)]
root = 0
for i in xrange(n):
    inp = map(int, raw_input().split())
    for f in xrange(n):
        if inp[f] > 0:
            gr[i].append(f)
            rgr[f].append(i)
            if f == i:
                root = i

vis = [False for i in xrange(n)]
def dfs(u, gr, yes):
    global n
    vis[u] = yes 
    st = [u]
    ans = 1
    while len(st) > 0:
        u = st.pop()
        for v in gr[u]:
            if vis[v] == yes:
                continue
            ans += 1
            vis[v] = yes 
            st.append(v)
    return ans

cnt1 = dfs(root, gr, True)
cnt2 = dfs(root, rgr, False)
if cnt1 == n and cnt2 == n:
    print("YES")
else:
    print("NO")