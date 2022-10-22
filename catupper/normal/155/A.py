a=input()
a=map(int,raw_input().split())

minn=a[0]
maxx=a[0]
res=0
for x in range(1,len(a)):
	if(a[x]<minn):
		res+=1
		minn=a[x]
	if(a[x]>maxx):
		res+=1
		maxx=a[x]

print res