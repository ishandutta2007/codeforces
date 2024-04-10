MOD = 998244353
n = int(input())
mult = pow(2, MOD-1-n, MOD)
a,b=0,1
for i in range(n):
    a,b = b, (a + b) % MOD
print((a * mult) % MOD)