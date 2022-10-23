MOD = 998244353

def modmul(x, y, c = 0):
    return (x * y + c) % MOD

mod_mul = modmul

def inv(x):
    return pow(x, MOD - 2, MOD)

MAX = 10 ** 5 + 10

fact = [1]
for i in range(1, MAX):
    fact.append(modmul(i, fact[i-1]))

invfact = [1] * (MAX)
invfact[MAX - 1] = inv(fact[MAX - 1])
for i in range(MAX - 2, -1, -1):
    invfact[i] = modmul(i + 1, invfact[i+1])

def comb(x, y):
    return modmul(fact[x], modmul(invfact[y], invfact[x - y]))

def perm(x, y):
    return modmul(fact[x], invfact[x - y])

def invcomb(x, y):
    return modmul(invfact[x], modmul(fact[y], fact[x - y]))

def invs(x):
    return modmul(fact[x - 1], invfact[x])


import sys
input = sys.stdin.readline

t = int(input())
out = []
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    high = sum(l)

    bad = 0
    for v in l[::-1][:high]:
        if v == 0:
            bad += 1

    tot = (n * n - n)//2
    
    r = 0
    for i in range(1, bad + 1):
        ii = invs(i)
        r += modmul(ii, ii)

    out.append(modmul(r, tot))
print('\n'.join(map(str, out)))