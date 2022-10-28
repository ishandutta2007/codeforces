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

const int N=200005;
vector<int> v[N];
bool vis[N];
vector<int> req,pending;
void dfs(int s)
{
	vis[s]=true;
	for(auto j:v[s])
	{
		if(!vis[j])
			dfs(j);
	}
}
int p[200005],r[200005];
void in(int n)
{
	for(int i=1;i<=n;++i)
		p[i]=i,r[i]=0;
}
int parent(int i)
{
	if(i==p[i])return i;
	return p[i]=parent(p[i]);
}
void merge(int x,int y)
{
	x=parent(x);y=parent(y);
	if(r[x]>r[y])
		p[y]=x;
	else p[x]=y;
	if(r[x]==r[y])++r[y];
}
int _runtimeTerror_()
{
	int n,m,D;
	cin>>n>>m>>D;
	vector<pair<int,int>> ans,edges;
	for(int i=0;i<m;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
		edges.pb({x,y});
	}
	in(n);
	if(sz(v[1])<D)
	{
		 cout<<"NO\n";return 0;
	}
	vis[1]=true;
	for(auto k:v[1])
	{
		if(!vis[k])
		{
			req.pb(k);
			dfs(k);
		}
		else pending.pb(k);
	}
	if(sz(req)>D)
	{
		cout<<"NO\n";return 0;
	}
	while(sz(req)<D)
	{
		req.pb(pending.back());
		pending.pop_back();
	}
	for(auto j:req)
		merge(1,j),ans.pb({1,j});
	for(auto k:edges)
	{
		if(parent(k.F)!=parent(k.S) && k.F!=1 && k.S!=1)
			ans.pb({k.F,k.S}),merge(k.F,k.S);
	}
	cout<<"YES\n";
	for(auto j:ans)
		cout<<j.F<<" "<<j.S<<endl;
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