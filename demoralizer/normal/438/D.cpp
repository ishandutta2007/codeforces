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

const int N=1e5+5;

const int maxn=N;
struct node{
	int v,mn,mx;
	int lazy=0;
	bool flag;
	void assign(int val)
	{
		mn=mx=v=val;
	}
	void merge(node &l,node &r)
	{
		mx=max(l.mx,r.mx);
		mn=min(l.mn,r.mn);
		v=l.v+r.v;
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
		if(t[v].flag){
			apply(ln,tl,tm,t[v].lazy);
			apply(rn,tm+1,tr,t[v].lazy);
			t[v].flag=0;
		}
	}
	//apply() is an auxillary function to apply range update and set lazy tag
	void apply(int v,int tl,int tr,int val)
	{
		if(tl!=tr){
			t[v].flag=1;
			t[v].lazy=val;
		}
		t[v].mx=t[v].mn=val;
		t[v].v=(tr-tl+1)*val;
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
		if(l > tr || r < tl || t[v].mx<val)
			return;
		if(l <= tl && tr <= r && t[v].mx==t[v].mn)
		{
			apply(v,tl,tr,t[v].mx%val);
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
	void pupd(int v,int tl,int tr,int k,int x){
		if(k>tr || k<tl)return;
		if(tl==tr && tl==k){
			t[v].assign(x);
			return;
		}
		pushdown(v,tl,tr);
		int tm = (tl + tr)/2;
		pupd(v*2,tl,tm,k,x);
		pupd(v*2+1,tm+1,tr,k,x);
		t[v].merge(t[v*2],t[v*2+1]);
	}
	void pupd(int k,int x){
		pupd(1,0,maxn-1,k,x);
	}
}t;

int a[N];
void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,1,n+1)cin>>a[i];
	t.build(a);
	rep(i,0,m){
		int q;
		cin>>q;
		if(q==1){
			int l,r;
			cin>>l>>r;
			cout<<t.query(l,r).v<<"\n";
		}
		else if(q==2){
			int l,r,x;
			cin>>l>>r>>x;
			t.rupd(l,r,x);
		}
		else{
			int k,x;
			cin>>k>>x;
			t.pupd(k,x);
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
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}