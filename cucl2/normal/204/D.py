Mod=1000000007
n,k=map(int,input().split(' '))
s=' '+input()
f,fs,g,gs,w=[0]*1000005,[0]*1000005,[0]*1000005,[0]*1000005,[0]*1000005
qx,qw,qb=[0]*1000005,[0]*1000005,[0]*1000005
q=0
f[0]=fs[0]=1
for i in range(1,n+1):
	lg=(i-k if i-k>=q else q)
	if s[i]!='B':
		f[i]=fs[i-1]-fs[lg-1]+Mod
		f[i]-=(Mod if f[i]>=Mod else 0)
	else:
		f[i]=0
	fs[i]=fs[i-1]+f[i]
	fs[i]-=(Mod if fs[i]>=Mod else 0)
	if s[i]=='W':
		q=i;
g[n+1]=gs[n+1]=1
q=n+1
for i in range(n,0,-1):
	rg=(i+k if i+k<=q else q)
	if s[i]!='W':
		g[i]=gs[i+1]-gs[rg+1]+Mod
		g[i]-=(Mod if g[i]>=Mod else 0)
	else:
		g[i]=0
	gs[i]=gs[i+1]+g[i]
	gs[i]-=(Mod if gs[i]>=Mod else 0)
	if s[i]=='B':
		q=i;
for i in range(1,n+1):
	qx[i],qb[i],qw[i]=qx[i-1]+(s[i]=='X'),qb[i-1]+(s[i]=='B'),qw[i-1]+(s[i]=='W')
for i in range(n,0,-1):
	w[i]=w[i+1]
	if s[i]=='X':
		w[i]*=2
		w[i]-=(Mod if w[i]>=Mod else 0)
	if i+k-1<=n:
		if qb[i+k-1]-qb[i-1]==0:
			w[i]+=g[i+k]
			w[i]-=(Mod if w[i]>=Mod else 0)
ans=0
for i in range(k,n+1):
	if qw[i]-qw[i-k]==0:
		ans=(ans+f[i-k]*w[i+1])%Mod
print(ans)