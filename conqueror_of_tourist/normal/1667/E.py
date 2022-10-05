MOD = 998244353

def modmul(x, y, c = 0):
    return (x * y + c) % MOD

def inv(x):
    return pow(x, MOD - 2, MOD)

MAX = 10 ** 6

fact = [1]
for i in range(1, MAX):
    fact.append(modmul(i, fact[i-1]))

invfact = [1] * (MAX)
invfact[MAX - 1] = inv(fact[MAX - 1])
for i in range(MAX - 2, -1, -1):
    invfact[i] = modmul(i + 1, invfact[i+1])

def comb(x, y):
    return modmul(fact[x], modmul(invfact[y], invfact[x - y]))
    
def invcomb(x, y):
    return modmul(invfact[x], modmul(fact[y], fact[x - y]))
    
def invs(x):
    return modmul(fact[x - 1], invfact[x])

n = int(input())

out = [0] * n

for i in range((n + 1) // 2):
    base = fact[n - 1]
    frac = modmul(comb(n//2, i), invcomb(n - 1, i))
    
    out[i] = modmul(base, frac)

rem = 0   
for i in range(n - 1, -1, -1):
    oldrem = rem
    rem += modmul(out[i], invs(i))
    out[i] -= oldrem
    
    rem %= MOD
    out[i] %= MOD
    
print(' '.join(map(str,out)))