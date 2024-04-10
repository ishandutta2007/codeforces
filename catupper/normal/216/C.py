m,n,k=map(int,raw_input().split())
res=k
day=1

hired=[m]*k
pp=[1]*k

while day<=m+n:
	t=k-len(hired)
	if t>0:
		hired+=[m]*t
		res+=t
		pp+=[day]*t
	if max(hired)==1:
		hired+=[m]
		res+=1
		pp+=[day]
	hired=map((lambda x:x-1),hired)
	while hired[0]==0:hired.pop(0)
	day+=1
print res
print " ".join(map(str,pp))