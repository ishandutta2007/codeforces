a, b = map(int, input().split())

if (b - a < 15):
	ans = 1
	for i in range(a + 1, b + 1):
		ans *= max(i, 1)
		ans %= 10
	print(ans % 10)
else:
	print(0)