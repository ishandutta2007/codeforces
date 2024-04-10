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
const int N=100005;
ll a[N],tree[4*N][22],lazy[4*N];
void buildTree(ll v,ll st,ll en)
{
	if(st==en)
	{
		for(int i=0;i<21;++i)
		{
			if(a[st]&(1<<i))
				tree[v][i]=1;
		}
		tree[v][21]=a[st];
		return ;
	}
	ll mid=(st+en)>>1;
	buildTree(v<<1,st,mid);
	buildTree(v<<1 | 1,mid+1,en);
	for(int i=0;i<22;++i)
		tree[v][i]=tree[v<<1][i]+tree[v<<1 | 1][i];
}
void checkup(ll v,ll st,ll en)
{
	for(int i=0;i<21;++i)
	{
		if(lazy[v]&(1<<i))
		{
			ll x=en-st+1-tree[v][i];
			ll y=x-tree[v][i];
			tree[v][i]=x;
			tree[v][21]+=y*power(2,i);
		}
	}
	if(st!=en)
	{
		lazy[v<<1]^=lazy[v];
		lazy[v<<1 | 1]^=lazy[v];
	}
	lazy[v]=0;
	return ;
}
void update(ll v,ll l,ll r,ll st,ll en,ll val)
{
	if(lazy[v]!=0)
		checkup(v,st,en);
	if(st>r || en<l)return ;
	if(st>=l && en<=r)
	{
		lazy[v]=val;
		checkup(v,st,en);
		return ;
	}
	ll mid=(st+en)>>1;
	update(v<<1,l,r,st,mid,val);
	update(v<<1 | 1,l,r,mid+1,en,val);
	for(int i=0;i<22;++i)
		tree[v][i]=tree[v<<1][i]+tree[v<<1 | 1][i];
}
ll query(ll v,ll l,ll r,ll st,ll en)
{
	if(st>r || en<l)return 0;
	if(lazy[v]!=0)
	{
		checkup(v,st,en);
	}
	if(st>=l && en<=r)
		return tree[v][21];
	ll mid=(st+en)>>1;
	return query(v<<1,l,r,st,mid)+query(v<<1 | 1,l,r,mid+1,en);
}
int _runtimeTerror_()
{
	ll n,i,m;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	buildTree(1,0,n-1);
	cin>>m;
	while(m--)
	{
		ll t,l,r,val;
		cin>>t>>l>>r;
		if(t==1)
			cout<<query(1,l-1,r-1,0,n-1)<<endl;
		else
		{
			cin>>val;
			update(1,l-1,r-1,0,n-1,val);
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef runSieve
		sieve();
	#endif
	#ifdef NCR
		initialize();
	#endif
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}