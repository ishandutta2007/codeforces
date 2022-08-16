#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
// #define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T>pair<T,T> operator+=(pair<T,T> &a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-=(pair<T,T> &a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T>pair<T,T> operator+(pair<T,T> a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-(pair<T,T> a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const int INF=1e18;

const int N=1e5+5;
const int32_t maxn=N;
struct node{
	long long v=0;
	int cnt[20]={};
	node(){}
	node(int val){
		v=val;
		rep(i,0,20){
			cnt[i]=(val>>i)&1;
		}
	}
	void merge(node &l,node &r)
	{
		v=l.v+r.v;
		rep(i,0,20){
			cnt[i]=l.cnt[i]+r.cnt[i];
		}
	}
}zero;
struct update{
	int v;
	update(){}
	update(int val){
		v=val;
	}
	void combine(update &other,int32_t tl,int32_t tr){
		v^=other.v;
	}
	void apply(node &x,int32_t tl,int32_t tr){
		rep(i,0,20){
			if((v>>i)&1){
				x.v+=(1LL*tr-tl+1-x.cnt[i]*2)<<i;
				x.cnt[i]=(tr-tl+1-x.cnt[i]);
			}
		}
	}
}noop;
struct segtree{
	bool built=false;
	node t[4*maxn];
	bool lazy[4*maxn];
	update upds[4*maxn];
	int32_t tl[4*maxn];
	int32_t tr[4*maxn];
	inline void pushdown(int32_t v)
	{
		if(lazy[v]){
			apply(v*2,upds[v]);
			apply(v*2+1,upds[v]);
			lazy[v]=0;
			upds[v]=noop;
		}
	}
	inline void apply(int32_t v,update &val)
	{
		if(tl!=tr){
			lazy[v]=1;
			upds[v].combine(val,tl[v],tr[v]);
		}
		val.apply(t[v],tl[v],tr[v]);
	}
	template<typename T>
	void build(T a, int32_t v, int32_t l, int32_t r) {
		tl[v]=l;
		tr[v]=r;
		if (l == r) {
			t[v]=a[l];
			return;
		} else {
			int32_t tm = (l + r) / 2;
			build(a, v*2, l, tm);
			build(a, v*2+1, tm+1, r);
			t[v].merge(t[v*2],t[v*2+1]);
		}
	}
	node query(int32_t v, int l, int r) {
		if (l > tr[v] || r < tl[v])
			return zero;
		if (l <= tl[v] && tr[v] <= r) {
			return t[v];
		}
		pushdown(v);
		node a,b,ans;
		a=query(v*2, l, r);
		b=query(v*2+1, l, r);
		ans.merge(a,b);
		return ans;
	}
	void rupd(int32_t v, int l, int r, update &val)
	{
		if(l > tr[v] || r < tl[v])
			return;
		if(l <= tl[v] && tr[v] <= r)
		{
			apply(v,val);
			return;
		}
		pushdown(v);
		rupd(v*2,l,r,val);
		rupd(v*2+1,l,r,val);
		t[v].merge(t[v*2],t[v*2+1]);
	}
public:
	int len=maxn;
	void clear(){
		rep(i,0,4*len){
			t[i]=zero;
			lazy[i]=0;
			upds[i]=noop;
		}
	}
	template<typename T>
	void build(T a){
		build(a,1,0,len-1);
		built=true;
	}
	node query(int l,int r){
		if(!built)build(t);
		return query(1,l,r);
	}
	void rupd(int l,int r,update val){
		if(!built)build(t);
		rupd(1,l,r,val);
	}
}t;

int a[N];
void solve(){
	int n;
	cin>>n;
	rep(i,1,n+1){
		cin>>a[i];
	}
	t.build(a);
	int m;
	cin>>m;
	rep(zz,0,m){
		int type,l,r;
		cin>>type>>l>>r;
		if(type==1){
			cout<<t.query(l,r).v<<"\n";
		}
		else{
			int x;
			cin>>x;
			t.rupd(l,r,x);
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}