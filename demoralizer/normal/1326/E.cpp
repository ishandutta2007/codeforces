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

const int INF=1e9;

const int N=3e5+5;

const int32_t maxn=N;
template<typename NODE,typename UPDATE>
struct segtree{
	bool built=false,lazy[4*maxn];
	NODE zero=NODE(),t[4*maxn];
	UPDATE noop=UPDATE(),upds[4*maxn];
	int32_t tl[4*maxn],tr[4*maxn];
	inline void pushdown(int32_t v)
	{
		if(lazy[v]){
			apply(v*2,upds[v]);
			apply(v*2+1,upds[v]);
			lazy[v]=0;
			upds[v]=noop;
		}
	}
	inline void apply(int32_t v,UPDATE &val)
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
	NODE query(int32_t v, int l, int r) {
		if (l > tr[v] || r < tl[v])
			return zero;
		if (l <= tl[v] && tr[v] <= r) {
			return t[v];
		}
		pushdown(v);
		NODE a,b,ans;
		a=query(v*2, l, r);
		b=query(v*2+1, l, r);
		ans.merge(a,b);
		return ans;
	}
	void rupd(int32_t v, int l, int r, UPDATE &val)
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
	template<typename T>
	int descent_right(int l, T x, int32_t v, NODE &prev) {
		if (l > tr[v])
			return len;
		NODE cur=t[v];
		cur.merge(prev,t[v]);
		if (!cur.check(x)){
			if(l<=tl[v])swap(cur,prev);
			return len;
		}
		if (tl[v]==tr[v]) {
			return tr[v];
		}
		pushdown(v);
		int ans=descent_right(l, x, v*2, prev);
		if(ans!=len)return ans;
		return descent_right(l, x, v*2+1, prev);
	}
	template<typename T>
	int descent_left(int r, T x, int32_t v, NODE &prev) {
		if (r < tl[v])
			return -1;
		NODE cur;
		cur.merge(t[v],prev);
		if (!cur.check(x)){
			if(r>=tr[v])swap(cur,prev);
			return -1;
		}
		if (tl[v]==tr[v]) {
			return tl[v];
		}
		pushdown(v);
		int ans=descent_left(r, x, v*2+1, prev);
		if(ans!=-1)return ans;
		return descent_left(r, x, v*2, prev);
	}
	
	int len=maxn;
	void clear(){
		fill(t,t+4*len,zero);
		fill(lazy,lazy+4*len,false);
		fill(upds,upds+4*len,noop);
	}
	template<typename T>
	void build(T a){
		build(a,1,0,len-1);
		built=true;
	}
	template<typename T>
	int descent_right(int l, T x) {
		NODE prev=zero;
		return descent_right(l,x,1,prev);
	}
	template<typename T>
	int descent_left(int r, T x) {
		NODE prev=zero;
		return descent_left(r,x,1,prev);
	}
	NODE query(int l,int r){
		if(!built)build(t);
		return query(1,l,r);
	}
	void rupd(int l,int r,UPDATE val){
		if(!built)build(t);
		rupd(1,l,r,val);
	}
};

#define node node1
#define update update1
struct node{
	int v=0;
	int id;
	node(){}
	node(pii x){
		v=x.fr;
		id=x.sc;
	}
	void merge(node &l,node &r)
	{
		if(l.v>r.v){
			v=l.v;
			id=l.id;
		}
		else{
			v=r.v;
			id=r.id;
		}
	}
};
struct update{
	int v;
	update(){}
	update(int val){
		v=val;
	}
	void combine(update &other,int32_t tl,int32_t tr){
		
	}
	void apply(node &x,int32_t tl,int32_t tr){
		x.v=v;
	}
};
segtree<node,update> t;
#undef node
#undef update

#define node node2
#define update update2
struct node{
	int v=INF;
	node(){}
	node(int val){
		v=val;
	}
	void merge(node &l,node &r)
	{
		v=min(l.v,r.v);
	}
	bool check(int x){
		return (v<=x);
	}
};
struct update{
	int v=0;
	update(){}
	update(int val){
		v=val;
	}
	void combine(update &other,int32_t tl,int32_t tr){
		v+=other.v;
	}
	void apply(node &x,int32_t tl,int32_t tr){
		x.v+=v;
	}
};
segtree<node,update> t2;
#undef node
#undef update



pii p[N];
int a[N];
void solve(){
	t2.build(a);
	int n;
	cin>>n;
	rep(i,1,n+1){
		cin>>p[i].fr;
		p[i].sc=i;
	}
	t.build(p);
	cout<<n<<" ";
	rep(zzz,0,n-1){
		int x;
		cin>>x;
		int ans=t2.descent_right(x,0);
		int k=t.query(1,ans).id;
		t.rupd(k,k,0);
		if(x>k)t2.rupd(k,x-1,1);
		else if(k>x)t2.rupd(x,k-1,-1);
		cout<<t.query(1,n).v<<" ";
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