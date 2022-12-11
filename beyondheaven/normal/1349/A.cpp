#include<bits/stdc++.h>
#define MaxN 200123
const int N=200000;
int n;
int a[MaxN];
int prime[MaxN>>2],mp[MaxN],cnt;
bool vis[MaxN];
std::vector<std::pair<int,int>>d[MaxN];
std::vector<int>f[MaxN];
inline void Sieve()
{
	for(int i=2;i<=N;++i)
	{
		if(!vis[i])
		{
			prime[++cnt]=i;
			mp[i]=i;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=N;++j)
		{
			vis[i*prime[j]]=1;
			mp[i*prime[j]]=std::min(mp[i],prime[j]);
			if(i%prime[j]==0)break;
		}
	}
}
inline void Init()
{
	Sieve();
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%d",a+i);
	for(int i=1,x;i<=n;++i)
	{
		x=a[i];
		while(x>1)
		{
			int p,k;
			for(p=mp[x],k=0;mp[x]==p;x/=mp[x])++k;
			d[i].push_back(std::make_pair(p,k));
		}
	}
}
inline void Solve()
{
	for(int i=1;i<=n;++i)
	{
		#ifdef Dubug
		printf("decompose of %d:\n",a[i]);
		for(auto&v:d[i])
		printf("%d^%d\n",v.first,v.second);
		#endif
		for(auto&v:d[i])
		f[v.first].push_back(v.second);
	}
	for(int i=1;i<=cnt;++i)
	std::sort(f[prime[i]].begin(),f[prime[i]].end());
	long long ans=1;
	for(int i=1;i<=cnt;++i)
	if(f[prime[i]].size()==n)
	{
		for(int j=1;j<=f[prime[i]][1];++j)
		ans*=prime[i];
	}
	else if(f[prime[i]].size()==n-1)
	{
		for(int j=1;j<=f[prime[i]][0];++j)
		ans*=prime[i];
	}
	printf("%lld\n",ans);
}
int main()
{
	Init();
	Solve();
	return 0;
}