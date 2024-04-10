import math

def lcm(x, y):
    return (x * y)//math.gcd(x,y)

q = int(input())


for i in range(q):
    n = int(input())
    p = list(map(lambda x: int(x)//100,input().split()))
    p = sorted(p)
    x, a = map(int,input().split())
    y, b = map(int,input().split())
    k = int(input())

    if y > x:
        x, y = y, x
        a, b = b, a

    lo = 0 #Impossible
    hi = n + 1 #Possible (with fake large ticket)
    while hi - lo > 1:
        test = (lo + hi)//2
        best = p[::]

        both = test//lcm(a,b)
        anum = (test//a) - both
        bnum = (test//b) - both

        out = 0
        while best:
            if both > 0:
                out += (x + y) * best.pop()
                both -= 1
            elif anum > 0:
                out += (x) * best.pop()
                anum -= 1
            elif bnum > 0:
                out += (y) * best.pop()
                bnum -= 1
            else:
                break

        if out >= k:
            hi = test
        else:
            lo = test


    if hi == n+1:
        print(-1)
    else:
        print(hi)