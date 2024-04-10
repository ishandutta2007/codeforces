def factor(n):
    out = []
    
    power = 0
    while n & 1 == 0:
        power += 1
        n >>= 1

    if power:
        out.append(2)
        power = 0

    test = 3
    while pow(test,2) <= n:
        while n % test == 0:
            power += 1
            n //= test
        if power:
            out.append(test)
            power = 0
        test += 2

    if n > 1:
        out.append(n)

    return out


x, n = list(map(int,input().split()))

M = 10 ** 9 + 7

f = factor(x)
out = 1
for p in f:
    newPower = 0
    nCopy = n
    while nCopy:
        nCopy //= p
        newPower += nCopy
    out *= pow(p,newPower,M)
    out %= M

print(out)