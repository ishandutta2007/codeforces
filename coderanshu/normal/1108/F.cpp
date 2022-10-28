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
#define INF 2e18
#define endl "\n"
#define llevel 20
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
struct node
{
	ll x,y,w,idx;
};
const int N=200002;
ll dsup[N],dsur[N],val=0,p[N][20],dep[N],ans[N][20];
bitset<N> vis;
vector<pair<ll,ll>> v[N];
void in(ll n)
{
	for(auto i=1;i<=n;++i)
	{
		dsup[i]=i;
		dsur[i]=0;
	}
}
ll parent(ll i)
{
	if(i==dsup[i])return i;
	return dsup[i]=parent(dsup[i]);
}
void merge(ll x,ll y)
{
	x=parent(x);
	y=parent(y);
	if(dsur[x]<dsur[y])
		dsup[x]=y;
	else
		dsup[y]=x;
	if(dsur[x]==dsur[y])
		++dsur[x];
}
void dfs(ll s)
{
	vis[s]=1;
	for(auto j:v[s])
	{
		if(!vis[j.F])
		{
			dep[j.F]=dep[s]+1;
			p[j.F][0]=s;
			ans[j.F][0]=j.S;
			dfs(j.F);
		}
	}
}
void build(ll n)
{
	for(auto i=1;i<20;++i)
	{
		for(auto j=1;j<=n;++j)
		{
				p[j][i]=p[p[j][i-1]][i-1];
				ans[j][i]=max(ans[j][i-1],ans[p[j][i-1]][i-1]);
		}
	}
}
ll query(ll a,ll b)
{
	if(dep[a]>dep[b])swap(a,b);
	ll diff=dep[b]-dep[a];
	ll ret=0;
	for(ll i=0;i<20;++i)
	{
		if(diff&(1<<i))
		{
			ret=max(ret,ans[b][i]);
			b=p[b][i];
		}
	}
	if(a==b)
		return ret;
	for(ll i=19;i>=0;--i)
	{
		if(p[a][i]!=p[b][i])
		{
			ret=max({ret,ans[a][i],ans[b][i]});
			a=p[a][i];b=p[b][i];
		}
	}
	ret=max({ret,ans[a][0],ans[b][0]});
	return ret;
}
int _runtimeTerror_()
{
	ll n,m,i;
	cin>>n>>m;
	in(n);
	bool mark[m]={false};
	node ed[m];
	ll print=0;
	for(i=0;i<m;++i)
	{
		cin>>ed[i].x>>ed[i].y>>ed[i].w;
		ed[i].idx=i;
	}
	sort(ed,ed+m,[&](node a,node b){return a.w<b.w;});
	for(i=0;i<m;++i)
	{
		if(parent(ed[i].x)!=parent(ed[i].y))
		{
			mark[ed[i].idx]=true;
			merge(ed[i].x,ed[i].y);
			v[ed[i].x].pb({ed[i].y,ed[i].w});v[ed[i].y].pb({ed[i].x,ed[i].w});
			val+=ed[i].w;
		}
	}
	p[1][0]=0;
	ans[1][0]=0;
	dfs(1);
	build(n);
	for(i=0;i<m;++i)
	{
		if(mark[ed[i].idx])
		{
			continue;
		}
		ll z=query(ed[i].x,ed[i].y);
		if(z==ed[i].w)
			++print;
	}
	cout<<print<<endl;
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
	return 0;
}