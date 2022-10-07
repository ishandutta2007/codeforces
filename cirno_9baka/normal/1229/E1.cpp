#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
int n,i,p[10][10],m,t[10],tot,g[100005],j;
unsigned long long ans[100005];
map<unsigned long long,int> f[7];
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
void dfs2(int i,int s,unsigned long long a,unsigned long long b)
{
	int j;
	if(i==n)
	{
		if(b)
		{
			ans[tot]=b;
			g[tot]=s;
			++tot;
		}
		return;
	}
	dfs2(i+1,1ll*s*(1+M-t[i])%M,a,b);
	for(j=0;j<(1<<n);++j)
		if((a>>j)&1)
			if(!(j>>i&1))
				b|=1ull<<(j|(1<<i));
	dfs2(i+1,1ll*s*t[i]%M,a,b);
}
int dfs(int i,unsigned long long a)
{
	if(i==n)
		return 1;
	if(f[i][a])
		return f[i][a]-1;
	int j;
	for(j=0;j<n;++j)
		t[j]=p[i][j];
	tot=0;
	dfs2(0,1,a,0);
	unsigned long long ta[tot];
	int tg[tot];
	int tq=tot;
	for(j=0;j<tot;++j)
	{
		ta[j]=ans[j];
		tg[j]=g[j];
	}
	int s=0;
	for(j=0;j<tq;++j)
		s=(s+1ll*dfs(i+1,ta[j])*tg[j])%M;
	f[i][a]=s+1;
	return s;
}
int main()
{
	scanf("%d",&n);
	m=1<<n;
	long long iv100=qpow(100,M-2);
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
		{
			scanf("%d",&p[i][j]);
			p[i][j]=p[i][j]*iv100%M;
		}
	cout<<(dfs(0,1)%M+M)%M;
}