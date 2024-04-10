MOD = 998244353

fact = [1]
curr = 1
for i in range(1, 6 * 10 ** 5):
    curr *= i
    curr %= MOD
    fact.append(curr)

def inv(x):
    return pow(x, MOD - 2, MOD)

n, k = map(int, input().split())
out = 0
for i in range(1, n + 1):
    count = n // i - 1
    if count >= k - 1:
        binom = fact[count]
        binom *= inv(fact[k - 1])
        binom %= MOD
        binom *= inv(fact[count - k + 1])
        binom %= MOD
        out += binom
        out %= MOD
print(out)