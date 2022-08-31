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

template<typename T1,typename T2>
std::istream& operator>>(std::istream& in,pair<T1,T2> &a)
{
	in>>a.fr>>a.sc;
	return in;
}
template<typename T1,typename T2>
std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a)
{
	out<<a.fr<<" "<<a.sc;
	return out;
}

#ifdef demoralizer
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif


const int N=1e5+5;
int n,x[N];


const int maxn=N;
struct node{
	int v;
	int lazy=0;
	void assign(int val)
	{
		v=val;
	}
	void merge(node &l,node &r)
	{
		v=__gcd(l.v,r.v);
	}
}zero;
struct segtree{
	node t[4*maxn];
public:
	//apply() is an auxillary function to apply range update and set lazy tag
	void apply(int v,int tl,int tr,int val)
	{
		t[v].v=val;
	}
	int descent(int v, int tl, int tr, int g, int r) {
		if(r<tl)return N;
		if(__gcd(t[v].v,g)==g) return tl;
		if(tl==tr)return N;
		int tm = (tl + tr) / 2;
		if(__gcd(t[2*v+1].v,g)==g)return min(tm+1,descent(v*2,tl,tm,g,r));
		return descent(v*2+1,tm+1,tr,g,r);
	}
	int descent(int g,int r){
		return descent(1,0,maxn-1,g,r);
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
		int tm = (tl + tr)/2;
		rupd(v*2,tl,tm,l,r,val);
		rupd(v*2+1,tm+1,tr,l,r,val);
		t[v].merge(t[v*2],t[v*2+1]);
	}
	void rupd(int l,int r,int val){
		rupd(1,0,maxn-1,l,r,val);
	}
}t;

int ans;
vector<int> v[N],order;
void dfs(int z,int p){
	int l=sz(order),r=l,rr=l;
	order.pb(x[z]);
	t.rupd(l,l,x[z]);
	int gg=0;
	while(l>=0){
		gg=__gcd(gg,order[l]);
		l=t.descent(gg,r);
		ans+=(rr-l+1)*gg%M;
		ans%=M;
		l--;
		rr=l;
	}
	for(int x:v[z]){
		if(x==p)continue;
		dfs(x,z);
	}
	order.ppb();l=sz(order);t.rupd(l,l,0);
}
void solve(){
	cin>>n;
	rep(i,1,n+1)cin>>x[i];
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,1);
	
	// t.rupd(0,0,2);
	// t.rupd(1,1,3);
	// t.rupd(2,2,0);
	// t.rupd(3,3,0);
	// cout<<t.descent(0,3)<<"\n";
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