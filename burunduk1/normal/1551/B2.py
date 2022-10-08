def solve():
	n, k = map(int, input().split())
	cnt = [0] * (n+1)
	a = []
	for i, x in enumerate(map(int, input().split())):
		if cnt[x] < k:
			a.append((x, i))
		cnt[x] += 1
	a.sort()
	cc = 0
	color = [0] * n
	m = len(a) - len(a) % k
	for x, i in a[:m]:
		color[i] = cc + 1
		cc = (cc + 1) % k
	print(*color)

t = int(input())
for _ in range(t): solve()