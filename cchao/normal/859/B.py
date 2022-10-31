n = input()
print min(x + (n + x - 1) / x for x in xrange(1, n + 1)) * 2