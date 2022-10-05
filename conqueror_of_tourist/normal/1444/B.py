n = int(input())
l = sorted(map(int, input().split()))
tot = sum(l[n:]) - sum(l[:n])
MOD = 998244353
fact = [1]
for i in range(1, 2 * n + 1):
    fact.append((fact[-1] * i) % MOD)
tot *= fact[2 * n]
inv = pow(fact[n], MOD-3, MOD)
tot *= inv
print(tot % MOD)