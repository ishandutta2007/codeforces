t = int(input())
for _ in range(t):
	n = int(input())
	neg = []
	pos = []
	for v in map(int, input().split()):
		if v >= 0:
			pos.append(v)
		else:
			neg.append(v)
	pos.sort(reverse=True)
	neg.sort()
	lo = max(5 - len(pos), 0)
	hi = min(5, len(neg))
	out = []
	for i in range(lo, hi+1):
		curr = 1
		for j in range(i):
			curr*=neg[j]
		for j in range(5-i):
			curr*=pos[j]
		out.append(curr)
	neg=neg[::-1]
	for i in range(lo, hi+1):
		curr = 1
		for j in range(i):
			curr*=neg[j]
		for j in range(5-i):
			curr*=pos[j]
		out.append(curr)
	print(max(out))