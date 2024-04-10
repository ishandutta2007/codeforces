a=input()
l=map(int,raw_input().split())
ll=sorted(l)

res=0
for x in xrange(a):
	if l[x]!=ll[x]:
		res+=1

if res<=2:print 'YES'
else:print 'NO'