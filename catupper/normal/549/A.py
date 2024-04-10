n, m = map(int, raw_input().split())

letters = [raw_input() for x in xrange(n)]
	
res = 0
for x in xrange( n - 1):
	for y in xrange(m - 1):
		a = letters[x][y] + letters[x][y+1] + letters[x+1][y] + letters[x+1][y+1]
		if 'f' in a and 'a' in a and 'c' in a and 'e' in a:
			res += 1
			
print res