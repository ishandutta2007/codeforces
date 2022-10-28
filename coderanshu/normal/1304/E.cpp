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
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"
#define level 20
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
vector<ll> v[100005];
bool vis[100005];
ll d[100005],p[100005][20];
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
	return ;
}
void sparseMatrix(ll n)
{
	for(ll i=1;i<level;++i)
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
	for(ll i=0;i<level;++i)
	{
		if(df&(1<<i))v=p[v][i];
	}
	if(u==v)return u;
	for (ll i=level-1; i>=0; i--) 
	{
        if (p[u][i] != p[v][i]) 
        { 
            u = p[u][i]; 
            v = p[v][i]; 
        } 
  	}
    return p[u][0]; 
}
ll pl(ll a,ll b)
{
	return d[a]+d[b]-2*d[lca(a,b)];
}
void in(ll n)
{
	d[1]=0;
	dfs(1);
	sparseMatrix(n);
}
ll _runtimeTerror_()
{
	ll n;
	cin>>n;
	for(ll i=0;i<n-1;++i)
	{
		ll u,vx;cin>>u>>vx;
		v[u].pb(vx);v[vx].pb(u);
	}
	ll q;cin>>q;
	in(n);
	while(q--)
	{
		ll x,y,a,b,k;
		cin>>x>>y>>a>>b>>k;
		if(pl(a,b)%2==k%2 && pl(a,b)<=k)
		{
			cout<<"YES\n";continue;
		}
		ll z=pl(a,x)+pl(b,y)+1;
		ll m=pl(b,x)+pl(a,y)+1;
		if((z%2==k%2 && z<=k)|| (m%2 == k%2 && m<=k))
		{
			cout<<"YES\n";
		}
		else cout<<"NO\n";

	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	mem1(p);
	ll tests=1;
	//cin>>tests;
	while(tests--)
		_runtimeTerror_();
	return 0;
}