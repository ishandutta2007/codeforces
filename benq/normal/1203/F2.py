from math import *

MOD = int(1e9)+7

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
    ans = 0
    for t in pos:
        if r >= t[0]:
            r += t[1]
            ans += 1

    dp = [-MOD]*60001
    dp[r] = ans

    for t in neg:
        for j in range(t[0],60001):
            dp[j+t[1]] = max(dp[j+t[1]],dp[j]+1)
    return max(dp)

print(solve())

# q = nextInt()
# for i in range(q):
#     print(YN(solve()))