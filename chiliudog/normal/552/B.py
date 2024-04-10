n=int(input())
k,ans=0,0
while n>=k:
	ans+=n-k
	k=k*10+9
print(ans)