for _ in range(int(input())):
	t, x = input().split()
	h, m = t.split(':')
	ans = set()
	for i in range(24 * 60):
		time = (int(h) * 60 + int(m) + int(x) * i) % (24 * 60)
		s = "%02d:%02d" % (time / 60, time % 60)
		if s == s[::-1]:
			ans.add(s)
	print(len(ans))