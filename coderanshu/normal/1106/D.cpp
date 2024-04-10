#pragma GCC optimize("Ofast")

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
#define INF 2e9
#define endl "\n"

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
vector<ll> v[100005];
vector<bool> vis(100005,false);
ll n;
vector<ll> ans;
void sort()
{
	for(auto i=1;i<=n;++i)
		sort(all(v[i]));
	ans.clear();
	return ;
}
void dfs(ll s)
{
	set<ll> q;
	q.insert(s);
	ll t;
	while(!q.empty())
	{
		 t=*q.begin();q.erase(q.begin());
		 vis[t]=true;ans.pb(t);
		 for(auto j:v[t])
		 {
		 	if(!vis[j])q.insert(j);	
		 }
	}
	return ;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll m,x,y;
	cin>>n>>m;
	while(m--)
	{
		cin>>x>>y;
		v[y].pb(x);v[x].pb(y);
	}
	sort();
	dfs(1);
	for(auto j:ans)cout<<j<<" ";
	return 0;
}