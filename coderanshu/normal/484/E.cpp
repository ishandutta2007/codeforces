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
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 

const long double PI = acos(-1);

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


const int N=100002,LOGN=20;
struct node{
	int l,r,val,pfx,sfx,len;
	node():l(-1),r(-1),val(0),pfx(0),sfx(0),len(0){}
}fake;
inline node make_node(int x)
{
	node ret;
	ret.sfx=ret.pfx=ret.val=x;
	ret.len=1;
	return ret;
}
int a[N];
node tree[N*LOGN];
int cursz=0;
inline void combine(int v,int l,int r)
{
	if(tree[l].len==tree[l].val)
		tree[v].pfx=tree[l].len+tree[r].pfx;
	else
		tree[v].pfx=tree[l].pfx;
	tree[v].len=tree[l].len+tree[r].len;
	tree[v].val=max(tree[l].val,max(tree[r].val,tree[l].sfx+tree[r].pfx));
	if(tree[r].len==tree[r].val)
		tree[v].sfx=tree[l].sfx+tree[r].len;
	else 
		tree[v].sfx=tree[r].sfx;
}
int buildTree(int st,int en)
{
	int v=cursz++;
	if(st==en)
	{
		tree[v]=make_node(0);
		return v;
	}
	int mid=(st+en)>>1;
	tree[v].l=buildTree(st,mid);
	tree[v].r=buildTree(mid+1,en);
	combine(v,tree[v].l,tree[v].r);
	return v;
}
int update(int u,int st,int en,int idx)
{
	int v=cursz++;
	if(st==en)
	{
		tree[v]=make_node(1);
		return v;
	}
	tree[v]=tree[u];
	int mid=(st+en)>>1;
	if(idx<=mid)
		tree[v].l=update(tree[u].l,st,mid,idx);
	else 
		tree[v].r=update(tree[u].r,mid+1,en,idx);
	combine(v,tree[v].l,tree[v].r);
	return v;
}
node func(node a,node b)
{
	node ret;
	if(a.len==a.val)
		ret.pfx=a.len+b.pfx;
	else
		ret.pfx=a.pfx;
	ret.len=a.len+b.len;
	ret.val=max({a.val,b.val,a.sfx+b.pfx});
	if(b.len==b.val)
		ret.sfx=a.sfx+b.len;
	else 
		ret.sfx=b.sfx;
	return ret;
}
node query(int u,int st,int en,int l,int r)
{
	if(l>en || r<st)
		return fake;
	if(st>=l && en<=r)
		return tree[u];
	int mid=(st+en)>>1;
	return func(query(tree[u].l,st,mid,l,r),query(tree[u].r,mid+1,en,l,r));
}
int b[N],c[N];
map<int,int> mp;
set<int> st;
int n;
bool check(int m,int l,int r,int w)
{
	auto it=st.lower_bound(m);
	assert(mp.count(*it));
	int idx=mp[*it];
	node ans=query(c[idx],0,n-1,l-1,r-1);
	if(ans.val>=w)
		return true;
	return false;
}
int _runtimeTerror_()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",a+i),b[i]=i;
	int m,mx;
	int root=buildTree(0,n-1);
	scanf("%d",&m);
	sort(b,b+n,[&](int x,int y){return a[x]>a[y];});
	//for(int i=0;i<n;++i)
	//	cout<<b[i]<<endl;
	mx=a[b[0]];
	for(int i=0;i<n;++i)
	{
		st.insert(a[b[i]]);
		mp[a[b[i]]]=i;
	}
	assert(mp.size()<=n);
	assert(st.size()<=n);
	int xx=root;
	for(int i=0;i<n;++i)
	{
		c[i]=update(xx,0,n-1,b[i]);
		xx=c[i];
	}
	for(int i=0;i<m;++i)
	{
		int l,r,w;
		cin>>l>>r>>w;
		int lo=1,hi=mx;
		//cout<<hi<<endl;
		while(lo<=hi)
		{
			int mid=(lo+hi)>>1;
			if(check(mid,l,r,w))
				lo=mid+1;
			else hi=mid-1;
		}
		cout<<lo-1<<endl;
	}
	return 0;
}
int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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