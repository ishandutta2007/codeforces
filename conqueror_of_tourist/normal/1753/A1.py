import sys
input = sys.stdin.readline

def p(x):
    if x % 2:
        return -1
    return 1

t = int(input())
out = []
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    imp = []
    for i in range(n):
        if a[i] != 0:
            imp.append(i)

    if len(imp) % 2 == 1:
        out.append('-1')
        continue

    curr = []


    if imp[0] != 0:
        curr.append(f' 1 {imp[0]}')

    z = len(imp)
    imp.append(n)
    for u in range(z // 2):
        i = imp[2 * u]
        j = imp[2 * u + 1]
        k = imp[2 * u + 2]

        if a[j] * p(j - i) + a[i] == 0:
            curr.append(f'{i + 1} {k}')
        else:
            curr.append(f'{i + 1} {i + 1}')
            curr.append(f'{i + 2} {k}')

    out.append(str(len(curr)))
    for s in curr:
        out.append(s)

print('\n'.join(out))