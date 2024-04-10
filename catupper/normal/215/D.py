n,m=map(int,raw_input().split())
res = 0
for t in range(n):
	a,b,c,d=map(int,raw_input().split())
	if a+1>b:
		res+=d+c*m
		continue
	s=(m/(b-a))+(m%(b-a)!=0)
	x=s*d
	res+=min(x,d+c*m)

print res