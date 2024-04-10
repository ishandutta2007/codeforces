from math import *

MOD = int(1e9)+7

def nextInt():
    return int(input())

def nextInts():
    return list(map(int,input().split()))

def YN(x):
    return "YES" if x else "NO"

cum = None
n,k = 0,0

def addRect(x0,x1,y0,y1):
    global cum,n,k
    x0 = max(x0,0)+1
    x1 = min(x1,n-k)+1
    y0 = max(y0,0)+1
    y1 = min(y1,n-k)+1
    #print("HA",x0,x1,y0,y1)
    if x0 > x1 or y0 > y1:
        return
    #print("BEF",x0,x1,cum[1][1])
    cum[x0][y0] += 1
    #print("??",cum[1][1])
    cum[x1+1][y0] -= 1
    #print("??",x1+1,y0,cum[1][1],len(cum))
    cum[x0][y1+1] -= 1
    #print("??",cum[1][1])
    cum[x1+1][y1+1] += 1
    #print("??",cum[1][1])
    #print("AFT",cum[1][1])

def solve():
    global cum,n,k
    n,k = nextInts()
    L = []
    cum = [[0]*2005 for x in range(2005)]
    # print(cum[0])
    for i in range(n):
        L.append(input())
    for i in range(n):
        mn,mx = MOD,-MOD
        for j in range(n):
            if L[i][j] == 'B':
                mx = j
                if mn == MOD:
                    mn = j
        if mn == MOD:
            cum[1][1] += 1
            continue
        #print(i,mn,mx,mx-k+1,mn)
        addRect(i-k+1,i,mx-k+1,mn)
    for j in range(n):
        mn,mx = MOD,-MOD
        for i in range(n):
            if L[i][j] == 'B':
                mx = i
                if mn == MOD:
                    mn = i
        if mn == MOD:
            cum[1][1] += 1
            continue
        #print(j,mn,mx)
        addRect(mx-k+1,mn,j-k+1,j)
    ans = 0
    for i in range(1,n+1):
        for j in range(1,n+1):
            cum[i][j] += cum[i][j-1]+cum[i-1][j]-cum[i-1][j-1]
            #print("HUH",i,j,cum[i][j])
            ans = max(ans,cum[i][j])
    return ans

print(solve())
# t = nextInt()
# for i in range(t):
#     print(YN(solve()))