a,b=map(int,raw_input().split())
c=map(int,raw_input().split())
c.sort()
k=c[::]
ma=0
mi=0
for x in range(a):
	if c[0]==0:c.pop(0)
	mi+=c[0]
	c[0]-=1
	ma+=k[-1]
	k[-1]-=1
	k.sort()

print ma,mi