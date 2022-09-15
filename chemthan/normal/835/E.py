import sys
import math
import random
import time
import decimal

line = lambda: list(int(x) for x in input().split())
MOD = int(1e9 + 7)
n = 0
x = 0
y = 0

def ask(ar):
    if len(ar) == 0:
        return 0
    print("? ", end = '')
    print(len(ar), end = '')
    for i in range(len(ar)):
        print(" %d" % (ar[i] + 1), end = '')
    print("")
    sys.stdout.flush()
    return int(input())

def get(ar):
    lo = 0
    hi = len(ar) - 1
    while lo < hi:
        mi = lo + hi >> 1
        tmp = 0
        if (mi & 1) == 0:
            tmp = x
        if ask(ar[0 : mi + 1]) == tmp:
            lo = mi + 1
        else:
            hi = mi
    return ar[lo + hi >> 1]

def solve():
    global n, x, y
    n, x, y = line()
    res = [0 for i in range(0, 10)]
    tmp = [0 for i in range(0, 10)]
    a = -1
    b = 0
    for k in range(0, 10):
        ar = []
        for i in range(n):
            if ((i >> k) & 1) == 1:
                ar.append(i)
        if (len(ar) & 1) == 1:
            tmp[k] = x
        res[k] = ask(ar)
        if a == -1 and res[k] != tmp[k]:
            a = get(ar)
    for k in reversed(range(0, 10)):
        b <<= 1
        if res[k] == tmp[k]:
            b |= (a >> k) & 1
        else:
            b |= ((a >> k) & 1) ^ 1
    if a > b:
        a, b = b, a
    print("! %d %d" % (a + 1, b + 1))
    sys.stdout.flush()

##st = time.time()
solve()
##print("Time elapsed: %.3fs" % (time.time() - st))
exit(0)