from math import *

MOD = int(1e9)+7

def nextInt():
    return int(input())

def nextInts():
    return list(map(int,input().split()))

def YN(x):
    return "YES" if x else "NO"

n,m,g,q = (0,0,0,0)

def comp(x,y):
    global n,m,g
    y -= 1
    if x == 1:
        return y//(n//g)
    else:
        return y//(m//g)

def solve():
    global n,m,g,q
    n,m,q = nextInts()
    g = gcd(n,m)
    # print(n//g,m//g)
    for i in range(q):
        sx,sy,ex,ey = nextInts()
        if comp(sx,sy) == comp(ex,ey):
            print("YES")
        else:
            print("NO")


solve()

# t = nextInt()
# for i in range(t):
#     print(YN(solve()))