n = int(raw_input())+1
mod=10**9+7
aa=1
for i in xrange(1, 2*n):
	aa = aa*i%mod
bb=1
for i in xrange(1, n+1):
	bb = bb*i%mod
cc = 1
for i in xrange(1, n):
	cc = cc*i%mod
def p(a,b):
	if b == 0:
		return 1
	t = p(a, b/2)
	t = t * t
	if b % 2 == 1:
		t = t * a
	return t % mod
print (2 * aa * p(bb*cc,mod-2) + mod - 1) % (mod)