n = input()

res = []
for x in xrange(30, -1, -1):
	if (n & (1 << x)):
		res += [x+1]

print " ".join(map(str, res))