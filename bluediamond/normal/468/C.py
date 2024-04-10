import random

def g(x):
    return x * (x + 1) // 2

def smart(x):
    #g(9) * 10 * (x / 100) + (if u2 cif > 0) g(u2 cif - 1) * 10 + (u2cif) * ((x % 10) + 1)  

    nr = x
    sol = 0
    p10 = 1
    while nr > 0:
        cif = nr % 10
        
        sol += g(9) * p10 * (x // (p10 * 10))
        if cif > 0: 
            sol += g(cif - 1) * p10
            sol += cif * ((x % p10) + 1)
        nr //= 10
        p10 *= 10
    return sol
    

def fnd(limit):
    l, r = 0, limit
    sol = -1
    while l <= r:
        mid = (l + r) // 2
        if smart(mid) <= limit:
            sol = mid
            l = mid + 1
        else:
            r = mid - 1
    assert sol != -1
    return sol

a = int(input())
cur = a
while True:
    x = fnd(cur)
    if smart(x) == cur:
        print(1, x)
        exit(0)
    cur += a