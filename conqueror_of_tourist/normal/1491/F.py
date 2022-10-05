import sys
input = sys.stdin.readline

def query(l,r):
    print('?',len(l),len(r))
    print(' '.join(map(lambda x: str(x + 1),l)))
    print(' '.join(map(lambda x: str(x + 1),r)))
    sys.stdout.flush()

    return int(input())

def ret(l):
    print('!',len(l),' '.join(map(lambda x: str(x + 1),l)))
    sys.stdout.flush()

t = int(input())
for _ in range(t):
    n = int(input())
    out = []

    for i in range(1, n):
        F = query(range(i),[i])
        if F != 0:
            break
        
    base = i
    for i in range(base + 1, n):
        F = query([base], [i])
        if F == 0:
            out.append(i)

    lo = 0
    hi = base #Impossible
    while hi - lo > 1:
        t = (lo + hi) // 2
        
        F = query([base], range(t))
        if F == 0:
            lo = t
        else:
            hi = t

    other = lo
    for i in range(base):
        if i != other:
            out.append(i)

    ret(out)