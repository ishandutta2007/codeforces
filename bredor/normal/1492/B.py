for _ in range(int(input())):
	n=int(input())
	lis=list(map(int,input().split()))
	look=[0 for i in range(n)]
	
	look[0]=lis[0]
	for i in range(1,n):
		look[i]=max(look[i-1],lis[i])
	j=n
	ans=[]
	for i in range(n-1,-1,-1):
		if look[i]==lis[i]:
			ans.extend(lis[i:j])
			j=i
			
	print(*ans)