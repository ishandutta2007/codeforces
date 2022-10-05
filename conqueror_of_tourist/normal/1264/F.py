fibM = [[1, 1], [1, 0]]

def mult(A, B):
    out = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            res = (A[i][0] * B[0][j] + A[i][1] * B[1][j]) % MOD
            out[i][j] = res
    return out

def powM(A, n):
    out = [[1, 0], [0, 1]]
    base = [l[:] for l in A]

    while n:
        if n % 2:
            out = mult(out, base)

        n //= 2
        base = mult(base, base)
        
    return out

MOD = 10 ** 18
dd = 300000000

def fibn(n):
    return powM(fibM, n)[1][0]


g = 0
from math import gcd
for i in range(1231):
    g = gcd(g, fibn(i) - 2 * fibn(i + dd) + fibn(i + 2 * dd))

#print(g, fibn(dd))

adv = powM(fibM, dd)

_, a, d = map(int, input().split())

curr = 12345
M = powM(fibM, curr)
for i in range(1, 7):
    want = pow(10, i)
    cd = [dd, dd, dd * 10, dd * 100, dd * 1000, dd * 10000, dd * 100000][i]
    mM = powM(fibM, cd)
    #print(want, M)
    while True:
        if (M[1][0]//(10 ** 11)) % want == a % want:
            break

        curr += cd
        M = mult(M, mM)

if _ == 1:
    print(curr, 1)
    exit()

na = curr
nec = M[1][0]

for i in range(11, 18):
    want = pow(10, i)
    cd = [dd, dd, dd * 10, dd * 100, dd * 1000, dd * 10000, dd * 100000][i - 11]
    adv = powM(fibM, cd)
    #print(curr, want, adv)
    while True:
        if (M[1][0]) % want == (nec + d * 10 ** 11) % want:
            break

        #print(((M[1][0] - (nec + d * 10 ** 11)) % want)/4000000000)

        curr += cd
        M = mult(M, adv)

print(na, curr - na)