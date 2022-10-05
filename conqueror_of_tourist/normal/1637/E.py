import sys
input = sys.stdin.readline
from collections import Counter

out = []

t = int(input())
for _ in range(t):
    n, m = map(int,input().split())
    a = list(map(int, input().split()))
    c = Counter(a)

    bad = set()
    for i in range(m):
        u, v = map(int, input().split())
        bad.add((u, v))
        bad.add((v, u))

    vals = sorted(c.keys())

    ct = dict()

    for v in vals:
        if c[v] not in ct:
            ct[c[v]] = []
        ct[c[v]].append(v)

    ctl = list(ct.keys())

    poss = []
    for v in vals:
        ctv = c[v]
        for cnt in ctl:
            l = len(ct[cnt])
            for i in range(l - 1, -1, -1):
                u = ct[cnt][i]
                if u <= v:
                    break
                if not (u, v) in bad:
                    poss.append((u + v) * (cnt + ctv))
                    break
    out.append(max(poss))
print('\n'.join(map(str,out)))