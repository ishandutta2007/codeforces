import sys
input = sys.stdin.readline

n = int(input())

good = list(range(1, n + 1))
mid = []

def query(l):
    print('?',len(l),' '.join(map(str, l)))
    sys.stdout.flush()

    s = input().strip()
    return s == 'YES'

ct = 0
while len(good) + len(mid) > 2:
    ct += 1

    assert ct < 70
    
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