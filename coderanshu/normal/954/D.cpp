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
template<typename T, typename U> static inline void setmin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void setmax(T &x, U y){ if(x<y) x=y; }


vector<ll> v[1003];
ll level[2][1003];
bool vis[1003];
void bfs(ll x,ll vv)
{
	level[vv][x]=0;
	queue<ll> q;
	q.push(x);
	vis[x]=true;
	while(!q.empty())
	{
		ll t=q.front();
		q.pop();
		for(auto j:v[t])
		{
			if(!vis[j])
			{
				vis[j]=true;
				level[vv][j]=level[vv][t]+1;
				q.push(j);
			}
		}
	}
}
int _runtimeTerror_()
{
	ll n,m,s,t,i,j;
	cin>>n>>m>>s>>t;
	ll adj[n+1][n+1]={0};
	while(m--)
	{
		ll x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
		adj[x][y]=1;adj[y][x]=1;
	}
	bfs(s,0);
	memf(vis);
	bfs(t,1);
	ll ans=0;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=i;++j)
		{
			if(adj[i][j]==1 || i==j)continue;
			if(level[0][i]+level[1][j]+1<level[0][t] || level[0][j]+level[1][i]+1<level[1][s])continue;
			++ans;
		}
	}
	cout<<ans<<endl;
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