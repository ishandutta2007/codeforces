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
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)

const long double PI = acos(-1);

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
	if(n<=3)
	{
		cout<<-1<<endl;
		return 0;
	}
	vector<ll> ans;
	if(n%4==0)
	{
		for(int i=1;i<=n/4;++i)
		{
			ans.pb(4*i-2);ans.pb(4*i);ans.pb(4*i-3);ans.pb(4*i-1);
		}
	}
	if(n%4==1)
	{	
		for(int i=1;i<=n/4;++i)
		{
			ans.pb(4*i-2);ans.pb(4*i);ans.pb(4*i-3);ans.pb(4*i-1);
		}
		ans.pb(n);
		swap(ans[n-2],ans[n-1]);
	}
	if(n%4==2)
	{
		for(int i=1;i<=n/4;++i)
		{
			ans.pb(4*i-2);ans.pb(4*i);ans.pb(4*i-3);ans.pb(4*i-1);
		}
		ans.pb(n-1);
		swap(ans[n-3],ans[n-2]);
		ans.pb(n);
	}
	if(n%4==3)
	{
		for(int i=1;i<=n/4;++i)
		{
			ans.pb(4*i-2);ans.pb(4*i);ans.pb(4*i-3);ans.pb(4*i-1);
		}
		ans.pb(n-1);
		swap(ans[n-3],ans[n-5]);
		ans.pb(n-2);
		ans.pb(n);
	}
	for(auto j:ans)
		cout<<j<<" ";
	cout<<endl;
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
	cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	cerr<<"\n"<<_time_;
	return 0;
}