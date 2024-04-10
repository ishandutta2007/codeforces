MOD = 998244353

fact = [0] * (10 ** 6 + 2)
for i in range(1, 10 ** 6 + 2):
    for j in range(i, 10 ** 6 + 2, i):
        fact[j] += 1

out = [0]
curr = 0
for i in range(1, 10 ** 6 + 1):
    out.append((curr + fact[i]) % MOD)
    curr += out[-1]
    curr %= MOD

n = int(input())
print(out[n])