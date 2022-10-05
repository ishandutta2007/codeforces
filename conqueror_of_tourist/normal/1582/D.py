from math import gcd, log

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    g = abs(a[0])
    for v in a:
        g = gcd(abs(v), g)
    out = [0] * n
    out[0] += a[1]
    out[1] -= a[0]
    seen = dict()
    seen[a[0]] = 0
    seen[a[1]] = 1
    for i in range(2, n):
        if a[i] in seen:
            while out[i] == 0 or out[seen[a[i]]] == 0:
                out[i] += 1
                out[seen[a[i]]] -= 1
        else:
            while out[i] == 0 or out[i - 1] == 0:
                out[i] += a[i - 1]
                out[i - 1] -= a[i]
        seen[a[i]] = i
    print(' '.join(map(str,out)))