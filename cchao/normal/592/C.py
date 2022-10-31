def gcd(a, b):
	if a % b == 0:
		return b
	return gcd(b, a % b)

def lcm(a, b):
	return a / gcd(a, b) * b

t, w, b = map(int, raw_input().split())
l = lcm(w, b)
a = (t / l + 1) * min(w, b) - 1
tmp = l * (t / l) + min(w, b) - 1
if tmp > t:
	a = a - (tmp - t)


if a == 0:
	print "0/1"
else:
	g = gcd(a, t)
	a = a / g
	t = t / g
	print str(a) + "/" + str(t)