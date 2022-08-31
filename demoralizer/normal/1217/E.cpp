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

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
template<typename T1,typename T2>std::istream& operator>>(std::istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a){out<<a.fr<<" "<<a.sc;return out;}

const int N=2e5+5;

const int maxn=N;
struct node{
	int a[9];
	int b[9];
	void assign(int val)
	{
		int v=val;
		rep(i,0,9){
			if(v%10) a[i]=val;
			else a[i]=M;
			b[i]=M;
			v/=10;
		}
	}
	void merge(node &l,node &r)
	{
		int c[4];
		rep(i,0,9){
			c[0]=l.a[i],c[1]=l.b[i],c[2]=r.a[i],c[3]=r.b[i];
			sort(c,c+4);
			a[i]=c[0];
			b[i]=c[1];
		}
	}
}zero;
struct segtree{
	node t[4*maxn];
public:
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
			t[v].assign(val);
			return;
		}
		int tm = (tl + tr)/2;
		rupd(v*2,tl,tm,l,r,val);
		rupd(v*2+1,tm+1,tr,l,r,val);
		t[v].merge(t[v*2],t[v*2+1]);
	}
	void rupd(int l,int val){
		rupd(1,0,maxn-1,l,l,val);
	}
}t;

int a[N];
void solve(){
	rep(i,0,9){
		zero.a[i]=zero.b[i]=M;
	}
	int n,m;
	cin>>n>>m;
	rep(i,1,n+1)cin>>a[i];
	t.build(a);
	rep(i,0,m){
		int c,x,y;
		cin>>c>>x>>y;
		if(c==1){
			t.rupd(x,y);
		}
		else{
			node ans=t.query(x,y);
			int k=2*M;
			rep(i,0,9){
				if(ans.b[i]!=M)amin(k,ans.a[i]+ans.b[i]);
			}
			if(k==2*M)k=-1;
			cout<<k<<"\n";
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