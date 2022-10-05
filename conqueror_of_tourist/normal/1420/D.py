import sys,os,io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

MOD = 998244353


MAX = 5 * 10 ** 5 + 5

fact = [1]
for i in range(1, MAX + 1):
    new = fact[-1] * i
    fact.append(new % MOD)

invL = pow(fact[MAX],MOD-2,MOD)
factInv = [invL] * (MAX + 1)
for i in range(MAX - 1, -1, -1):
    old = factInv[i + 1]
    new = old * (i  + 1)
    factInv[i] = new % MOD

def choose(a,b):
    if a < b:
        return 0
    res = fact[a]
    res *= factInv[b]
    res %= MOD
    res *= factInv[a - b]
    res %= MOD
    return res
    

n, k = map(int, input().split())
events = []
for i in range(n):
    s, e = map(int, input().split())
    events.append(2*s+0)
    events.append(2*e+1)
    
events.sort()
count = 0
out = 0
for t in events:
    if t&1== 0:
        out += choose(count, k - 1)
        count += 1
        out %= MOD
    else:
        count -= 1

print(out)