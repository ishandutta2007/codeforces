#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007LL
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
struct DSU
{
	vector<ll> p,r,sz;
	DSU(ll n)
	{
		p.resize(n+10);r.resize(n+10);sz.resize(n+10);
		for(ll i=1;i<=n;++i)
		{
			p[i]=i;r[i]=0;sz[i]=1;
		}
	}
	ll parent(ll i)
	{
		if(i==p[i])return i;
		return p[i]=parent(p[i]);
	}	
	void merge(ll x,ll y)
	{
		x=parent(x);y=parent(y);
		if(x==y)return ;
		if(r[x]>r[y])
		{
			p[y]=x;sz[x]+=sz[y];sz[y]=0;
		}
		else
		{
			p[x]=y;sz[y]+=sz[x];sz[x]=0;
		}
		if(r[x]==r[y])++r[y];
	}
};
int _runtimeTerror_()
{
	ll n,k,i,ans=0;
	cin>>n>>k;
	DSU d(n);
	for(i=1;i<=n-1;++i)
	{
		ll x,y,l;
		cin>>x>>y>>l;
		if(l==1)continue;
		d.merge(x,y);
	}
	ans=power(n,k,M);
	for(i=1;i<=n;++i)
	{
		if(d.sz[i]==0)continue;
		ans=(ans+M-power(d.sz[i],k,M))%M;
	}
	cout<<ans<<endl;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int tests=1;
	//cin>>tests;
	while(tests--)
		_runtimeTerror_();
	return 0;
}