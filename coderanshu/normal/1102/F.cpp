
	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstring>
	#include <chrono>
	#include <complex>
	#define endl "\n"
	#define ll long long int
	#define vi vector<int>
	#define vll vector<ll>
	#define vvi vector < vi >
	#define pii pair<int,int>
	#define pll pair<long long, long long>
	#define mod 1000000007
	#define INF 1000000000000000001
	#define all(c) c.begin(),c.end()
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define f first
	#define s second
	const int N=16,NN=10005;
	ll a[N][NN];
	ll n,m;
	ll dp[N][N][1<<N],pre[N][N];
	using namespace std;
	int main()
	{
		scanf("%lld %lld",&n,&m);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				scanf("%lld",&a[i][j]);
		int sub=(1<<n);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				for(int k=0;k<sub;++k)
				{
					if(i==j && k==(1<<i))dp[i][j][k]=INF;
					else dp[i][j][k]=-1;
				}
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
			{
				pre[i][j]=INF;
				for(int k=0;k<m;++k)
					pre[i][j]=min(pre[i][j],abs(a[j][k]-a[i][k]));
				pre[j][i]=pre[i][j];
			}
		for(int used=1;used<sub;++used)
		{
			for(int i=0;i<n;++i)
				for(int j=0;j<n;++j)
				{
					if(dp[i][j][used]==-1)
						continue;
					for(int k=0;k<n;++k)
					{
						if(used&(1<<k))continue;
						dp[i][k][used|(1<<k)]=max(dp[i][k][used|(1<<k)],min(dp[i][j][used],pre[j][k]));
					}
				}
		}
		ll ans=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			{
				ll ff=dp[i][j][(1<<n)-1];
				for(int k=0;k<m-1;++k)
					ff=min(ff,abs(a[j][k]-a[i][k+1]));
				//printf("%lld",ff);
				ans=max(ans,ff);
			}
		printf("%lld",ans);
		return 0;
	}