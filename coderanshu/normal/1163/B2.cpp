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


int _runtimeTerror_()
{
	ll n;
	cin>>n;
	ll a[n],i;
	for(i=0;i<n;++i)
		cin>>a[i];
	int fr[100005];
	mem0(fr);
	map<ll,ll> m;
	ll ans=0;
	for(i=0;i<n;++i)
	{
		if(fr[a[i]]!=0)
		{
			if(m[fr[a[i]]]==1)
				m.erase(fr[a[i]]);
			else
				m[fr[a[i]]]--;
		}
		fr[a[i]]++;
		m[fr[a[i]]]++;
		if(m.size()==1)
		{
			if(m.count(1) || m.begin()->S==1)ans=i+1;
			continue;
		}
		else if(m.size()==2)
		{
			if(m.count(1) && m[1]==1)
				ans=i+1;
			else
			{
				int x=m.begin()->F;
				if(m.rbegin()->F>x+1)
					continue;
				else
				{
					if(m[x+1]==1)
						ans=i+1;
				}
			}
		}
	}
	cout<<ans;
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