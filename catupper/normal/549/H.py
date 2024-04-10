a, b = map(int, raw_input().split())
c, d = map(int, raw_input().split())

if a * d - b * c == 0:
	print 0
	exit(0)

bottom = 0.0
top = 10**9


def mmi(x, y, z, w):
	return min(x * z, x * w, y * z, y * w)

def mma(x, y, z, w):
	return max(x * z, x * w, y * z, y * w)


def able(val):
	ll = mmi(a - val, a + val, d - val, d + val)
	rr = mma(a - val, a + val, d - val, d + val)
	pp = mmi(b - val, b + val, c - val, c + val)
	qq = mma(b - val, b + val, c - val, c + val)
	if(ll <= rr < pp <= qq or pp <= qq < ll <= rr):
		return False
	else:
		return True

for x in xrange(200):
	mid = (bottom + top) / 2
	if(able(mid)):top = mid
	else: bottom = mid

print "%.19lf"%top