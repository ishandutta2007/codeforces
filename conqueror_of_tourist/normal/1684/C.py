import sys
input = sys.stdin.readline

out = []

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())

    b = []
    for _ in range(n):
        b.append(list(map(int, input().split())))

    bad = [0] * m

    for l in b:
        sl = sorted(l)

        for i in range(m):
            if l[i] != sl[i]:
                bad[i] = 1

    if sum(bad) == 0:
        out.append('1 1')
    elif sum(bad) == 2:
        vals = []
        for i in range(m):
            if bad[i]:
                vals.append(i)

        i, j = vals[0], vals[1]
        good = True
        for l in b:
            l[i], l[j] = l[j], l[i]

            good &= (l == sorted(l))

        if good:
            out.append(f'{i + 1} {j + 1}')
        else:
            out.append('-1')
    else:
        out.append('-1')

print('\n'.join(out))