#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e5+5;

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
		if(tl[v]!=tr[v]){
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
		if (l > tr[v]) // node is completely out of range
			return len;
		if(l <= tl[v]){ // node is completely in range
			NODE cur;
			cur.merge(prev,t[v]);
			if (!cur.check(x)){ // go further right than this node
				swap(prev,cur); // merging this node's contribution
				return len;
			}
			if (tl[v]==tr[v]) {
				return tr[v];
			}
		}
		pushdown(v);
		int ans=descent_right(l, x, v*2, prev); // trying to find in left child
		if(ans!=len)return ans; // found in left child
		return descent_right(l, x, v*2+1, prev); // finding in right child
	}
	template<typename T>
	int descent_left(int r, T x, int32_t v, NODE &prev) {
		if (r < tl[v]) // node is completely out of range
			return -1;
		if(r >= tr[v]){ // node is completely in range
			NODE cur;
			cur.merge(t[v],prev);
			if (!cur.check(x)){ // go further left than this node
				swap(cur,prev); // merging this node's contribution
				return -1;
			}
			if (tl[v]==tr[v]) {
				return tl[v];
			}
		}
		pushdown(v);
		int ans=descent_left(r, x, v*2+1, prev); // trying to find in right child
		if(ans!=-1)return ans; // found in right child
		return descent_left(r, x, v*2, prev); // finding in left child
	}
	
	int len=maxn;
	void clear(){
		fill(t,t+4*len,zero);
		fill(lazy,lazy+4*len,false);
		fill(upds,upds+4*len,noop);
		built = false;
	}
	template<typename T>
	void build(T a){
		build(a,1,0,len-1);
		built=true;
	}
	template<typename T>
	int descent_right(int l, T x){ // minimum r such that [l...r].check(x) == true, returns segtree.len if not found
		NODE prev=zero;
		return descent_right(l,x,1,prev);
	}
	template<typename T>
	int descent_left(int r, T x){ // maximum l such that [l...r].check(x) == true, returns -1 if not found
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
	int mn = INF, mx = 0;
	int smn = INF, smx = 0;
	node(){}
	node(int val){
		mn = mx = val;
	}
	void merge(node &l,node &r)
	{
		vector<int> x = {l.mn,r.mn,l.smn,r.smn};
		sort(all(x));
		mn = x[0], smn = x[1];
		x = {l.mx,r.mx,l.smx,r.smx};
		sort(all(x));
		mx = x[3], smx = x[2];
	}
	bool check(int x){
		return false;
	}
};
struct update{
	
	update(){}
	update(int val){
		
	}
	void combine(update &other,int32_t tl,int32_t tr){
		
	}
	void apply(node &x,int32_t tl,int32_t tr){
		
	}
};
segtree<node,update> t;
#undef node
#undef update

vector<int> v[N];
int st[N],ver[N],tim=1;

const int H = 17;
int par[N][H+1], lvl[N];
void dfs(int z, int p = 0){
	ver[tim] = z;
	st[z] = tim++;
	lvl[z] = lvl[p] + 1;
	par[z][0] = p;
	for (int i = 1; i <= H; ++i){
		par[z][i] = par[par[z][i-1]][i-1];
	}
	for(int x:v[z]){
		if(x==p)continue;
		dfs(x,z);
	}
}

int lca(int x, int y) {
	if (lvl[x] < lvl[y]) swap(x, y);
	for (int i = H; i >= 0; i--){
		if (lvl[x] - (1<<i) >= lvl[y]){
			x = par[x][i];
		}
	}
	if (x == y) return x;
	for (int i = H; i >= 0; i--){
		if (par[x][i] != par[y][i]){
			x = par[x][i], y = par[y][i];
		}
	}
	return par[x][0];
}

void solve(){
	lvl[0] = -1;
	int n,q;
	cin >> n >> q;
	rep(i,2,n+1){
		int x;
		cin >> x;
		v[x].pb(i);
	}
	dfs(1);
	t.build(st);
	
	rep(i,0,q){
		int x,y;
		cin >> x >> y;
		auto z = t.query(x,y);
		int a = lvl[lca(ver[z.mn],ver[z.smx])];
		int b = lvl[lca(ver[z.smn],ver[z.mx])];
		int k,ans = max(a,b);
		if(a > b){
			k = ver[z.mx];
		}
		else{
			k = ver[z.mn];
		}
		cout << k << " " << ans << "\n";
	}
	
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}