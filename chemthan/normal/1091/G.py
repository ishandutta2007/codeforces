import sys
import math
import random
import time
from decimal import *

line = lambda: list(int(x) for x in input().split())
MOD = int(1e9 + 7)

def gcd(a, b):
    if b == 0:
        return a;
    return gcd(b, a % b)

def solve():
    n = int(input())
    res = []
    res.append(n)
    numfail = 0
    while numfail < 20:
        numfail += 1
        x = random.randrange(0, n)
        print("sqrt " + str(x * x % n))
        sys.stdout.flush()
        y = int(input())
        if (x != y and x + y != n):
            nres = []
            for z in res:
                g = gcd(x - y, z)
                if (1 < g and g < z):
                    numfail = 0
                    nres.append(g)
                    nres.append(z // g)
                else:
                    g = gcd(x + y, z)
                    if (1 < g and g < z):
                        numfail = 0
                        nres.append(g)
                        nres.append(z // g)
                    else:
                        nres.append(z)
            res = nres
    print("! " + str(len(res)), end = '')
    for x in res:
        print(" " + str(x), end = '')
    print("");
    sys.stdout.flush()

st = time.time()
solve()
##print("\nTime elapsed: %dms" % int(1000 * (time.time() - st)))
exit(0)