N = 300100
prime = [1]*N

prime[0] = 0
prime[1] = 0

for i in range(2, N):
    if(prime[i]):
        for j in range(i*2, N, i):
            prime[j] = 0

MOD = 998244353

def binpow(a, b):
    res = 1
    while(b > 0):
        if(b % 2): 
            res = res * a % MOD
        a = a * a % MOD
        b //= 2
    return res

n, m = map(int, input().split())

total = 0

for i in range(1, n + 1):
    total = (total + binpow(m, i)) % MOD

product = 1
add = 1

for i in range(1, n + 1):
    if(prime[i]):
        product *= i
    if(product > m):
        break
    add *= m//product
    add %= MOD
    total = (total - add + MOD) % MOD

print(total)