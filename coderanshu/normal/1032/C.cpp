#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

const int N=100005;
ll dp[N][5],a[N],ans[N],n;
int _runtimeTerror_()
{
	cin>>n;
	ll i,j,k;
	for(i=0;i<n;++i)
		cin>>a[i];
	for(j=0;j<5;++j)
		dp[0][j]=1;
	for(i=1;i<n;++i)
	{
		if(a[i]>a[i-1])
		{
			for(j=0;j<5;++j)
			{
				for(k=0;k<j;++k)
				{
					if(dp[i-1][k]==1)
					{
						dp[i][j]=1;break;
					}
				}
			}
		}
		else if(a[i]==a[i-1])
		{
			for(j=0;j<5;++j)
			{
				for(k=0;k<5;++k)
				{
					if(k==j)continue;
					if(dp[i-1][k]==1)
					{
						dp[i][j]=1;break;
					}
				}
			}
		}
		else
		{
			for(j=0;j<5;++j)
			{
				for(k=j+1;k<5;++k)
				{
					if(dp[i-1][k]==1)
					{
						dp[i][j]=1;break;
					}
				}
			}
		}
	}
	ll lst;
	for(i=0;i<n;++i)
	{
		bool check=false;
		for(j=0;j<5;++j)
			if(dp[i][j]==1)check=true;
		if(!check)
		{
			cout<<-1;
			return 0;
		}
	}
	for(j=0;j<5;++j)
	{
		if(dp[n-1][j]==1)
		{
			lst=j,ans[n-1]=j;break;
		}
	}
	for(i=n-2;i>=0;--i)
	{
		if(a[i]<a[i+1])
		{
			for(j=0;j<lst;++j)
			{
				if(dp[i][j]==1)
				{
					lst=j,ans[i]=j;break;
				}
			}
		}
		else if(a[i]==a[i+1])
		{
			for(j=0;j<5;++j)
			{
				if(j!=lst && dp[i][j]==1)
				{
					lst=j;ans[i]=j;break;
				}
			}
		}
		else
		{
			for(j=lst+1;j<5;++j)
			{
				if(dp[i][j]==1)
				{
					lst=j,ans[i]=j;break;
				}
			}
		}
	}
	for(i=0;i<n;++i)
		cout<<ans[i]+1<<" ";
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef runSieve
		sieve();
	#endif
	#ifdef NCR
		initialize();
	#endif
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	cerr<<"\n"<<_time_;
	return 0;
}