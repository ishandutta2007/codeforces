from math import *

def nextInt():
    return int(input())

def nextInts():
    return list(map(int,input().split()))

def solve():
    n = nextInt()
    a = nextInts()
    res = 0
    for i in a:
        res = gcd(res,i)
    i = 1
    ans = 0
    while i*i < res:
        if res%i == 0:
            ans += 2
        i += 1
    if i*i == res:
        ans += 1
    return ans

print(solve())

# q = nextInt()
# for i in range(q):
#     print("YES" if solve() else "NO")