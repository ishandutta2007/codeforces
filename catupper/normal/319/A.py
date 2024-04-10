a = raw_input()
g = (1 << len(a))
MOD = 1000000007
res =(g * (g - 1) / 2) % MOD
for x in xrange(len(a)):
    if(a[x] == '1'):continue
    res -= pow(2, len(a) * 2 - x - 2 , MOD)
    res %= MOD

print( res + MOD) %MOD