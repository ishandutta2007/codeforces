read = lambda: map(int, input().split())

T = int(input())

for t in range(T):
	n = int(input())
	a = list(read())
	sm, mx = sum(a), max(a)
	on = (sm + n - 2) // (n - 1)
	print(max(mx, on) * (n - 1) - sm)