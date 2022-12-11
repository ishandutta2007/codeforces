#include<cstdio>
#include<vector>
#include<algorithm>
#define MaxN 100123
typedef long long LL;
inline int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}
const int N=100000;
int n;
LL ans;
bool exist[MaxN];
std::vector<int>d[MaxN];
int mu[MaxN];
int cnt[MaxN];
inline void Sieve()
{
	static int prime[MaxN],cnt=0;
	static bool vis[MaxN];
	mu[1]=1;
	for(int i=2;i<=N;++i)
	{
		if(!vis[i])
		{
			prime[++cnt]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=N;++j)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				mu[i*prime[j]]=0;
				break;
			}
			else mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1;i<=N;++i)
	for(int j=i;j<=N;j+=i)
	d[j].push_back(i);
}
std::vector<int>s;
inline void Insert(int x)
{
	#ifdef Dubug
	printf("Insert(%d);\n",x);
	#endif
	for(auto i:d[x])++cnt[i];
	s.push_back(x);
}
inline void Delete()
{
	#ifdef Dubug
	printf("Delete(%d);\n",s.back());
	#endif
	for(auto i:d[s.back()])--cnt[i];
	s.pop_back();
}
inline int Calc(int x)
{
	#ifdef Dubug
	printf("Calc(%d);\n",x);
	#endif
	int ans=0;
	for(auto i:d[x])ans+=mu[i]*cnt[i];
	return ans;
}
inline void Solve()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		for(auto i:d[x])exist[i]=1;
		ans=std::max(ans,1LL*x);
	}
	for(int i=N;i;--i)
	{
		if(!exist[i])continue;
		if(Calc(i))
		{
			int x;
			while(Calc(i))x=s.back(),Delete();
			ans=std::max(ans,1LL*i*x);
		}
		else Insert(i);
	}
	printf("%lld\n",ans);
}
int main()
{
	Sieve();
	Solve();
	return 0;
}