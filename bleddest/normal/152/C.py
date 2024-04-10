mod = 10 ** 9 + 7

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

n, m = map(int, input().split())
s = []
for i in range(n):
    s.append(input())

ans = 1
for i in range(m):
    t = set()
    for j in range(n):
        t.add(s[j][i])
    ans = mul(ans, len(t))

print(ans)