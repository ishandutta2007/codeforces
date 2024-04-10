import sys
import math
import random
import time
from decimal import *

line = lambda: list(int(x) for x in input().split())
MOD = int(1e9 + 7)

def solve():
    x, y = line()
    fx = math.log(x) / x
    fy = math.log(y) / y
    if fx > fy:
        print(">")
    else:
        if fx < fy:
            print("<")
        else:
            print("=")

st = time.time()
solve()
##print("\nTime elapsed: %dms" % int(1000 * (time.time() - st)))
exit(0)