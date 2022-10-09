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

n, l, r = map(int, input().split())

ans = [1, 0, 0]
cnt = [r // 3 - (l - 1) // 3, (r + 2) // 3 - (l + 1) // 3, (r + 1) // 3 - l // 3]

for i in range(n):
    newans = [0, 0, 0]
    for j in range(3):
        for k in range(3):
            newans[(j + k) % 3] = add(newans[(j + k) % 3], mul(cnt[k], ans[j]))
    ans = newans

print(ans[0])