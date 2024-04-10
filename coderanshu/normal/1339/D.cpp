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
vector<ll> v[N];
bool vis[N];
ll ansm=0;
ll val[2],dep[N];
void dfs(ll s)
{
	vis[s]=true;
	ll count=0;
	bool var=false;
	for(auto j:v[s])
	{
		if(!vis[j])
		{
			dep[j]=dep[s]+1;
			dfs(j);
			if(sz(v[j])==1)
				var=true;
			if(sz(v[j])>1)
				++count;
		}
	}
	if(sz(v[s])==1)
		val[dep[s]%2]++;
	ansm+=count+var;
}
int _runtimeTerror_()
{
	ll n,i;
	cin>>n;
	for(i=0;i<n-1;++i)
	{
		ll x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}

	ll sour=1;
	for(i=1;i<=n;++i)
	{
		if(sz(v[i])>1)
		{
			sour=i;break;
		}
	}
	dep[sour]=0;
	dfs(sour);
	if(val[1] && val[0])
		cout<<"3 ";
	else cout<<"1 ";
	cout<<ansm<<endl;
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