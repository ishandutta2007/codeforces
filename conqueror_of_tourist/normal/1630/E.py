import sys
from math import gcd

input = sys.stdin.readline

MOD = 998244353

def mod_mul(x, y, c = 0):
    return (x * y + c) % MOD

def inv(x):
    return pow(x, MOD - 2, MOD)

MAX = 10 ** 6 + 100

fact = [1]
for i in range(1, MAX):
    fact.append(mod_mul(i, fact[i-1]))

invfact = [1] * (MAX)
invfact[MAX - 1] = inv(fact[MAX - 1])
for i in range(MAX - 2, -1, -1):
    invfact[i] = mod_mul(i + 1, invfact[i+1])

def invsmol(x):
    return mod_mul(fact[x - 1], invfact[x])

out = []
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    ct = [0] * n
    for v in a:
        ct[v - 1] += 1

    ct = [v for v in ct if v]

    if len(ct) == 1:
        out.append(1)
        continue

    g = ct[-1]
    for v in ct:
        g = gcd(g, v)

    shift = [0] * (n + 1)
    for i in range(1, n + 1):
        shift[gcd(i, n)] += 1

    oo = 0
    tot = 0

    avg = 0
    for v in ct:
        avg += mod_mul(v, n - v)

    for i in range(n + 1):
        if shift[i] == 0:
            continue

        rep = n // i

        if g % rep:
            continue

        #cts = [v // rep for v in ct]

        t_num = mod_mul(fact[n // rep], shift[i])
        t_den = 1
        for v in ct:
            t_den = mod_mul(t_den, fact[v // rep])
        amt = mod_mul(t_num, inv(t_den))

        avg_c = mod_mul(avg, invsmol(n - rep))

        oo += mod_mul(avg_c, amt)
        tot += amt

        oo %= MOD
    tot %= MOD

    out.append(mod_mul(oo, inv(tot)))

print('\n'.join(map(str, out)))