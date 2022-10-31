inp = lambda:map(int, input().split())
n, m = inp();
a = [[],[]]
for x, y in zip(inp(), inp()):
	a[y] += [x]
s = [0] * m
riders, drivers = a;
i = 0
for ri in riders:
	while i < m - 1 and ri - drivers[i] > drivers[i + 1] - ri:
		i = i + 1
	s[i] = s[i] + 1;
print(*s)