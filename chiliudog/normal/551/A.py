n=int(input())
a=list(map(int,input().split()))
for i in a:
	ans=1
	for j in a:
		if j>i:
			ans+=1
	print(ans,end=' ')