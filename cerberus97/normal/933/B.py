p, k = map(int, input().split())
l = []
d = 0
sign = +1
while (True):
	t = []
	st = sign * (k ** d)
	for j in range(k):
		t.append(j * st)

	l.append(t)
	d += 1
	sign = -sign
	if (t[-1] >= p):
		break

	# print(i, t[-1])

# print(d, l)
a = 0
b = 0
neg = []
pos = []
for i in range(d):
	a += min(l[i][0], l[i][-1])
	b += max(l[i][0], l[i][-1])
	neg.append(a)
	pos.append(b)

ans = []
done = True
for i in range(d - 1, -1, -1):
	# print(i)
	if (i == 0):
		if p in l[i]:
			ans.append(p)
		else:
			done = False
		break

	for j in range(k):
		# print(j, neg[i - 1], pos[i - 1])
		if (l[i][j] + neg[i - 1] <= p and l[i][j] + pos[i - 1] >= p):
			ans.append(j)
			p -= l[i][j]
			# print(p, j)
			break

# print(done, ans)

if (done and len(ans) == d):
	while (ans[0] == 0):
		ans = ans[1:]
		d -= 1

	print(d)
	for i in range(d - 1, -1, -1):
		print(ans[i], end = ' ')
else:
	print(-1)