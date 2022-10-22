t=map(int,raw_input().split())
res=-1
while(any(t)):
	t[(res+1)%3]=max(t[(res+1)%3]-2,0)
	res+=1
print 30+res