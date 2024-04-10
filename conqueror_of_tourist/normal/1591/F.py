n = int(input())
a = list(map(int, input().split()))

MOD = 998244353

stack = [(a[0], 0)]

base = 1
mult = 1
total = a[0]
u = a[0]

def modmul(x, y):
    return (x * y) % MOD

for v in a[1:]:
    if v == u:
        base, mult, total = total - base, -mult, modmul(total, u - 1)
    elif v > u:
        oTot = total
        oBase = base
        base, mult, total = total - base, -mult, modmul(total, u - 1)

        stack.append(((v - u), mult * oBase))
        total += modmul(oTot, v - u)
    else:
        tRest = total
        while v < u:
            rem = u - v
            if rem >= stack[-1][0]:
                diff = stack.pop()
                u -= diff[0]
            else:
                sl, sr = stack.pop()
                stack.append((sl - rem, sr))
                diff = (rem, sr)
                u -= rem

            tVal = base + modmul(mult, diff[1])
            tRest = (tRest - modmul(diff[0], tVal)) % MOD
                        
            
        base, mult, total = total - base, -mult, modmul(total, u) - tRest

    #print(stack, base, mult, total)

    u = v

print(total % MOD)