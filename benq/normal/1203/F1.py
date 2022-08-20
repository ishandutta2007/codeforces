from math import *

def nextInt():
    return int(input())

def nextInts():
    return list(map(int,input().split()))

def YN(x):
    return "YES" if x else "NO"

def solve():
    n,r = nextInts()
    pos = []
    neg = []
    for i in range(n):
        a,b = nextInts()
        a = max(a,-b)
        if b >= 0:
            pos.append((a,b))
        else:
            neg.append((a,b))
    pos.sort(key = lambda x:x[0])
    neg.sort(key = lambda x:-(x[0]+x[1]))
    for t in pos:
        if r < t[0]:
            return False
        r += t[1]
    for t in neg:
        if r < t[0]:
            return False
        r += t[1]
    return True

print(YN(solve()))

# q = nextInt()
# for i in range(q):
#     print("YES" if solve() else "NO")