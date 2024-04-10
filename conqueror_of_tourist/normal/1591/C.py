import sys
input = sys.stdin.readline

oo = []
t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    x = list(map(int, input().split()))

    pos = []
    neg = []

    for v in x:
        if v > 0:
            pos.append(v)
        if v < 0:
            neg.append(-v)

    out = []

    for l in [pos, neg]:
        l.sort(reverse = True)

        for v in l[0::k]:
            out.append(v)
    
    if len(out) == 0:
        oo.append(0)
        continue

    out.sort()
    oo.append(2*sum(out) - out[-1])
print('\n'.join(map(str,oo)))