import random
import math

def gcd(a, b) :
    if (a == 0) :
        return b
    else :
        return gcd(b % a, a)

n = int(input())
S = []
for T in range(50) :
    x = random.randint(1, n - 1)
    print("sqrt %d" % (x * x % n))
    x0 = int(input())
    # x0 = -1
    # for i in range(n) :
    #     if (i * i % n == x * x % n) :
    #         x0 = i
    if (x != x0 and x0 != -1 and (x - x0 + n) % n != 0 and (x + x0) % n != 0) :
        S.append((x - x0 + n) % n)
        S.append((x + x0) % n)
# print(*S)
ans = []
while (n != 1) :
    p = n
    for i in range(len(S)) :
        tp = gcd(p, S[i])
        if (tp != 1) :
            p = tp
    for i in range(len(S)) :
        while (S[i] % p == 0) :
            S[i] //= p
    while (n % p == 0) :
        n //= p
    ans.append(p)
print("!", len(ans), *ans)