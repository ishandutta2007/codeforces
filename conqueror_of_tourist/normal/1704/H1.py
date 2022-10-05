import sys
input = sys.stdin.readline

from functools import lru_cache

k, M = map(int, input().split())

MOD = M

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
    assert 0 <= y <= x
    
    return modmul(fact[x], modmul(invfact[y], invfact[x - y]))

def invcomb(x, y):
    return modmul(invfact[x], modmul(fact[y], fact[x - y]))

def invs(x):
    return modmul(fact[x - 1], invfact[x])


def count(a, b):
    if a + b == 0:
        return 1
    return modmul(a, fact[a + b - 1])
    
n = k

pn1 = [1]
for i in range(5000):
    pn1.append(modmul(pn1[-1], n - 1))

out = 0
for i in range(1, n):
    
    pni = [1]
    for _ in range(5000):
        pni.append(modmul(pni[-1], n - i))
        
    for j in range(i + 1):
        if n - i - j < 0:
            continue
        
        stab = comb(n, i)
        app = modmul(comb(i, j), comb(n - i, n - i - j))
        order = count(j, n - i - j)
        sao = modmul(modmul(stab, app), order)
        #sao = 1

        #u1 = pow(n - i, i - j, M)
        #u2 = pow(n - 1, j, M)
        u1 = pni[i - j]
        u2 = pn1[j]
        u = modmul(u1, u2)
        #u = 1

        #print(i, j, stab, app, order, u1, u2)
        
        out += modmul(sao, u)

print(out % M)