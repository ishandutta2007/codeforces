n = int(input())
subtract = lambda t1, t2: (t1[0] - t2[0], t1[1] - t2[1])
add = lambda t1, t2: (t1[0] + t2[0], t1[1] + t2[1])
def conv(ch):
	if ch == 'L':
		return (-1, 0)
	elif ch == 'R':
		return (1, 0)
	elif ch == 'U':
		return (0, 1)
	elif ch == 'D':
		return (0, -1)

ops = [conv(ch) for ch in input()]
x, y = map(int, input().split())
lsum = [ops[0]] * n
for i in range(1, n):
	lsum[i] = add(lsum[i - 1], ops[i])
rsum = [ops[n - 1]] * n
i = n - 2
while i >= 0:
	rsum[i] = add(rsum[i + 1], ops[i])
	i = i - 1

def check(L):
	
	for i in range(0, n - L + 1):
		moves = (x, y)
		if i > 0:
			moves = subtract(moves, lsum[i - 1])
		if i + L < n:
			moves = subtract(moves, rsum[i + L])
		turns = abs(moves[0]) + abs(moves[1])
		if (turns <= L and (L - turns) % 2 == 0):
			return True;
	return False;

if abs(x) + abs(y) > n or (abs(x) + abs(y) - n) % 2 != 0:
	print(-1);
else:
	st, en = 0, n
	while st < en:
		md = (st + en) // 2
		if check(md):
			en = md
		else:
			st = md + 1
	print(st)