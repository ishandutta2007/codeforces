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
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
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
template<typename T, typename U> static inline void setmin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void setmax(T &x, U y){ if(x<y) x=y; }
map<ll,queue<ll>> m;
const int N=300005;
ll a[N],b[N];
struct node
{
	ll sum;
}fake={2000000000};
// base value is assigned to fake node
node tree[4*N];
ll lazy[4*N];
inline node combine(node a,node b)
{
	node ret;
	ret.sum=min(a.sum,b.sum);
	return ret;
}
inline node make_node(ll val)
{
	node ret;
	ret.sum=val;
	return ret;
}
inline void pushdown(ll v,ll st,ll en)
{
	tree[v].sum+=(en-st+1)*lazy[v];
	if(st!=en)
	{
		lazy[v<<1]+=lazy[v];
		lazy[v<<1 | 1]+=lazy[v];
	}
	lazy[v]=0;
	return ;
}
void buildTree(ll v,ll st,ll en)
{
	if(st==en)
	{
		tree[v]=make_node(a[st]);
		return ;
	}
	ll mid=(st+en)>>1;
	buildTree(v<<1,st,mid);
	buildTree(v<<1 | 1,mid+1,en);
	tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
}
void update(ll v,ll st,ll en,ll in,ll val)
{
	ll mid=(st+en)>>1;
	if(st==en)
	{
		tree[v]=make_node(val);
		a[st]=val;
		return ;
	}
	if(in<=mid)
		update(v<<1,st,mid,in,val);
	else
		update(v<<1 | 1,mid+1,en,in,val);
	tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
}
void rupdate(ll v,ll st,ll en,ll l,ll r,ll val)
{
	if(lazy[v]!=0)
	{
		pushdown(v,st,en);
	}
	if(en<l || st>r)return ;
	if(st>=l && en<=r)
	{
		lazy[v]=val;
		pushdown(v,st,en);
		return ;
	}
	ll mid=(st+en)>>1;
	rupdate(v<<1,st,mid,l,r,val);
	rupdate(v<<1 | 1,mid+1,en,l,r,val);
	tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
}
node query(ll v,ll st,ll en,ll l,ll r)
{
	if(en<l || st>r)
		return fake;
	if(lazy[v]!=0)
	{
		pushdown(v,st,en);
	}
	if(st>=l && en<=r)
		return tree[v];
	ll mid=(st+en)>>1;
	return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
}
int _runtimeTerror_()
{
	m.clear();
	ll n,i;
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>a[i];
		m[a[i]].push(i);
	}
	for(i=0;i<n;++i)
	{
		cin>>b[i];
	}
	buildTree(1,0,n-1);
	for(i=0;i<n;++i)
	{
		if(sz(m[b[i]])==0)
		{
			cout<<"NO\n";return 0;
		}
		ll k=m[b[i]].front();m[b[i]].pop();
		if(k==0)
		{
			update(1,0,n-1,0,INF);continue;
		}
		node ans=query(1,0,n-1,0,k-1);
		if(ans.sum<=b[i])
		{
			cout<<"NO\n";return 0;
		}
		update(1,0,n-1,k,INF);
	}
	cout<<"YES\n";
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
	cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	cerr<<"\n"<<_time_;
	return 0;
}