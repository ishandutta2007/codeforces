import sys
input = sys.stdin.readline

for _ in range(int(input())):
	a=list(map(int,input().strip().split(" ")))
	b=[]
	for i in range(a[0]):
		b.append(input().strip().split(" "))
	c=""
	f=[]
	u=""
	for i in range(a[1]):
		u=input().strip().split(" ")
		if b[0][0] in u:
			c=u
	
	x={}
	for i in b:
		x[i[0]]=i
	for i in c:
		f.append(x[i])
	for i in f:
		print(" ".join(i))