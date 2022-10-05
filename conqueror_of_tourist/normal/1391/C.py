MOD = 10 ** 9 + 7

out = 1

n = int(input())

for i in range(n):
    out *= (i + 1)
    out %= MOD
out -= pow(2, n - 1, MOD)
print(out % MOD)