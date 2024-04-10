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

const int N=0;

const int maxn=1e6+5;
struct node{
	int v=-1e17;
	int lazy=0;
	node(){}
	void assign(int val)
	{
		v=val;
	}
	void merge(node &l,node &r)
	{
		v=max(l.v,r.v);
	}
}zero;
struct segtree{
	node t[4*maxn];
public:
	//if a node has lazy tag then its info is correct but its children's info
	//is old, so pushdown() before going into children
	void pushdown(int v,int tl,int tr)
	{
		int ln=v*2;
		int rn=v*2+1;
		int tm=(tl+tr)/2;
		if(t[v].lazy){
			apply(ln,tl,tm,t[v].lazy);
			apply(rn,tm+1,tr,t[v].lazy);
			t[v].lazy=0;
		}
	}
	//apply() is an auxillary function to apply range update and set lazy tag
	void apply(int v,int tl,int tr,int val)
	{
		if(tl!=tr){
			t[v].lazy+=val;
		}
		t[v].v+=val;
	}
	void build(int a[], int v, int tl, int tr) {
		if (tl == tr) {
			t[v].assign(a[tl]);
			return;
		} else {
			int tm = (tl + tr) / 2;
			build(a, v*2, tl, tm);
			build(a, v*2+1, tm+1, tr);
			t[v].merge(t[v*2],t[v*2+1]);
		}
	}
	void build(int a[]){
		build(a,1,0,maxn-1);
	}
	node query(int v, int tl, int tr, int l, int r) {
		if (l > tr || r < tl)
			return zero;
		if (l <= tl && tr <= r) {
			return t[v];
		}
		pushdown(v,tl,tr);
		int tm = (tl + tr) / 2;
		node a,b,ans;
		a=query(v*2, tl, tm, l, r);
		b=query(v*2+1, tm+1, tr, l, r);
		ans.merge(a,b);
		return ans;
	}
	node query(int l,int r){
		return query(1,0,maxn-1,l,r);
	}
	void rupd(int v, int tl, int tr, int l, int r, int val)
	{
		if(l > tr || r < tl)
			return;
		if(l <= tl && tr <= r)
		{
			apply(v,tl,tr,val);
			return;
		}
		pushdown(v,tl,tr);
		int tm = (tl + tr)/2;
		rupd(v*2,tl,tm,l,r,val);
		rupd(v*2+1,tm+1,tr,l,r,val);
		t[v].merge(t[v*2],t[v*2+1]);
	}
	void rupd(int l,int r,int val){
		rupd(1,0,maxn-1,l,r,val);
	}
}t;

int bui[maxn];
map<int, int> a,b;

void solve(){
	int n,m,p;
	cin>>n>>m>>p;
	vector<pair<pii, pii>> q;
	rep(i,0,n){
		int t,z;
		cin>>t>>z;
		if(!a.count(t))a[t]=z;
		amin(a[t],z);
	}
	rep(i,0,m){
		int t,z;
		cin>>t>>z;
		if(!b.count(t))b[t]=z;
		amin(b[t],z);
	}
	rep(i,0,p){
		int x,y,z;
		cin>>x>>y>>z;
		q.pb({{x,1},{y,z}});
	}
	for(pii x:a){
		q.pb({{x.fr,0},{x.sc,0}});
	}
	rep(i,0,maxn)bui[i]=-1e16;
	for(pii x:b){
		bui[x.fr]=-x.sc;
	}
	t.build(bui);
	sort(all(q));
	int ans=-1e17;
	for(auto r:q){
		if(r.fr.sc){
			t.rupd(r.sc.fr+1,maxn,r.sc.sc);
		}
		else{
			amax(ans,t.query(0,maxn).v - r.sc.fr);
		}
	}
	cout<<ans;
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
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}