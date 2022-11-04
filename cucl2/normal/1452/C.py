read = lambda: map(int, input().split())

T = int(input())

for t in range(T):
	s = input()
	c1, c2, ans = 0, 0, 0
	for c in s:
		if c == '(': c1 += 1
		if c == ')' and c1:
			c1 -= 1
			ans += 1
		if c == '[': c2 += 1
		if c == ']' and c2:
			c2 -= 1
			ans += 1
	print(ans)