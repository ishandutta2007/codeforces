#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back

const int N=1005;
ll b[N],w[N],n,dp[N];
vector<int> v[N];
bool vis[N];
vector<vector<pair<ll,ll>>> pre;
vector<pair<ll,ll>> vv;
ll bty,we;

void dfs(int s)
{
	vis[s]=true;
	we+=w[s],bty+=b[s];
	vv.pb({w[s],b[s]});
	for(auto j:v[s])
		if(!vis[j])
			dfs(j);
	
}
int main() {
	ios_base::sync_with_stdio(false);
	int m;
	ll weight;
	cin>>n>>m>>weight;
	for(int i=1;i<=n;++i)
	{
		cin>>w[i];
		dp[i]=-1e18;
	}
	for(int i=1;i<=n;++i)
		cin>>b[i];
	for(int i=0;i<m;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			bty=we=0;
			vv.clear();
			dfs(i);
			vv.pb({we,bty});
			pre.pb(vv);
		}
	}
	for(auto j:pre)
	{
		ll x[N];
		for(int i=0;i<=1000;++i)
			x[i]=dp[i];
		for(auto k:j)
		{
			for(int i=0;i<=1000;++i)
			{
				if(k.first+i>1000)
					break;
				dp[i+k.first]=max(dp[i+k.first],x[i]+k.second);
			}
		}
	}
	ll ans=-1e18;
	for(int i=0;i<=weight;++i)
		ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}