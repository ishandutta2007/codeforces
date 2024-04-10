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
vector<ll> degree[200005];
ll p[200005],r[200005];
vector<pair<ll,ll>> edges;
ll n;
void in()
{
	for(auto i=1;i<=n;++i)
	{
		r[i]=0;p[i]=i;
	}
}
ll parent(ll i)
{
	if(i==p[i])return i;
	return p[i]=parent(p[i]);
}
void merge(ll x,ll y)
{
	x=parent(x);
	y=parent(y);
	if(r[x]>r[y])
		p[y]=x;
	else p[x]=p[y];
	if(r[x]==r[y])++r[y];
	return ;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll m,x,y,i;
	cin>>n>>m;
	in();
	while(m--)
	{
		cin>>x>>y;
		edges.pb({x,y});
		degree[x].pb(y);
		degree[y].pb(x);
	}
	ll ansd=0,ans=0;
	for(i=1;i<=n;i++)
	{
		if(degree[i].size()>ans)
		{
			ans=degree[i].size();
			ansd=i;
		}
	}
	for(auto j:degree[ansd])
	{
		cout<<ansd<<" "<<j<<endl;
		merge(ansd,j);
	}
	for(auto j:edges)
	{
		if(parent(j.F)!=parent(j.S))
		{
			cout<<j.F<<" "<<j.S<<endl;
			merge(j.F,j.S);
		}
	}
	
	return 0;
}