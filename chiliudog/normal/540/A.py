n,s,t=int(input()),input(),input()
ans=0
for i in range(n):
	x,y=max(int(s[i]),int(t[i])),min(int(s[i]),int(t[i]))
	ans+=min(x-y,10+y-x)
print(ans)