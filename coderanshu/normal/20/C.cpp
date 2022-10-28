#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=a;i<b;i++)
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"
#define findMax max_element
ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}
vector<pair<ll,ll>> adj[100005];
bool vis[100005];
ll dis[100005],mapped[100005],n;
bool dijkstra(ll so,ll de)
{
	dis[1]=0;vis[1]=false;
	for(auto i=2;i<=n;i++)
	{
		dis[i]=INF;vis[i]=false;mapped[i]=i;
	}
	set<pair<ll,ll>> s;
	s.insert({0,1});
	pair<ll,ll> p;
	mapped[1]=1;
	bool found=false;
	while(!s.empty())
	{
		p=*s.begin();s.erase(s.begin());
		if(p.S==de)
			{
				found=true;
				break;
			}
		vis[p.S]=true;
		for(auto j:adj[p.S])
		{
			if(dis[p.S]+j.S<dis[j.F])
			{
				if(s.count({dis[j.F],j.F}))
					s.erase({dis[j.F],j.F});
				mapped[j.F]=p.S;
				dis[j.F]=dis[p.S]+j.S;
				s.insert({dis[j.F],j.F});
			}
		}
	}
	return found;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll m,u,v,w;
	cin>>n>>m;
	for(auto i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
	if(dijkstra(1LL,n))
	{
		vector<ll> ans;
		ans.pb(n);ll i=n;
		while(mapped[i]!=i)
		{
			ans.pb(mapped[i]);i=mapped[i];
		}
		reverse(all(ans));
		for(auto j:ans)cout<<j<<" ";
	}
	else
		cout<<-1;
	return 0;
}