m={}
g=input()
for tt in xrange(g):
	a,b=map(int,raw_input().split())
	if a not in m:
		m[a]=set()
	m[a].add(b)

m=m.values()

k=0
while k < len(m):
	y=k+1
	g=0
	while y<len(m):
		if m[k]&m[y]:
			m[k]|=m[y]
			m.pop(y)
			g+=1
		else:
			y+=1
	if g==0:
		k+=1

print len(m)-1