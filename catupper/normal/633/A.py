a, b, c = map(int, raw_input().split())

for x in xrange(20000):
	if (c - a * x) % b == 0 and c - a * x >= 0:
		print "Yes"
		exit(0)

print "No"
exit(0)