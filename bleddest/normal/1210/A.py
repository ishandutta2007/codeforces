n, m = map(int, input().split())

d = [0 for i in range(7)]
g = [[] for i in range(7)]

for i in range(m):
	x, y = map(int, input().split())
	x -= 1
	y -= 1
	d[x] += 1
	d[y] += 1
	
	g[x].append(y)
	g[y].append(x)
	
mn = min(d)
for i in range(7):
	for j in range(i):
		cnt = 0
		for k in range(7):
			if((k in g[i]) and (k in g[j])):
				cnt += 1
		mn = min(mn, cnt)
m -= mn
print(m)