#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define pb push_back
#define mem0(a)	memset(a,0,sizeof(a))
#define mem1(a)	memset(a,-1,sizeof(a))
#define memf(a)	memset(a,false,sizeof(a))
#define aint(v) v.begin(),v.end()
#define sz(a) (int)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountint(x)
#define pint pair<int,int> 
#define ld long double

const long double PI = acos(-1);
//comment
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
struct node
{
	int sum=0;
};
struct SEGTREE
{
	int a[N];
	SEGTREE(){ mem0(a); }
	node tree[4*N];
	inline node combine(node a,node b)
	{
		node ret;
		ret.sum=a.sum+b.sum;
		return ret;
	}
	inline node make_node(int val)
	{
		node ret;
		ret.sum=val;
		return ret;
	}
	void buildTree(int v,int st,int en)
	{
		if(st==en)
		{
			tree[v]=make_node(a[st]);
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
	int query(int v,int st,int en,int k)
	{	
		if(st==en)
			return st;
		int mid=(st+en)>>1;
		if(tree[v<<1].sum>=k)
			return query(v<<1,st,mid,k);
		else
			return query((v<<1 | 1),mid+1,en,k-tree[v<<1].sum);
	}
}seg;
int _runtimeTerror_()
{
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;++i)
	{
		int x;
		cin>>x;
		seg.a[x]++;
	}
	seg.buildTree(1,1,n);
	for(int i=0;i<q;++i)
	{
		int k;
		cin>>k;
		if(k>0)
		{
			++seg.a[k];
			seg.update(1,1,n,k,seg.a[k]);
		}
		else
		{
			int idx=seg.query(1,1,n,-k);
			seg.update(1,1,n,idx,--seg.a[idx]);
		}
	}
	for(int i=1;i<=n;++i)
		if(seg.a[i])
		{
			cout<<i;exit(0);
		}
	cout<<0;
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