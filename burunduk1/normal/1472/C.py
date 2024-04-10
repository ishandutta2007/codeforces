t = int(input())
for _ in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	res = 0
	s = [0] * n # s[i]
	for i in range(n)[::-1]:
		s[i] = a[i]
		if i + a[i] < n:
			s[i] += s[i + a[i]] # i+a[i] > i
		res = max(res, s[i])
	print(res)