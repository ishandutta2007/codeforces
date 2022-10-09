mod = 998244353

def add(x, y):
    global mod
    return (x + y) % mod

def sub(x, y):
    global mod
    return ((x - y) % mod + mod) % mod

def mul(x, y):
    global mod
    return (x * y) % mod

def binpow(x, y):
    global mod
    if y == 0:
        return 1
    elif y % 2 == 0:
        z = binpow(x, y // 2)
        return mul(z, z)
    else:
        return mul(binpow(x, y - 1), x)

def divide(x, y):
    global mod
    return mul(x, binpow(y, mod - 2))

N = 2000

C = [[0 for i in range(N + 1)] for j in range(N + 1)]
for i in range(N):
    C[i][0] = 1
    C[i][i] = 1
    for j in range(1, i):
        C[i][j] = add(C[i - 1][j], C[i - 1][j - 1])

n, m, k = map(int, input().split())
print(mul(mul(C[n - 1][k], m), binpow(sub(m, 1), k)))