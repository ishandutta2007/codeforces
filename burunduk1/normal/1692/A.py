t = int(input())
for _ in range(t):
	a, b, c, d = map(int, input().split())
	print((b > a) + (c > a) + (d > a))