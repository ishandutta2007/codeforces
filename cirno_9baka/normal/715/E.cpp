#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=5005;
int n,a[N],b[N],i,j,k,l,p[N],q[N],vis[N],s,e[4],su,fu[N],fv[N];
long long fac[N],inv[N],ans[N],f[2005][2005];
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
long long C(int n,int m)
{
	if(n<0)
		return 0;
	return fac[n]*inv[m]%M*inv[n-m]%M;
}
long long C2(int n,int a,int b)
{
	return fac[n]*inv[a]%M*inv[b]%M*inv[n-a-b]%M;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(fu[a[i]]&&a[i]!=0)
		{
			for(i=1;i<=n;++i)
				printf("0 ");
			return 0;
		}
		fu[a[i]]=1;
	}
	for(i=1;i<=n;++i)
	{
		scanf("%d",&b[i]);
		if(fv[b[i]]&&b[i]!=0)
		{
			for(i=1;i<=n;++i)
				printf("0 ");
			return 0;
		}
		fv[b[i]]=1;
	}
	memset(p,-1,sizeof(p));
	memset(q,-1,sizeof(q));
	for(i=1;i<=n;++i)
	{
		p[a[i]]=b[i];
		q[b[i]]=a[i];
		if(!a[i]&&!b[i])
			++su;
	}
	for(i=1;i<=n;++i)
		if(!vis[i])
		{
			for(j=p[i];j!=i&&j&&j!=-1;j=p[j]);
			if(j==i)
			{
				++s;
				vis[i]=1;
				for(j=p[i];j!=i&&j&&j!=-1;j=p[j])
					vis[j]=1;
			}
		}
	for(i=1;i<=n;++i)
		if(!vis[i])
		{
			int u=0,v=0;
			for(j=i;p[j]&&p[j]!=-1;j=p[j])
				vis[j]=1;
			vis[j]=1;
			if(!p[j])
				u=1;
			for(j=i;q[j]&&q[j]!=-1;j=q[j])
				vis[j]=1;
			vis[j]=1;
			if(!q[j])
				v=1;
			++e[u<<1|v];
		}
	int w=e[3];
	e[3]=0;
	fac[0]=inv[0]=1;
	for(i=1;i<=n*2;++i)
	{
		fac[i]=fac[i-1]*i%M;
		inv[i]=inv[i-1]*qpow(i,M-2)%M;
	}
	f[0][0]=1;
	for(i=1;i<=n;++i)
		for(k=1;k<=i;++k)
			for(j=1;j<=i;++j)
				f[i][k]=(f[i][k]+f[i-j][k-1]*fac[j-1]%M*C(i-1,j-1))%M;
	//cout<<g[1][0]<<endl;
	/*for(i=1;i<=e[1]+e[2]+e[3];++i)
		cout<<g[i]<<' ';
	cout<<endl;*/
	for(i=0;i<=min(e[1],e[2]);++i)
		for(j=0;j<=n;++j)
			ans[j+s]=(ans[j+s]+(i&1?-1:1)*f[e[0]+e[1]+e[2]-i][j]%M*C(e[0]+e[1]+e[2]-i,e[3])%M*fac[e[3]]%M*C(e[1],i)%M*C(e[2],i)%M*fac[i]%M)%M;
			
	for(i=n;i>=1;--i)
		printf("%lld ",(ans[i]*fac[su+w]%M+M)%M);
}