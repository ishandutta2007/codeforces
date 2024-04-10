MOD = 10**9 + 7

a = raw_input()
b = input()
allpos = pow(2, len(a), MOD)
c = (pow(allpos, b, MOD) - 1) * pow(allpos - 1, MOD - 2, MOD)
c %= MOD

res = 0

for i, x in enumerate(a):
    if x == '0' or x == '5':
        res += c * pow(2, i, MOD)
        res %= MOD

print res