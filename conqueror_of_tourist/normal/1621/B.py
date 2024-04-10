import sys
input = sys.stdin.readline

out = []
t = int(input())
for _ in range(t):
    n = int(input())

    l = (10 ** 10, 0)
    r = (-10 ** 10, 0)

    seen = dict()

    for i in range(n):
        li, ri, ci = map(int, input().split())
        if (li, ri) not in seen:
            seen[(li, ri)] = 10 ** 10
        seen[(li, ri)] = min(seen[(li, ri)], ci)

        l = min(l, (li, ci))
        r = max(r, (ri, -ci))

        p = [l[1] - r[1]]
        if (l[0], r[0]) in seen:
            p.append(seen[(l[0], r[0])])
        out.append(min(p))
    
print('\n'.join(map(str,out)))