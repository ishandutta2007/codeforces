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

const int N=400002;
ll n,a[N],dp[1<<20];
vector<ll> v;
ll cnt[22][22];
int _runtimeTerror_()
{
	cin>>n;
	ll i,j;
	bool mark[21];
	memf(mark);
	ll temp[21];
	mem0(temp);
	for(i=0;i<n;++i)
	{
		cin>>a[i];
		mark[a[i]]=true;
	}
	for(i=1;i<=20;++i)
	{
		if(!mark[i])continue;
		for(j=1;j<=20;++j)
		{
			if(j==i || !mark[j])continue;
			ll pfx[n];
			for(ll k=0;k<n;++k)
			{
				if(k==0)
					pfx[0]=(a[0]==j);
				else
					pfx[k]=pfx[k-1]+(a[k]==j);
				if(a[k]==i)
					cnt[j][i]+=pfx[k];
			}
		}
	}
	for(i=1;i<=20;++i)
		if(mark[i])
			v.pb(i);
	ll nn=sz(v);
	ll sub=(1<<nn);
	for(i=1;i<sub;++i)
	{
		dp[i]=INF;
		ll ff=0;
		bool ch[21];
		memf(ch);
		for(j=0;j<nn;++j)
			if(i&(1<<j))
				ch[v[j]]=true;
		for(j=0;j<nn;++j)
		{
			if(i&(1<<j))
			{
				ll sample=0;
				for(ll z=1;z<=20;++z)
				{
					if(!ch[z])
						sample+=cnt[z][v[j]];
				}
				amin(dp[i],dp[i&(~(1<<j))]+sample);
			}
		}
	}
	cout<<dp[sub-1]<<endl;
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