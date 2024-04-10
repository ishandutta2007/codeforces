n, MOD = map(int, input().split())

pascal = [[1]]
for _ in range(500):
    nl = [1]
    for i in range(_):
        nl.append((pascal[-1][i] + pascal[-1][i+1]) % MOD)
    nl.append(1)
    pascal.append(nl)

mod_mul = lambda x, y: (x * y) % MOD

import __pypy__

int_add = __pypy__.intop.int_add
int_sub = __pypy__.intop.int_sub
int_mul = __pypy__.intop.int_mul


def make_mod_mul(mod=MOD):
    fmod_inv = 1.0 / mod

    def mod_mul(a, b, c=0):
        res = int_sub(int_add(int_mul(a, b), c), int_mul(mod, int(fmod_inv * a * b + fmod_inv * c)))
        if res >= mod:
            return res - mod
        elif res < 0:
            return res + mod
        else:
            return res

    return mod_mul


mod_mul = make_mod_mul()


def mod_pow(x, y):
    if y == 0:
        return 1
    res = 1
    while y > 1:
        if y & 1 == 1:
            res = mod_mul(res, x)
        x = mod_mul(x, x)
        y >>= 1
    return mod_mul(res, x)


base = [0] * (n + 1)

dp = []
for i in range(n):
    nex = base[:]
    nex[1] = mod_pow(2, i)
    for j in range(i - 1):
        bl = i-j-1
        assert bl > 0
        mul = mod_pow(2, bl - 1)
        for k in range(n):
            ct = 2 + j - k
            if ct < 0:
                assert dp[j][k] == 0
                continue
            mulr = mod_mul(mul, pascal[bl+ct][ct])
            nex[k+1] += mod_mul(mulr, dp[j][k])
            nex[k+1] %= MOD
    dp.append(nex)
print(sum(dp[-1]) % MOD)