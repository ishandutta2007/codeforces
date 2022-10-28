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
vector<ll> v[200005];
bool vis[200005];
ll val[200005],color[200005];
void dfs(ll s)
{
	vis[s]=true;
	val[s]=0;
	for(auto j:v[s])
	{
		if(!vis[j])
		{
			dfs(j);
			if(val[j]>=0)
			val[s]+=val[j];
		}
	}
	if(color[s]==1)val[s]++;
	else val[s]--;
}
void bfs(ll s)
{
	memf(vis);
	vis[s]=true;
	queue<ll> q;q.push(s);
	while(!q.empty())
	{
		ll t=q.front();q.pop();
		for(auto j:v[t])
		{
			if(!vis[j])
			{
				if(val[j]>=0)
				{
					if(val[t]>val[j])val[j]=val[t];
				}
				else
				{
					if(val[t]>val[j])val[j]=val[t]-1;
				}
				vis[j]=true;q.push(j);
			}
		}
	}
}
int _runtimeTerror_()
{
	ll n,i,j;
	cin>>n;
	for(i=1;i<=n;++i)cin>>color[i];
	for(i=0;i<n-1;++i)
	{
		ll x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}
	ll root=1;
	dfs(root);
	bfs(root);
	for(i=1;i<=n;++i)cout<<val[i]<<" ";
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}