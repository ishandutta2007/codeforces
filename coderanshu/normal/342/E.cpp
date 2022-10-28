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
vector<ll> v[100005];
bool vis[100005];
ll d[100005],p[100005][20],md[100005],color[100005];
void dfs(ll s)
{
	vis[s]=true;
	for(auto j:v[s])
	{
		if(!vis[j])
		{
			d[j]=d[s]+1;p[j][0]=s;
			dfs(j);
		}
	}
}
void sparseMatrix(ll n)
{
	for(ll i=1;i<20;++i)
	{
		for(ll j=1;j<=n;++j)
		{
			if(p[j][i-1]!=-1)
				p[j][i]=p[p[j][i-1]][i-1];
		}
	}
}
ll lca(ll u,ll v)
{
	if(d[u]>d[v])swap(u,v);
	ll df=d[v]-d[u];
	for(ll i=0;i<20;++i)
		if(df&(1<<i))v=p[v][i];
	if(u==v)return u;
	for (ll i=20-1; i>=0; i--) 
	{
        if (p[u][i] != p[v][i]) 
        { 
            u = p[u][i]; 
            v = p[v][i]; 
        } 
  	}
    return p[u][0]; 
}
void compute(ll n)
{
	queue<ll> q;
	ll i;
	for(i=1;i<=n;++i)
	{
		vis[i]=false;
		if(color[i]==1)
		{
			q.push(i),md[i]=0,vis[i]=true;
		}
	}
	while(!q.empty())
	{
		ll t=q.front();q.pop();
		for(auto j:v[t])
		{
			if(!vis[j])
			{
				vis[j]=true;
				q.push(j);
				md[j]=md[t]+1;
			}
		}
	}
	return ;
}
ll pl(ll a,ll b)
{
	return d[a]+d[b]-2*d[lca(a,b)];
}
void in(ll n)
{
	mem1(p);
	d[1]=0;
	dfs(1);
	sparseMatrix(n);
}
const int N=100005;
struct node{
	ll id,vt,b;
};
int _runtimeTerror_()
{
	ll n,m,i;
	cin>>n>>m;
	for(ll i=0;i<n-1;++i)
	{
		ll x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}
	in(n);
	color[1]=1;
	ll BLOCK=sqrt(n);
	node Q[N];
	for(i=0;i<m;++i)
		cin>>Q[i].id>>Q[i].vt,Q[i].b=i/BLOCK+1;
	ll curB=1;
	for(i=0;i<m;++i)
	{
		compute(n);
		vector<ll> qq;
		while(i<m && Q[i].b==curB)
		{
			if(Q[i].id==1)
			{
				color[Q[i].vt]=1;
				qq.pb(Q[i].vt);
				++i;
				continue;
			}
			ll ans=md[Q[i].vt];
			for(auto j:qq)
				amin(ans,pl(Q[i].vt,j));
			cout<<ans<<endl;
			++i;
		}
		--i;
		++curB;
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