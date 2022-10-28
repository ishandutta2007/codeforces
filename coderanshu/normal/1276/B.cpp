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
ll p[200005],r[200005];
vector<ll> v[200005];
bool vis[200005];
void in(ll n)
{
	for(ll i=1;i<=n;++i)
	{
		p[i]=i;r[i]=0;v[i].clear();
	}
}
ll unvis(ll n)
{
	ll ret=0;
	for(ll i=1;i<=n;++i)
	{
		if(!vis[i])++ret;
	}
	return ret;
}
void in2(ll n)
{
	for(ll i=1;i<=n;++i)vis[i]=false;
}
void bfs(ll s,ll d,ll n)
{
	in2(n);
	vis[s]=true;
	queue<ll> q;
	q.push(s);
	while(!q.empty())
	{
		ll t=q.front();q.pop();
		if(t==d)continue;
		for(auto j:v[t])
		{
			if(!vis[j])
			{
				q.push(j);vis[j]=true;
			}
		}
	}return;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll t,i,m,n,a,b,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>a>>b;
		in(n);
		while(m--)
		{
			cin>>x>>y;v[x].pb(y);v[y].pb(x);
		}
		bfs(a,b,n);
		ll c1=unvis(n);bfs(b,a,n);ll c2=unvis(n);
		cout<<c1*c2<<endl;
	}
}