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

int a[4][4];
pair<int,int> getpoint(int x,int y,int i)
{
	if(i==0)
		return {x,y};
	if(i==1)
		return {-y,x};
	if(i==2)
		return {-x,-y};
	if(i==3)
		return {y,-x};
}
bool is_square(vector<pair<int,int>> &v)
{
	set<ll> s;
	for(int i=0;i<4;++i)
		for(int j=i+1;j<4;++j)
			s.insert((ll)(v[j].S-v[i].S)*(v[j].S-v[i].S)+(ll)(v[j].F-v[i].F)*(v[j].F-v[i].F));
	if(sz(s)!=2)
		return false;
	ll a=*s.begin();
	ll b=*s.rbegin();
	if(a*2==b)
		return true;
	return false;
}
int getans()
{
	int ans=100;
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			for(int k=0;k<4;++k)
				for(int l=0;l<4;++l)
				{
					int moves=i+j+k+l;
					vector<pair<int,int>> point;
					for(int x=0;x<4;++x)
					{
						int xx;
						if(x==0)xx=i;
						if(x==1)xx=j;
						if(x==2)xx=k;
						if(x==3)xx=l;
						pair<int,int> pp=getpoint(a[x][0]-a[x][2],a[x][1]-a[x][3],xx);
						pp.F+=a[x][2];pp.S+=a[x][3];
						point.pb(pp);
					}
					if(is_square(point))
						amin(ans,moves);
				}
	if(ans==100)
		return -1;
	return ans;
}
int _runtimeTerror_()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<4;++j)
			for(int k=0;k<4;++k)
				cin>>a[j][k];
		cout<<getans()<<endl;
	}
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