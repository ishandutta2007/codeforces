from math import *

def nextInt():
    return int(input())

def nextInts():
    return list(map(int,input().split()))

def need(s,t):
    cur = 0
    res = [cur]
    for c in t:
        while s[cur] != c:
            cur += 1
        cur += 1
        res.append(cur)
    return res

def solve():
    s = input()
    t = input()
    x = need(s,t)
    s = "".join(reversed(s))
    t = t[::-1]
    y = need(s,t)
    ans = 1e9
    for i in range(len(x)):
        ans = min(ans,x[i]+y[len(x)-1-i])
    return len(s)-ans

print(solve())

# q = nextInt()
# for i in range(q):
#     print("YES" if solve() else "NO")