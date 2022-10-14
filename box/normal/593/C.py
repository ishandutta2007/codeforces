def canonise(t):
	if t < 0:
		return "(0-" + canonise(-t) + ")"
	ans = ""
	while t > 50:
		ans += "(50+"
		t -= 50
	return ans + str(t) + ")" * (len(ans)//4)

n = int(input())

cxes = []
cyes = []
for i in range(n):
	x, y, r = map(int, input().split())
	for dx in range(2):
		for dy in range(2):
			if (x+dx)%2 == 0 and (y+dy)%2 == 0:
				cxes.append((x+dx)//2)
				cyes.append((y+dy)//2)

coeffx = [0]*(n+2)
coeffy = [0]*(n+2)
cfx = 0
cfy = 0

for i in range(n):
	if i == 0:
		cfx += cxes[i]
		coeffx[i+1] -= cxes[i]
		coeffx[i+2] += cxes[i]
		
		cfy += cyes[i]
		coeffy[i+1] -= cyes[i]
		coeffy[i+2] += cyes[i]
	elif i == n-1:
		cfx += cxes[i]
		coeffx[i] += cxes[i]
		coeffx[i+1] -= cxes[i]

		cfy += cyes[i]
		coeffy[i] += cyes[i]
		coeffy[i+1] -= cyes[i]
	else:
		coeffx[i] += cxes[i]
		coeffx[i+1] -= 2*cxes[i]
		coeffx[i+2] += cxes[i]

		coeffy[i] += cyes[i]
		coeffy[i+1] -= 2*cyes[i]
		coeffy[i+2] += cyes[i]

rx = ""
ry = ""
for i in range(1, n+1):
	s = f"abs((t-{i}))"
	if i != n:
		rx += f"(({s}*{canonise(coeffx[i])})+"
		ry += f"(({s}*{canonise(coeffy[i])})+"
	else:
		rx += f"({s}*{canonise(coeffx[i])})" + ")"*(n-1)
		ry += f"({s}*{canonise(coeffy[i])})" + ")"*(n-1)

print(f"({rx}+{canonise(cfx)})")
print(f"({ry}+{canonise(cfy)})")