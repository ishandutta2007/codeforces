fac=[0]*25
fac[0]=1
for i in range(1,25):
	fac[i]=fac[i-1]*i
T=int(input());
while True:
	cnt = [0]*25
	pre = [0]*25
	k = int(input())
	p=2
	le=0
	while k!=0:
		cnt[k%p]+=1
		k//=p
		le=p
		p+=1
	pre[0]=cnt[0]
	for i in range(1,le+1):
		pre[i]=pre[i-1]+cnt[i]
	ans=1
	for i in range(2,le+1):
		ans*=pre[i-1]-(i-2)
	if cnt[0]!=0:
		exc=1
		for i in range(1,le+1):
			pre[i]-=1
		for i in range(2,le):
			if pre[i-1]-(i-2)<=0:
				exc=0
				break
			exc*=pre[i-1]-(i-2)
		ans-=exc*cnt[0]
	for i in range(le+1):
		ans//=fac[cnt[i]];
	print(ans-1)
	T-=1
	if T==0:
		break