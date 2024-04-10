import sys,io,os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
M = 998244353
def solve():
    ret = 1
    n, k = map(int, input().split())
    l = list(map(lambda x: int(x) - 1, input().split()))
    left = [-1] * n
    right = [-1] * n
    for i in range(n-1):
        left[l[i+1]] = l[i]
        right[l[i]] = l[i+1]

    useable = [1] * n
    b = list(map(lambda x: int(x) - 1, input().split()))
    for v in b:
        useable[v] = 0

    for v in b:
        useable[v] = 1
        if left[v] != -1:
            lposs = useable[left[v]]
        else:
            lposs = 0

        if right[v] != -1:
            rposs = useable[right[v]]
        else:
            rposs = 0
            
        s = lposs + rposs
        if s == 0:
            return 0
        elif s == 2:
            ret *= 2
            ret %= M
            
        if lposs:
            d = left[v]
        else:
            d = right[v]

        l,r = left[d], right[d]
        if l != -1:
            right[l] = r
        if r != -1:
            left[r] = l

    return ret
    
    

t = int(input())
out = []
for _ in range(t):
    out.append(solve())

print('\n'.join(map(str,out)))