#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define sz(a) (int)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountint(x)

const long double PI = acos(-1);

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T , null_type ,less<T> ,rb_tree_tag ,tree_order_statistics_node_update>;
const int N=200005;
int n,m,a[N],b[N],pos[N],posa[N];
struct node
{
	ordered_set<int> s;
}fake;
template<typename T>
class fenwick {
public:
	T a[N]{};
	node bit[N];
	void build(int st,int en)
	{
		for(int i=st;i<=en;++i)
		{
			for(int j=i;j<=en;j+=j&-j)
				bit[j].s.insert(a[i]);
		}
	}
	void update(int st,int en,int in,bool deloradd,T val)
	{
		for(int j=in;j<=en;j+=j&-j)
		{
			if(deloradd)
				bit[j].s.insert(val);
			else bit[j].s.erase(val);
		}
	}
	T get(int r,int p1,int p2)
	{
		T x{};
		while(r>0)
		{
			x+=bit[r].s.order_of_key(p2+1)-bit[r].s.order_of_key(p1);
			r-=r&-r;
		}
		return x;
	}
	T query(int l,int r,int p1,int p2)
	{
		return get(r,p1,p2)-get(l-1,p1,p2);
	}
};
int _runtimeTerror_()
{
	fenwick<int> fenw;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		posa[a[i]]=i;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>b[i];
		pos[b[i]]=i;
	}
	for(int i=1;i<=n;++i)
		fenw.a[i]=pos[a[i]];
	fenw.build(1,n);
	for(int i=1;i<=m;++i)
	{
		int tt;
		cin>>tt;
		if(tt==1)
		{
			int la,lb,ra,rb;
			cin>>la>>ra>>lb>>rb;
			int ans=fenw.query(la,ra,lb,rb);
			cout<<ans<<'\n';
		}
		else
		{
			int x,y;
			cin>>x>>y;
			int xx=b[x],yy=b[y];
			swap(b[x],b[y]);
			swap(pos[x],pos[y]);
			fenw.a[posa[xx]]=y;
			fenw.a[posa[yy]]=x;
			//int xy=min(posa[xx],posa[yy]),yx=max(posa[xx],posa[yy]);
			fenw.update(1,n,posa[yy],0,y);
			fenw.update(1,n,posa[xx],0,x);
			fenw.update(1,n,posa[yy],1,x);
			fenw.update(1,n,posa[xx],1,y);
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
	cerr<<"\n"<<_time_;
	return 0;
}