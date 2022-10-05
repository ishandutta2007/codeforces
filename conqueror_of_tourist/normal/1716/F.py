MOD = 998244353

def modmul(x, y, c = 0):
    return (x * y + c) % MOD

mod_mul = modmul

def inv(x):
    return pow(x, MOD - 2, MOD)

MAX = 10 ** 5

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

ster = [[1]]

for i in range(2010):
    curr = ster[-1]
    nex = [1]
    for j in range(i):
        nex.append(modmul(curr[j + 1], (j + 2), curr[j]))
    nex.append(curr[-1])
    ster.append(nex)

t = int(input())
for _ in range(t):
    m, n, k = map(int, input().split())

    out = 0
    a = (n + 1) // 2

    invn = inv(n)
    deriv = [pow(n, m, MOD)]
    for i in range(k + 5):
        deriv.append(modmul(deriv[-1], modmul(invn, modmul(m - i, a))))

    cs = ster[k - 1]

    for i in range(1, k + 1):
        out += cs[i - 1] * deriv[i]
        out %= MOD
        
    print(out)