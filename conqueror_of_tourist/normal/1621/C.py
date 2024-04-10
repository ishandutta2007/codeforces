import sys
input = sys.stdin.readline

def q(i):
    print('?',i+1)
    sys.stdout.flush()
    r = int(input())
    assert r != 0
    
    return r - 1

def rep(l):
    print('!',' '.join(map(lambda x: str(1+x),l)))
    sys.stdout.flush()

t = int(input())
for _ in range(t):
    n = int(input())

    out = [-1] * n
    for i in range(n):
        if out[i] != -1: continue

        curr = []
        while True:
            curr.append(q(i))

            if len(curr) > 1 and curr[0] == curr[-1]:
                break

        for i in range(len(curr) - 1):
            out[curr[i]] = curr[i+1]

    rep(out)


#print('\n'.join(map(str,out)))