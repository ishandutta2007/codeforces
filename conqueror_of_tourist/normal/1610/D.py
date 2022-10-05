MOD = 10 ** 9 + 7

n = int(input())
a = list(map(int, input().split()))

p2 = [0] * 50
for v in a:
    ct = 0
    while v % 2 == 0:
        ct += 1
        v //= 2
    p2[ct] += 1

out = pow(2, n, MOD) - 1
for i in range(1, 40):
    curr = p2[i]
    res = sum(p2[i+1:])
    bad = 0 if curr == 0 else pow(2, curr - 1, MOD)
    out -= bad * pow(2, res, MOD)
print(out % MOD)