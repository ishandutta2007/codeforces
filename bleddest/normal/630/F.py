mod = 10 ** 30

def add(x, y):
    global mod
    return (x + y)

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

N = 777
C = [[0 for i in range(N + 1)] for j in range(N + 1)]
for i in range(N + 1):
    C[i][0] = 1
    C[i][i] = 1
    for j in range(1, i):
        C[i][j] = add(C[i - 1][j], C[i - 1][j - 1])

n = int(input())

print(add(add(C[n][5], C[n][6]), C[n][7]))