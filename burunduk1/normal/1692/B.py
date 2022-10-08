from collections import Counter

for _ in range(int(input())):
	input()
	s = [0] * 2
	r = Counter(map(int, input().split()))
	for t in r:
		s[r[t] & 1] += 1
	print(s[1] + s[0] - s[0] % 2)