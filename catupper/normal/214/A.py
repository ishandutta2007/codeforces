n,m=map(int,raw_input().split())

res=0

for a in range(0,n+100):
	b=n-a*a
	if b<0:
		break
	if a+b*b==m:
		res+=1

print res