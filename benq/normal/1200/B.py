from math import *

MOD = int(1e9)+7

def nextInt():
    return int(input())

def nextInts():
    return list(map(int,input().split()))

def YN(x):
    return "YES" if x else "NO"

def solve():
    n,m,k = nextInts()
    h = nextInts()
    for i in range(n-1):
        m += h[i]
        m -= max(0,h[i+1]-k)
        if m < 0:
            return False
    return True

t = nextInt()
for i in range(t):
    print(YN(solve()))