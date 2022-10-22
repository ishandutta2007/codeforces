n = input()

res = [99] * n

a = [map(int, raw_input().split()) for _ in xrange(n)]

done = [False] * 1000

for x in xrange(1, n+1):
	for y in xrange(n):
		ok = True
		if done[y]:continue
		for z in xrange(n):
			if a[y][z] > x:
				ok = False
				break
		if ok:
			done[y] = True
			res[y] = x
			break

print " ".join(map(str, res))