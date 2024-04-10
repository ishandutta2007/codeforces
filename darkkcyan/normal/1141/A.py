from math import *
n, m = map(int, input().strip().split())
if m % n != 0:
    print(-1)
else:
    x = m // n
    u = gcd(x, 2**40)
    v = gcd(x, 3**40)
    if x // u // v != 1:
        print(-1)
    else:
        print(round(log(u) / log(2)) + round(log(v) / log(3)))