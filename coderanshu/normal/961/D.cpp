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
#define popcount(x) __builtin_popcountll(x)
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
pair<ll,ll> p[N];
ll a,b,c,n;
void pre(int id1,int id2)
{
	b=p[id2].F-p[id1].F;
	a=p[id1].S-p[id2].S;
	c=p[id2].S*p[id1].F-p[id1].S*p[id2].F;
}
bool check(int id1,int id2)
{
	vector<ll> v;
	pre(id1,id2);
	for(int i=0;i<n;++i)
			if(a*p[i].F+b*p[i].S+c!=0)
				v.pb(i);
	if(sz(v)<=2)
		return true;
	pre(v[0],v[1]);
	for(int i=0;i<sz(v);++i)
		if(a*p[v[i]].F+b*p[v[i]].S+c!=0)
			return false;
	return true;
}
int _runtimeTerror_()
{
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>p[i].F>>p[i].S;
	if(n<=4)
	{
		cout<<"YES\n";return 0;
	}
	if(check(0,2) || check(0,1) || (check(1,2)))
		cout<<"YES\n";
	else cout<<"NO\n";
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