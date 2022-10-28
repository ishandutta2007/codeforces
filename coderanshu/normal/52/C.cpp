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
#define INF 2e17
#define endl "\n"
#define llevel 20
ll power(ll b,ll e,ll m)
{
	return (!e)?1:power(b*b%m,e/2,m)*(e&1?b:1)%m;
}
ll power( ll b, ll e)
{
	return (!e)?1:power(b*b,e/2)*(e&1?b:1);
}
ll a[200005],tree[800005],lazy[800005];
void buildTree(ll v,ll st,ll en)
{
	if(st==en)
	{
		tree[v]=a[st];
		return ;
	}
	ll mid=(st+en)>>1;
	buildTree(v<<1,st,mid);
	buildTree(v<<1 | 1,mid+1,en);
	tree[v]=min(tree[v<<1],tree[v<<1 | 1]);
}
void updateTree(ll v,ll l,ll r,ll st,ll en,ll val)
{
	if(lazy[v]!=0)
	{
		tree[v]+=lazy[v];
		if(st!=en)
		{
			lazy[v<<1]+=lazy[v];lazy[v<<1 | 1]+=lazy[v];
		}
		lazy[v]=0;
	}
	if(en<l || st>r)return ;
	if(st>=l && en<=r)
	{
		tree[v]+=val;
		if(st!=en)
		{
			lazy[v<<1]+=val;lazy[v<<1 | 1]+=val;
		}
		return ;
	}
	ll mid=(st+en)>>1;
	updateTree(v<<1,l,r,st,mid,val);
	updateTree(v<<1 | 1,l,r,mid+1,en,val);
	tree[v]=min(tree[v<<1],tree[v<<1 | 1]);
}
ll query(ll v,ll l,ll r,ll st,ll en)
{
	if(en<l || st>r)return INF;
	if(lazy[v]!=0)
	{
		tree[v]+=lazy[v];
		if(st!=en)
		{
			lazy[v<<1]+=lazy[v];lazy[v<<1 | 1]+=lazy[v];
		}
		lazy[v]=0;
	}
	if(l<=st && en<=r)
		return tree[v];
	ll mid=(st+en)>>1;
	return min(query(v<<1,l,r,st,mid),query(v<<1 | 1,l,r,mid+1,en));
}	
int _runtimeTerror_()
{
	ll n,i,m;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	buildTree(1,0,n-1);
	cin>>m;
	string s;
	getline(cin,s);
	for(i=0;i<m;++i)
	{
		getline(cin,s);
		ll fo;vector<ll> v;
		istringstream x(s);
		while(x>>fo)
			v.pb(fo);
		if(sz(v)==3)
		{
			if(v[0]<=v[1])updateTree(1,v[0],v[1],0,n-1,v[2]);
			else
			{
				updateTree(1,v[0],n-1,0,n-1,v[2]);
				updateTree(1,0,v[1],0,n-1,v[2]);
			}
		}
		else
		{
			if(v[0]<=v[1])
				cout<<query(1,v[0],v[1],0,n-1)<<endl;
			else
			{
				cout<<min(query(1,v[0],n-1,0,n-1),query(1,0,v[1],0,n-1))<<endl;
			}
		}
	}
	return 0;
}

signed main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef runSieve
		sieve();
	#endif
	#ifdef NCR
		initialize();
	#endif
	ll TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}