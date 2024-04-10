MOD = 998244353 

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

n, m = map(int, input().split())

pascal = [[1]]
for _ in range(n + m + 5):
    nl = [1]
    for i in range(_):
        nl.append((pascal[-1][i] + pascal[-1][i+1]) % MOD)
    nl.append(1)
    pascal.append(nl)

def s1(n,m):
    out = 0
    for row in range(1, n):
        above = row
        below = n - row

        bottom = []
        for i in range(m):
            a = below - 1
            b = i
            a2 = below
            b2 = m-i-1
            bottom.append(mod_mul(pascal[a+b][a] , pascal[a2+b2][a2]))

        top = []
        for i in range(m):
            a = above - 1
            b = i
            a2 = above
            b2 = m-i-1
            top.append(mod_mul(pascal[a+b][a] , pascal[a2+b2][a2]))
        top.reverse()

        curr = 0
        for i in range(m):
            out += mod_mul(curr,bottom[i])
            curr += top[i]
            curr %= MOD
            out %= MOD
    return out * 2

def s2(n,m):
    o = 0
    for i in range(1,n):
        for j in range(1,m):
            a = pascal[i+j-1][i-1]
            b = pascal[n-i+j-1][n-i]
            c = pascal[n-i-1+m-j][m-j]
            d = pascal[i+m-j-1][i]
            #print(a,b,c,d)
            o += mod_mul(mod_mul(a,b),mod_mul(c,d))
    return o
    

c1 = s1(n,m)
c2 = s1(m,n)
c3 = s2(n,m)

out = (c1 + c2 - 2*c3) % MOD
print(out)