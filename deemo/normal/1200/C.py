import math
n, m, q = map(int, input().split(" "))
g = math.gcd(n, m)
l = n*m // g
for i in range(q):
    sx, sy, ex, ey = map(int, input().split(" "))
    sy -= 1
    ey -= 1
    if sx == 1:
        sy *= m
    else:
        sy *= n
    if ex == 1:
        ey *= m
    else:
        ey *= n
    if sy // l == ey // l:
        print("YES")
    else:
        print("NO")