MOD = 998244353

n = int(input())

a = list(map(int, input().split()))
tot = sum(a)

def inv(x):
    return pow(x, MOD - 2, MOD)

l = [0, pow(n, tot, MOD) - 1]

for i in range(1, tot):
    aC = i
    cC = (n - 1) * (tot - i)
    curr = (aC + cC) * l[-1]
    curr -= tot * (n - 1)
    curr -= aC * l[-2]
    curr *= inv(cC)
    curr %= MOD
    l.append(curr)

out = 0
for v in a:
    out += l[tot - v]
    out %= MOD

zero = l[tot]
out -= (n - 1) * zero
out *= inv(n)
print(out % MOD)