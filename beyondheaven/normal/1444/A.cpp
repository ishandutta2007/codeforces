#include<bits/stdc++.h>
#define MaxN 100123
typedef long long LL;

inline LL pow_mod(LL a,LL b)
{
	LL res=1;
	for(;b;b>>=1,a=a*a)
	if(b&1)res=res*a;
	return res;
}

int prime[MaxN],cnt;
bool vis[MaxN];

inline void Sieve()
{
	const int n=100000;
	for(int i=2;i<=n;++i)
	{
		if(!vis[i])
		{
			prime[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=n;++j)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}

int a[MaxN],b[MaxN];

inline LL Solve(LL p,int q)
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int tmp=0;
	
	for(int i=1;i<=cnt;++i)
	if(q%prime[i]==0)
	{
		a[++tmp]=prime[i];
		while(q%prime[i]==0)
		{
			++b[tmp];
			q/=prime[i];
		}
	}
	
	if(q>1)
	{
		a[++tmp]=q;
		b[tmp]=1;
	}
	
	#ifdef Dubug
	for(int i=1;i<=tmp;++i)
	printf("%d^%d ",a[i],b[i]);
	puts("");
	#endif
	
	bool flag=0;
	
	for(int i=1;i<=tmp;++i)
	flag|=(p%pow_mod(a[i],b[i])!=0);
	
	if(flag)return p;
	
	LL raw_p=p;
	
	LL minv=1e18+5;
	for(int i=1;i<=tmp;++i)
	if(p%a[i]==0)
	{
		LL t=1;
		while(p%a[i]==0)
		{
			p/=a[i];
			t*=a[i];
		}
		minv=std::min(minv,t/pow_mod(a[i],b[i]-1));
	}
	
	#ifdef Dubug
	printf("minv=%lld\n",minv);
	#endif
	
	return raw_p/minv;
}

int main()
{
	Sieve();
	int T=0;scanf("%d",&T);
	while(T--)
	{
		LL p;int q;scanf("%lld%d",&p,&q);
		printf("%lld\n",Solve(p,q));
	}
	
	return 0;
}