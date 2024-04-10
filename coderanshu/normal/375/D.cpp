#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define aint(v) v.begin(),v.end()
#define sz(a) (int)a.size()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
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

const int N=100005;
struct node{
	int l,r,idx,val;
}Q[N];
int a[N],A[N],bit[N],freq[N],color[N];
int n;
void update(int idx,int val)
{
	for(int j=idx;j<=n;j+=j&-j)
		bit[j]+=val;
}
int query(int r)
{
	int ret=0;
	while(r>0)
	{
		ret+=bit[r];
		r-=r&-r;
	}
	return ret;
}
/*make freq array*/
inline void add(int i,int &ans)
{
	if(freq[color[a[i]]]>0)
		update(freq[color[a[i]]],-1);
	freq[color[a[i]]]++;
	update(freq[color[a[i]]],1);
}
inline void del(int i,int &ans)
{
	update(freq[color[a[i]]],-1);
	freq[color[a[i]]]--;
	if(freq[color[a[i]]])
		update(freq[color[a[i]]],1);
}
vector<int> v[N];
int in[N],out[N],cur=1;
bool vis[N];
void dfs(int s=1)
{
	vis[s]=true;
	a[cur]=s;
	in[s]=cur++;
	for(auto j:v[s])
	{
		if(!vis[j])
			dfs(j);
	}
	out[s]=cur-1;
}
void MO(int n,int q)
{
	int BLOCK=max((int)(n/sqrt(q)),1);
	sort(Q,Q+q,[&](node &a,node &b){if(a.l/BLOCK==b.l/BLOCK)return a.r<b.r;return a.l/BLOCK<b.l/BLOCK;});
	int ans=0,curL=1,curR=0;
	for(int i=0;i<q;++i)
	{
		while(curR<Q[i].r)add(++curR,ans);
		while(curR>Q[i].r)del(curR--,ans);
		while(curL<Q[i].l)del(curL++,ans);
		while(curL>Q[i].l)add(--curL,ans);
		A[Q[i].idx]=query(n)-query(min(n,Q[i].val-1));
	}
}
int _runtimeTerror_()
{
	int m,i;
	cin>>n>>m;
	for(i=1;i<=n;++i)
		cin>>color[i];
	for(int i=0;i<n-1;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}
	dfs();
	for(i=0;i<m;++i)
	{
		int vv;
		cin>>vv>>Q[i].val;
		Q[i].idx=i;
		Q[i].l=in[vv];
		Q[i].r=out[vv];
	}
	MO(n,m);
	for(i=0;i<m;++i)
		cout<<A[i]<<endl;	
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