#lol, I'm going Crazy!!
n, a, b = map(int, raw_input().split());
ans = 0;
for i in range(a, n):
	c = n - i - 1;
	if c <= b:
		ans += 1
print ans