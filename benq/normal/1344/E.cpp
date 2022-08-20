#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bit(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 
int fstTrue(function<bool(int)> f, int lo, int hi) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		int mid = (lo+hi)/2; 
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}

// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }

// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { 
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { // containers with begin(), end()
	bool fst = 1; str res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += ts(x);
	}
	res += "}"; return res;
}
template<class A, class B> str ts(pair<A,B> p) {
	return "("+ts(p.f)+", "+ts(p.s)+")"; }

// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
	pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) { 
	pr(h); if (sizeof...(t)) pr(" "); ps(t...); }

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

// FILE I/O
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(string s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

/**
 * Description: Link-Cut Tree. Given a function $f(1\ldots N)\to 1\ldots N,$ 
 	* evaluates $f^b(a)$ for any $a,b.$ \texttt{sz} is for path queries; 
 	* \texttt{sub}, \texttt{vsub} are for subtree queries. \texttt{x->access()} 
 	* brings \texttt{x} to the top and propagates it; its left subtree will be 
 	* the path from \texttt{x} to the root and its right subtree will be empty. 
 	* Then \texttt{sub} will be the number of nodes in the connected component
 	* of \texttt{x} and \texttt{vsub} will be the number of nodes under \texttt{x}.
 	* Use \texttt{makeRoot} for arbitrary path queries.
 * Time: O(\log N)
 * Usage: FOR(i,1,N+1)LCT[i]=new snode(i); link(LCT[1],LCT[2],1);
 * Source: Dhruv Rohatgi, Eric Zhang
	* https://sites.google.com/site/kc97ble/container/splay-tree/splaytree-cpp-3
	* https://codeforces.com/blog/entry/67637
 * Verification: (see README for links)
	* ekzhang Balanced Tokens
	* Dynamic Tree Test (Easy)
	* https://probgate.org/viewproblem.php?pid=578 (The Applicant)
 */

vi cool;

ll dist[MX];
vpl inter;

typedef struct snode* sn;
struct snode { //////// VARIABLES
	sn p, c[2]; // parent, children
	sn extra; // extra cycle node for "The Applicant"
	bool flip = 0; // subtree flipped or not
	int val, sz; // value in node, # nodes in current splay tree
	int lst = 0, lazy = 0;
	int sub, vsub = 0; // vsub stores sum of virtual children
	snode(int _val) : val(_val) {
		p = c[0] = c[1] = extra = NULL; calc(); }
	friend int getSz(sn x) { return x?x->sz:0; }
	friend int getSub(sn x) { return x?x->sub:0; }
	void prop() { // lazy prop
		if (lazy) {
			lst = lazy; 
			F0R(i,2) if (c[i]) c[i]->lazy = lazy;
			lazy = 0;
		}
		if (!flip) return;
		swap(c[0],c[1]); flip = 0;
		F0R(i,2) if (c[i]) c[i]->flip ^= 1;
	}
	void calc() { // recalc vals
		F0R(i,2) if (c[i]) c[i]->prop();
		sz = 1+getSz(c[0])+getSz(c[1]);
		sub = 1+getSub(c[0])+getSub(c[1])+vsub;
	}
	//////// SPLAY TREE OPERATIONS
	int dir() {
		if (!p) return -2;
		F0R(i,2) if (p->c[i] == this) return i;
		return -1; // p is path-parent pointer
	} // -> not in current splay tree
	// test if root of current splay tree
	bool isRoot() { return dir() < 0; } 
	friend void setLink(sn x, sn y, int d) {
		if (y) y->p = x;
		if (d >= 0) x->c[d] = y; }
	void rot() { // assume p and p->p propagated
		assert(!isRoot()); int x = dir(); sn pa = p;
		setLink(pa->p, this, pa->dir());
		setLink(pa, c[x^1], x); setLink(this, pa, x^1);
		pa->calc(); calc();
	}
	void splay() {
		while (!isRoot() && !p->isRoot()) {
			p->p->prop(), p->prop(), prop();
			dir() == p->dir() ? p->rot() : rot();
			rot();
		}
		if (!isRoot()) p->prop(), prop(), rot();
		prop();
	}
	//////// BASE OPERATIONS
	void access() { // bring this to top of tree, propagate
		for (sn v = this, pre = NULL; v; v = v->p) {
			v->splay(); // now switch virtual children
			if (pre) v->vsub -= pre->sub;
			if (v->c[1]) v->vsub += v->c[1]->sub;
			v->c[1] = pre; v->calc(); pre = v;
		}
		splay(); assert(!c[1]); // right subtree is empty
	}
	void ACCESS(int ti) {
		dbg("ACCESS",ti,val);
		splay();
		for (sn v = this->p, pre = this; v; v = v->p) {
			v->splay(); // now switch virtual children
			ll d = dist[v->val];
			dbg("HA",v->val,d,v->lst,ti);
			if (v->lst == 0) inter.pb({1,ti+d});
			else inter.pb({v->lst+d+1,ti+d});
			if (pre) v->vsub -= pre->sub;
			if (v->c[1]) v->vsub += v->c[1]->sub;
			v->c[1] = pre; v->calc(); pre = v;
		}
		splay(); assert(!flip && !lazy);
		if (c[0]) {
			c[0]->lazy = ti;
			//dbg("HUH",val,c[0]->val);
		}
	}
	void makeRoot() { 
		access(); flip ^= 1; access(); assert(!c[0] && !c[1]); }
	//////// QUERIES
	friend sn lca(sn x, sn y) {
		if (x == y) return x;
		x->access(), y->access(); if (!x->p) return NULL;
		x->splay(); return x->p?:x;
	} // access at y did not affect x -> not connected
	friend bool connected(sn x, sn y) { return lca(x,y); } 
	// # nodes above
	int distRoot() { access(); return getSz(c[0]); } 
	sn getRoot() { // get root of LCT component
		access(); auto a = this; 
		while (a->c[0]) a = a->c[0], a->prop();
		a->access(); return a;
	}
	sn getPar(int b) { // get b-th parent on path to root
		access(); b = getSz(c[0])-b; assert(b >= 0);
		for (sn a = this;;a->prop()) {
			int z = getSz(a->c[0]);
			if (b == z) { a->access(); return a; }
			if (b < z) a = a->c[0];
			else a = a->c[1], b -= z+1;
		}
	} // can also get min, max on path to root, etc
	//////// MODIFICATIONS
	void set(int v) { access(); val = v; calc(); } 
	friend void link(sn x, sn y, bool force = 0) { 
		assert(!connected(x,y)); 
		if (force) y->makeRoot(); // make x par of y
		else { y->access(); assert(!y->c[0]); }
		x->access(); setLink(y,x,0); y->calc();
	}
	friend void cut(sn y) { // cut y from its parent
		y->access(); assert(y->c[0]);
		y->c[0]->p = NULL; y->c[0] = NULL; y->calc(); }
	friend void cut(sn x, sn y) { // if x, y adj in tree
		x->makeRoot(); y->access(); 
		assert(y->c[0] == x && !x->c[0] && !x->c[1]); cut(y); }
};
sn LCT[MX];

int n,m,par[MX],lst[MX];
vpi adj[MX];

void dfsAccess(int x) {
	LCT[x]->access();
	trav(t,adj[x]) {
		dist[t.f] = dist[x]+t.s;
		dfsAccess(t.f);
	}
}

void process() {
	int s,t; re(s,t);
	cool.clear();
	LCT[s]->ACCESS(t);
	//dbg("HA",inter);
	//dbg(cool);
}

int main() {
	setIO(); re(n,m);
	FOR(i,1,n+1) LCT[i] = new snode(i);
	F0R(i,n-1) {
		int u,v,d; re(u,v,d);
		adj[u].pb({v,d});
		par[v] = u;
	}
	FOR(i,2,n+1) link(LCT[par[i]],LCT[i]);
	dfsAccess(1);
	F0R(i,m) process();
	priority_queue<ll,vl,greater<ll>> pq;
	sort(all(inter));
	// dbg(inter);
	int ind = 0;
	for (ll i = 1; ;++i) {
		if (ind == sz(inter) && !sz(pq)) break;
		if (!sz(pq)) i = inter[ind].f;
		while (ind < sz(inter) && inter[ind].f == i) {
			pq.push(inter[ind].s);
			ind ++;
		}
		if (sz(pq)) pq.pop();
		if (sz(pq) && pq.top() == i) {
			//fin(i);
			int cnt = 0; trav(t,inter) cnt += t.s < i;
			ps(i,cnt);
			exit(0);
		}
	}
	ps(-1,sz(inter));
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/