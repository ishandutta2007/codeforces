def solve():
	k = 1
	s = set()
	for c in input():
		if len(s | set(c)) > 3:
			k += 1
			s.clear()
		s.add(c)
	print(k)

tn = int(input())
for _ in range(tn):
	solve()