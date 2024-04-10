#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (int)a.size()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountint(x)
//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int power(int b,int e,int m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
int power( int b, int e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

const int N=1000005;
int n;
vector<int> v[N],vec[N];
int sub[N],dep[N];
void pre(int s,int p=-1)
{
	for(int j:v[s])
	{
		if(j!=p)
		{
			dep[j]=dep[s]+1;
			pre(j,s);
			sub[s]+=sub[j];
		}
	}
	++sub[s];
}
struct node
{
	int mx,idx;
	node (): mx(-1),idx(-1){}
}fake;
struct SEGTREE
{
	int a[N];
	SEGTREE(){ mem0(a); }
	node tree[4*N];
	inline node combine(node a,node b)
	{
		node ret;
		ret.mx=max(a.mx,b.mx);
		if(ret.mx==a.mx)
			ret.idx=a.idx;
		else
			ret.idx=b.idx;
		return ret;
	}
	inline node make_node(int val,int st)
	{
		node ret;
		ret.mx=val;
		ret.idx=st;
		return ret;
	}
	void buildTree(int v,int st,int en)
	{
		if(st==en)
		{
			tree[v]=make_node(a[st],st);
			return ;
		}
		int mid=(st+en)>>1;
		buildTree(v<<1,st,mid);
		buildTree(v<<1 | 1,mid+1,en);
		tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
	}
	void update(int v,int st,int en,int in,int val)
	{
		int mid=(st+en)>>1;
		if(st==en)
		{
			tree[v]=make_node(val,en);
			a[st]=val;
			return ;
		}
		if(in<=mid)
			update(v<<1,st,mid,in,val);
		else
			update(v<<1 | 1,mid+1,en,in,val);
		tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
	}
	node query(int v,int st,int en,int l,int r)
	{
		if(en<l || st>r)
			return fake;
		if(st>=l && en<=r)
			return tree[v];
		int mid=(st+en)>>1;
		return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
	}
}seg;
int ans[N];
inline void add(int v)
{
	seg.a[dep[v]]++;
	seg.update(1,0,n-1,dep[v],seg.a[dep[v]]);
}
inline void del(int v)
{
	seg.a[dep[v]]--;
	seg.update(1,0,n-1,dep[v],seg.a[dep[v]]);
}
void dfs(int s=1,int p=-1,int bors=1)
{
	int mx=-1,bc=-1;
	for(int j:v[s])
		if(j!=p)
			if(mx<sub[j])
				mx=sub[j],bc=j;
	for(int j:v[s])
		if(j!=p && j!=bc)
			dfs(j,s,0);
	if(bc!=-1)
	{
		dfs(bc,s,1);
		swap(vec[s],vec[bc]);
	}
	vec[s].pb(s);
	add(s);
	for(int j:v[s])
		if(j!=p && j!=bc)
			for(int k:vec[j])
				add(k),vec[s].pb(k);
	ans[s]=seg.query(1,0,n-1,0,n-1).idx-dep[s];
	if(!bors)
		for(auto j:vec[s])
			del(j);
}
int _runtimeTerror_()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;++i)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(y);v[y].pb(x);
	}
	pre(1);
	seg.buildTree(1,0,n-1);
	dfs();
	for(int i=1;i<=n;++i)
		printf("%d\n",ans[i]);
	return 0;
}

int main()
{
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