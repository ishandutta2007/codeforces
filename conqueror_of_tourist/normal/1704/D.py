import sys
input = sys.stdin.readline

out = []
t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    c = []
    for _ in range(n):
        l = list(map(int, input().split()))
        v = 0
        for i in range(m):
            v += i * l[i]
        c.append(v)

    f3 = c[:3]
    med = sum(f3) - min(f3) - max(f3)

    for k in range(n):
        if c[k] != med:
            break

    out.append(f'{k + 1} {c[k] - med}')
    

print('\n'.join(map(str, out)))