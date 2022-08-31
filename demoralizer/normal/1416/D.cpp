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

const int N=2e5+5;

int parent[3*N],size[3*N],head[3*N];
int findParent(int i)
{
	if(parent[parent[i]]!=parent[i])
		parent[i]=findParent(parent[i]);
	return parent[i];
}
void unionNodes(int a,int b)
{
	int parent_a=findParent(a),parent_b=findParent(b);
	int tmp = head[parent_a];
	if(parent_a==parent_b)
		return;
	if(size[parent_a]>=size[parent_b]){
		swap(parent_a,parent_b);
	}
	size[parent_b]+=size[parent_a];
	parent[parent_a]=parent_b;
	head[parent_b] = tmp;
	return;
}
void cleardsu(int n){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		size[i]=1;
		head[i]=i;
	}
}

int tim = 1;
int p[3*N],st[3*N],et[3*N];
vector<int> v[3*N];

pii val[3*N];

void dfs(int z){
	st[z] = tim++;
	if(z < N){
		val[st[z]] = {p[z],st[z]};
	}
	for(int x:v[z]){
		dfs(x);
	}
	et[z] = tim;
}

int nc = N;
void merge(int x,int y){
	x = findParent(x);
	y = findParent(y);
	if(x == y) return;
	nc++;
	v[nc].pb(head[x]);
	unionNodes(nc,x);
	v[nc].pb(head[y]);
	unionNodes(nc,y);
}

const int32_t maxn=3*N;
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
	pii v = {0,0};
	node(){}
	node(pii val){
		v = val;
	}
	void merge(node &l,node &r)
	{
		v = max(l.v,r.v);
	}
	bool check(int x){
		return false;
	}
};
struct update{
	int v;
	update(){}
	update(int val){
		v = val;
	}
	void combine(update &other,int32_t tl,int32_t tr){
		
	}
	void apply(node &x,int32_t tl,int32_t tr){
		x.v.fr = v;
	}
};
segtree<node,update> t;
#undef node
#undef update



void solve(){
	cleardsu(3*N-5);
	int n,m,q;
	cin >> n >> m >> q;
	rep(i,1,n+1){
		cin >> p[i];
	}
	vector<pii> edgs(m+1),quer(q);
	set<int> av;
	rep(i,1,m+1){
		cin >> edgs[i];
		av.insert(i);
	}
	rep(i,0,q){
		cin >> quer[i];
		if(quer[i].fr == 2){
			av.erase(quer[i].sc);
		}
	}
	
	for(int x:av){
		merge(edgs[x].fr,edgs[x].sc);
	}
	rep(z,0,q){
		int i = q - 1 - z;
		if(quer[i].fr == 2){
			int x = quer[i].sc;
			merge(edgs[x].fr,edgs[x].sc);
		}
		else{
			int x = quer[i].sc;
			x = head[findParent(x)];
			quer[i].sc = x;
		}
	}
	rep(i,1,n){
		merge(i,i+1);
	}
	
	// nc is the root now
	dfs(nc);
	t.build(val);
	
	rep(i,0,q){
		if(quer[i].fr == 1){
			int x = quer[i].sc;
			int a = st[x], b = et[x] - 1;
			pii ans = t.query(a,b).v;
			cout << ans.fr << "\n";
			t.rupd(ans.sc,ans.sc,0);
		}
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