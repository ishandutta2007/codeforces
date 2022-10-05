MOD = 998244353
BOUND = 19
 
n, m = map(int, input().split())
l = list(map(int,input().split()))
 
basis = []
for p in range(m-1,-1,-1):
    p2 = pow(2,p)
    nex = -1
    for i in range(n):
        if l[i] >= p2:
            nex = l[i]
            break
    if nex != -1:
        basis.append(nex)
        for i in range(n):
            if l[i] >= p2:
                l[i] ^= nex
        
extra = n - len(basis)

def add(a, b):
    out = [0] * (max(len(a), len(b)))
    for i in range(len(a)):
        out[i] = a[i]
    for i in range(len(b)):
        out[i] += b[i]
        out[i] %= MOD
    return out
    
 
def addSh(a, b):
    out = [0] * (max(len(a) + 1, len(b)))
    for i in range(len(a)):
        out[i + 1] = a[i]
    for i in range(len(b)):
        out[i] += b[i]
        out[i] %= MOD
    return out
 
i = 0
curr = dict()
curr[0] = [1]
for p in range(m-1,-1,-1):
    p2 = pow(2,p)
    if i < len(basis) and basis[i] >= p2:
        currN = dict(curr)
        for v in curr:
            if v ^ basis[i] not in currN:
                currN[v ^ basis[i]] = [0]
            currN[v ^ basis[i]] = add(curr[v], currN[v ^ basis[i]])
        curr = currN
        i += 1
 
    currN = dict(curr)
    for v in curr:
        if v >= p2:
            if v ^ p2 not in currN:
                currN[v ^ p2] = [0]
            currN[v ^ p2] = addSh(curr[v], currN[v ^ p2])
            del currN[v]
    curr = currN  
 
out = curr[0]
while len(out) < m + 1:
    out.append(0)
for i in range(m + 1):
    out[i] *= pow(2, extra, MOD)
    out[i] %= MOD
print(' '.join(map(str,out)))