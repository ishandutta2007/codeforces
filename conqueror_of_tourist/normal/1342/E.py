MOD = 998244353

def inv(x):
    return pow(x,MOD - 2, MOD)

n, k = map(int, input().split())
if k >= n:
    print(0)
else:
    out = 0
    col = n - k 
    binom = 1
    mult = 1
    for i in range(n, col, -1):
        mult *= i
        mult *= inv(n + 1 - i)
        mult %= MOD
        
    for i in range(col, 0, -1):
        out += binom * pow(i, n, MOD)
        out %= MOD
        binom *= i
        binom *= inv(col + 1 - i)
        binom *= -1
        binom %= MOD

    out *= mult

    if k > 0:
        out *= 2
    print(out % MOD)