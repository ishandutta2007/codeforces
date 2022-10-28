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
ll n,m,tba;
vector<ll> v[100005];
ll c[100005];
vector<bool> vis(100005,false);
void dfs(ll s)
{
	vis[s]=true;
	tba=min(tba,c[s]);
	for(auto j: v[s])
	{
		if(!vis[j])
			dfs(j);
	}
	return ;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll x,y,i,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;++i)cin>>c[i];
	while(m--)
	{
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}
	for(i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			tba=INF;
			dfs(i);
			ans+=tba;
		}
	}
	cout<<ans;
	return 0;
}