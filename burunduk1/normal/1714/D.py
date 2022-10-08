for _ in range(int(input())):
	text = input()
	d = dict([(input(), i) for i in range(int(input()))])
	lens = set(map(lambda x : len(x), d))
	ans = []
	pos = 0
	while True:
		best = (-1, pos)
		for r in range(pos + 1, len(text) + 1):
			for rl in lens:
				l = max(0, r - rl)
				if l <= pos and text[l:r] in d: best = (l, r)
		if pos == best[1]:
			break
		l, r = best[0], best[1]
		pos = r
		ans.append((d[text[l:r]], l))
	if pos < len(text):
		print(-1)
		continue
	print(len(ans))
	for a, b in ans: print(a + 1, b + 1)