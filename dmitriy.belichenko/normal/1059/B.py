def ok(field, y, x):
	for i in range(3):
		for j in range(3):
			if i == 1 and j == 1:
				continue
			if field[y + i][x + j] == '.':
				return False
	return True

def fill(y, x):
	for i in range(3):
		for j in range(3):
			if i == 1 and j == 1:
				continue
			cur[y + i][x + j] = '#'

n, m = list(map(int, input().split()))
sig = []
cur = []
for i in range(n):
	sig += [list(input())]
	cur += [["."] * m]

for i in range(n - 2):
	for j in range(m - 2):
		if ok(sig, i, j):
			fill(i, j)
if sig == cur:
	print("YES")
else:
	print("NO")