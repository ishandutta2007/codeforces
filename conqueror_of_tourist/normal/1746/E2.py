import sys, random
input = sys.stdin.readline

n = int(input())

good = list(range(1, n + 1))
mid = []

def query(l):
    print('?',len(l),' '.join(map(str, l)))
    sys.stdout.flush()

    #return random.randint(0, 1)

    s = input().strip()
    return s == 'YES'

from functools import cache

@cache
def solveu(p, q):
    if p + q <= 2:
        return 0

    if p == 2 and q == 1:
        return 2

    if p + q < 10:
        uu, vv = solved(p, q, 0)

        pl = uu
        ql = vv

        pr = p - pl
        qr = q - ql
    else:
        pl = p // 2
        pr = p - pl

        qr = q // 2
        ql = q - qr

    #print(pl, pr, ql, qr)

    return 1 + max(solveu(pl + ql, pr), solveu(pr + qr, pl))

@cache
def solve(p, q):
    if p + q <= 2:
        return 0

    if p == 2 and q == 1:
        return 2

    pl = p // 2
    pr = p - pl

    qr = q // 2
    ql = q - qr

    #print(pl, pr, ql, qr)

    return 1 + max(solve(pl + ql, pr), solve(pr + qr, pl))

@cache
def solved(p, q, d):
    if d > 100:
        return d
    
    if p + q <= 2:
        return d

    if p == 2 and q == 1:
        return 2 + d

    poss = []
    
    for i in range(p + 1):
        for j in range(q + 1):
            poss.append((max(solved(i + j, p - i, d + 1), solved(p - i + q - j, i, d + 1)), i, j))

    if d == 0:
        return min(poss)[1:]

    return min(poss)[0]

mz = solveu(n, 0)
assert mz <= 53



ct = 0
while len(good) + len(mid) > 2:
    curr = ct + solveu(len(good), len(mid))
    assert curr <= mz
    mz = min(curr, mz)
    
    ct += 1
    assert ct <= 53
    
    p = len(good)
    q = len(mid)
    #print(good, mid)

    if p == 2 and q == 1:
        if query(good):
            mid = []
            continue
        else:
            mid, good = good, mid
            continue

    if p + q < 10:
        uu, vv = solved(p, q, 0)

        pl = good[:uu]
        pr = good[uu:]

        ql = mid[:vv]
        qr = mid[vv:]
    else:
        pl = good[:p//2]
        pr = good[p//2:]

        ql = mid[q//2:]
        qr = mid[:q//2]

    if query(pl + ql):
        good = pl + ql
        mid = pr
    else:
        good = pr + qr
        mid = pl

poss = good + mid

for v in poss:
    print('!',v)
    sys.stdout.flush()
    s = input().strip()
    if s == ':)':
        exit()