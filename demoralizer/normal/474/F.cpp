#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
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
	int mn=INF,gcd=0,mnc=0;
	node(){}
	node(int val){
		mn=gcd=val;
		mnc=1;
	}
	void merge(node &l,node &r)
	{
		mn=min(l.mn,r.mn);
		gcd=__gcd(l.gcd,r.gcd);
		if(mn==l.mn)mnc+=l.mnc;
		if(mn==r.mn)mnc+=r.mnc;
	}
}zero;
struct update{
	
	update(){}
	update(int val){
		
	}
	void combine(update &other){
		
	}
	void apply(node &x){
		
	}
}noop;
struct segtree{
	node t[4*maxn];
	bool lazy[4*maxn];
	update upds[4*maxn];
	void pushdown(int32_t v,int32_t tl,int32_t tr)
	{
		int32_t tm=(tl+tr)/2;
		if(lazy[v]){
			apply(v*2,tl,tm,upds[v]);
			apply(v*2+1,tm+1,tr,upds[v]);
			lazy[v]=0;
			upds[v]=noop;
		}
	}
	void apply(int32_t v,int32_t tl,int32_t tr,update &val)
	{
		if(tl!=tr){
			lazy[v]=1;
			upds[v].combine(val);
		}
		val.apply(t[v]);
	}
	template<typename T>
	void build(T a[], int32_t v, int32_t tl, int32_t tr) {
		if (tl == tr) {
			t[v]=a[tl];
			return;
		} else {
			int32_t tm = (tl + tr) / 2;
			build(a, v*2, tl, tm);
			build(a, v*2+1, tm+1, tr);
			t[v].merge(t[v*2],t[v*2+1]);
		}
	}
	node query(int32_t v, int32_t tl, int32_t tr, int l, int r) {
		if (l > tr || r < tl)
			return zero;
		if (l <= tl && tr <= r) {
			return t[v];
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) / 2;
		node a,b,ans;
		a=query(v*2, tl, tm, l, r);
		b=query(v*2+1, tm+1, tr, l, r);
		ans.merge(a,b);
		return ans;
	}
	void rupd(int32_t v, int32_t tl, int32_t tr, int l, int r, update &val)
	{
		if(l > tr || r < tl)
			return;
		if(l <= tl && tr <= r)
		{
			apply(v,tl,tr,val);
			return;
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr)/2;
		rupd(v*2,tl,tm,l,r,val);
		rupd(v*2+1,tm+1,tr,l,r,val);
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
	void build(T a[]){
		build(a,1,0,len-1);
	}
	node query(int l,int r){
		return query(1,0,len-1,l,r);
	}
	void rupd(int l,int r,update val){
		rupd(1,0,len-1,l,r,val);
	}
}t;

int s[N];
void solve(){
	int n;
	cin>>n;
	rep(i,1,n+1){
		cin>>s[i];
	}
	t.build(s);
	int q;
	cin>>q;
	rep(i,0,q){
		int l,r;
		cin>>l>>r;
		node ans=t.query(l,r);
		int k=r-l+1;
		if(ans.mn==ans.gcd){
			k-=ans.mnc;
		}
		cout<<k<<"\n";
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