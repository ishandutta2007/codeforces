from collections import Counter

def solve():
	input()
	r = Counter()
	a = []
	for x in input().split():
		x = int(x) % 10
		r[x] += 1
		if r[x] <= 3:
			a.append(x)
	for i in range(len(a)):
		for j in range(i):
			for k in range(j):
				if (a[i] + a[j] + a[k]) % 10 == 3:
					return "YES"
	return "NO"

for _ in range(int(input())):
	print(solve())