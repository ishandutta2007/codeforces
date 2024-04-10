n, m, k = map(int, input().split())
t = 1
n -= 1
for i in range(n - k + 1, n + 1):
	t *= i
for j in range(1, k + 1):
	t //= j
for i in range(k):
	t *= (m - 1)
	t %= 998244353
print(m * t % 998244353)