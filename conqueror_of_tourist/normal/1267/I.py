import sys
input = sys.stdin.readline

def query(a, b):
    print("?", a+1, b+1, flush = True)

t = int(input())
for __ in range(t):
    n = int(input())
    good = set()
    bad = set()

    for i in range(n):
        query(i, i + n)

        s = input().strip()
        if s == "<":
            good.add(i + n)
            bad.add(i)
        else:
            good.add(i)
            bad.add(i + n)

    best = -1

    for test in bad:
        if best == -1:
            best = test
        else:
            query(best, test)
            sp = input().strip()
            if sp == "<":
                best = test

    bad.remove(best)     

    for i in range(n):
        worst = -1

        for test in bad:
            if worst == -1:
                worst = test
            else:
                query(worst, test)
                sp = input().strip()
                if sp == ">":
                    worst = test

        bad.remove(worst)

        nex = (worst + n) % (2 * n)
        if nex in good:
            good.remove(nex)
            bad.add(nex)

    query(best, worst)
    input() 

    print('!', flush = True)