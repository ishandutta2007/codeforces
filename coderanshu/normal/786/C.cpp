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
#define popcount(x) __builtin_popcountll(x)
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
const int N=100005;
const int NN=N*45;
ll a[N],n;
struct node{
	ll val,L,R;
	node (): L(-1),R(-1),val(0){};
	node(ll x) : L(-1),R(-1),val(x){};
};
ll lst[N];
struct PERTREE{
	node tree[NN];
	int cursz=0;
	ll buildTree(ll st,ll en)
	{
		ll v = cursz++;
		tree[v]=node();
		if(st==en)
			return v;
		ll mid=(st+en)>>1;
		tree[v].L=buildTree(st,mid);
		tree[v].R=buildTree(mid+1,en); 
		return v;
	}
	ll update(ll v,ll st,ll en,ll pos,ll val)
	{
		ll u=cursz++;
		tree[u]=node(tree[v].val+val);
		if(st==en)
			return u;
		ll mid=(st+en)>>1;
		if(pos<=mid)
			tree[u].L=update(tree[v].L,st,mid,pos,val);
		else 
			tree[u].R=update(tree[v].R,mid+1,en,pos,val);
		tree[u].L=(tree[u].L==-1)?tree[v].L:tree[u].L;
		tree[u].R=(tree[u].R==-1)?tree[v].R:tree[u].R;
		return u;
	}
	ll query(ll v,ll st,ll en,ll k)
	{
		if(tree[v].val<=k)
			return en+1;
		if(st==en)
			return st;
		ll mid=(st+en)>>1;
		if(k<tree[tree[v].L].val)
			return query(tree[v].L,st,mid,k);
		else
			return query(tree[v].R,mid+1,en,k-tree[tree[v].L].val);
	}
};
PERTREE seg;
ll roots[N];
int _runtimeTerror_()
{
	ll i;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	for(i=1;i<=n+2;++i)
		lst[i]=-1;
	ll root= seg.buildTree(0,n-1);
	roots[n]=root;
	for(i=n-1;i>=0;--i)
	{
		root=roots[i+1];
		if(lst[a[i]]!=-1)
			root=seg.update(root,0,n-1,lst[a[i]],-1);
		lst[a[i]]=i;
		roots[i]=seg.update(root,0,n-1,i,1);
	}
	int x=1;
	//cout<<seg.query(roots[1],0,n-1,1)<<endl;
	for(i=1;i<=n;++i)
	{
		ll ans=0;
		ll pos=0;
		while(pos<n)
		{
			pos=seg.query(roots[pos],0,n-1,i);
			++ans;
		}
		cout<<ans<<" ";
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
	cerr<<"\n"<<_time_;
	return 0;
}
// farthest index and the nearest index are very different bc