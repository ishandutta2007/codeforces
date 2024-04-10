for _ in range(int(input())):
	n, s = map(int, input().split())
	a = list(map(int, input().split()))
	ans = n + 1
	l, r = 0, 0
	while l < n:
		if s == 0:
			ans = min(ans, l + n - r)
		if s < 0 or r == n:
			s += a[l]
			l += 1
		else:
			s -= a[r]
			r += 1
	print(-1 if ans > n else ans)