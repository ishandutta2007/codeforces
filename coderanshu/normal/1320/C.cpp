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
#define INF 2000000000000000000
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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
struct nodee{
	ll x,y,z;
};
const int N=1000005;
ll a[1000005];
struct node
{
	ll mx;
}fake={-INF};
// base value is assigned to fake node
node tree[4*N];
ll lazy[4*N];
inline node combine(node a,node b)
{
	node ret;
	ret.mx=max(a.mx,b.mx);
	return ret;
}
inline node make_node(ll val)
{
	node ret;
	ret.mx=val;
	return ret;
}
inline void pushdown(ll v,ll st,ll en)
{
	tree[v].mx+=lazy[v];
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
	ll n,m,p,i;
	cin>>n>>m>>p;
	for(i=0;i<=1000000;++i)
		a[i]=-INF;
	pair<ll,ll> pp[n];
	for(i=0;i<n;++i)
		cin>>pp[i].F>>pp[i].S;
	sort(pp,pp+n);
	for(i=0;i<m;++i)
	{
		ll b,cb;
		cin>>b>>cb;
		amax(a[b],-cb);
	}
	buildTree(1,0,1000000);
	nodee qq[p];
	for(i=0;i<p;++i)
		cin>>qq[i].x>>qq[i].y>>qq[i].z;
	sort(qq,qq+p,[&](nodee a,nodee b){return a.x<b.x;});
	ll cur=0;
	ll ans=-INF;
	for(i=0;i<n;++i)
	{
		while(qq[cur].x<pp[i].F && cur<p)
		{
			rupdate(1,0,1000000,qq[cur].y+1,1000000,qq[cur].z);
			++cur;
		}
		amax(ans,query(1,0,1000000,0,1000000).mx-pp[i].S);
	}
	cout<<ans<<endl;
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
	cerr<<"\n"<<_time_;
	return 0;
}