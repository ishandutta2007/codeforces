from collections import Counter

def f(s):
	x = int(s)
	while x % 2 == 0: x //= 2
	return x

def solve():
	input()
	m = Counter(map(f, input().split()))
	for x in map(f, input().split()):
		while x > 0 and m[x] == 0:
			x //= 2
		if x:
			m[x] -= 1
	print("NO" if sum(m.values()) else "YES")

tn = int(input())
for _ in range(tn):
	solve()