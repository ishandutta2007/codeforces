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
#define pll pair<ll,ll> 
#define ld long double

const long double PI = acos(-1);

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
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}
int _runtimeTerror_()
{
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;++i)
		cin>>a[i];
	ll pe[n+2],po[n+2];
	pe[0]=a[0];po[0]=0;
	for(int i=1;i<n;++i)
	{
		pe[i]=pe[i-1];
		po[i]=po[i-1];
		if(i&1)
			po[i]+=a[i];
		else pe[i]+=a[i];
	}
	ll ans=0,val=0;
	for(int i=0;i<n;i+=2)
		ans+=a[i],val+=a[i];
	multiset<ll> s[2];
	for(int i=0;i<n;++i)
	{
		s[i%2].insert(po[i]-pe[i]);
	}
	for(int i=0;i<n-1;++i)
	{
		assert(!s[1-i%2].empty());
		auto it=s[1-i%2].rbegin();
		ll x=*s[1-i%2].rbegin();
		if(i>0)
		{
			x+=pe[i-1];
			x-=po[i-1];
		}
		amax(ans,val+x);
		s[i%2].erase(s[i%2].find(po[i]-pe[i]));
	}
	cout<<ans<<'\n';
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
	return 0;
}