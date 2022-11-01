n=int(input())
a=sorted(map(int,input().split()))
pre=-1;ans=0;
for x in a:
	if x<=pre:
		ans+=pre-x+1;
		x=pre+1;
	pre=x;
print(ans)