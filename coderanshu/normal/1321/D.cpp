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
ll level[200005];
vector<ll> v[200005],v2[200005];
bool vis[200005];
void bfs(ll s)
{
	vis[s]=true;
	queue<ll> q;
	q.push(s);
	while(!q.empty())
	{
		ll t=q.front();q.pop();
		for(auto j:v[t])
		{
			if(!vis[j])
			{
				vis[j]=true;
				level[j]=level[t]+1;
				q.push(j);
			}
		}
	}
}
int _runtimeTerror_()
{
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;++i){level[i]=-2;}
	while(m--)
	{
		ll x,y;
		cin>>x>>y;
		v[y].pb(x);v2[x].pb(y);// inverted the graph
	}
	ll k,i,j;cin>>k;
	ll a[k];
	for(i=0;i<k;++i)
	{
		cin>>a[i];
	}
	level[a[k-1]]=0;
	bfs(a[k-1]);
	ll z=level[a[0]];
	ll mi=0,ma=0;
	for(i=1;i<k-1;++i)
	{
		//cout<<level[a[i]]<<" ";
		if(level[a[i]]==z-1){--z;continue;}
		z=level[a[i]];++mi;
	}
	//cout<<endl<<level[2];
	cout<<mi<<" ";
	z=level[a[0]];
	ll count=0;
	for(auto j:v2[a[0]])
	{
		if(level[j]==level[a[0]]-1)
			count++;	
	}
	//set<ll> s;
	//s.insert(a[0]);
	for(i=1;i<k-1;++i)
	{
		if(level[a[i]]!=z-1){++ma;}
		else
		{
			if(count>1)++ma;
		}
		z=level[a[i]];
		count=0;
		for(auto j:v2[a[i]])
		{
			if(level[j]==level[a[i]]-1)count++;
		}
		//s.insert(a[i]);
	}
	cout<<ma;
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