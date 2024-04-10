def can(x):
    a2 = min(a, x)
    b2 = min(b, x)
    if(n < k):
        return 0
    else:
        return min(x, (a2 * ((n + 1) // 2) + b2 * (n // 2)) // k) >= x

t, n, a, b, k = map(int, input().split())

lf = 0
rg = t + 1
while(rg - lf > 1):
    mid = (lf + rg) // 2
    if(can(mid)):
        lf = mid
    else:
        rg = mid

print(lf)