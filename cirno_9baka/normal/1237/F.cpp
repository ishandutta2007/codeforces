#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,i,h,w,r1,r2,c1,c2,v1[3605],v2[3605],p[3605][3605],q[3605][3605],a[3605],k,j;
long long fac[100005],inv[100005],f[3605][3605],ans;
long long C(long long n,long long m)
{
	if(n<0||m<0||n<m)
		return 0;
	return fac[n]*inv[m]%M*inv[n-m]%M;
}
int main()
{
	inv[0]=inv[1]=fac[0]=1;
	for(i=2;i<=100000;i++)
		inv[i]=inv[M%i]*(M-M/i)%M;
	for(i=1;i<=100000;i++)
	{
		inv[i]=inv[i-1]*inv[i]%M;
		fac[i]=fac[i-1]*i%M;
	}
	scanf("%d %d %d",&h,&w,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
		v1[r1]=v1[r2]=v2[c1]=v2[c2]=1;
	}
	k=0;
	for(i=1;i<=h;i++)
		if(v1[i]==0)
			a[++k]=i;
	memset(f,0,sizeof(f));
	f[0][0]=f[1][0]=1;
	for(i=2;i<=k;i++)
	{
		f[i][0]=1;
		for(j=1;j<=i/2;j++)
		{
			f[i][j]=f[i-1][j];
			if(a[i]==a[i-1]+1)
				f[i][j]=(f[i-2][j-1]+f[i][j])%M;
		}
	}
	for(i=0;i<=k/2;i++)
		for(j=0;j<=k-i*2;j++)
			p[i][j]=C(k-i*2,j)*f[k][i]%M;
	k=0;
	for(i=1;i<=w;i++)
		if(v2[i]==0)
			a[++k]=i;
	memset(f,0,sizeof(f));
	f[0][0]=f[1][0]=1;
	for(i=2;i<=k;i++)
	{
		f[i][0]=1;
		for(j=1;j<=i/2;j++)
		{
			f[i][j]=f[i-1][j];
			if(a[i]==a[i-1]+1)
				f[i][j]=(f[i-2][j-1]+f[i][j])%M;
		}
	}
	for(i=0;i<=k/2;i++)
		for(j=0;j<=k-i*2;j++)
			q[i][j]=C(k-i*2,j)*f[k][i]%M;
	for(i=0;i<=h;i++)
		for(j=0;j<=h;j++)
			ans=(ans+1ll*p[i][j]*q[j][i]%M*fac[j]%M*fac[i])%M;
	cout<<(ans%M+M)%M;
}