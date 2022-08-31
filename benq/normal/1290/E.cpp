#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 
#define mp make_pair 
#define f first
#define s second

typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

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

const int MOD = 1e9+7; // 998244353; // = (119<<23)+1
const int MX = 1.5e5+5;
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 

template<class T> bool ckmin(T& a, const T& b) { 
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; }
int pc(int x) { return __builtin_popcount(x); } 

namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);

	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(ld& x) { string t; re(t); x = stold(t); }
	template<class T, class... Ts> void re(T& t, Ts&... ts) { 
		re(t); re(ts...); 
	}

	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = {a,b}; }
	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
	template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
	template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }
	
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
	
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
		pr(t); pr(ts...); 
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
		pr("{",x.f,", ",x.s,"}"); 
	}
	template<class T> void pr(const T& x) { 
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
		pr("}");
	}
	
	void ps() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
	}
	
	void pc() { pr("]\n"); } // debug w/ commas
	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
	}
	#define dbg(x...) pr("[",#x,"] = ["), pc(x);
}

using namespace output;

namespace io {
	void setIn(string s) { freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { freopen(s.c_str(),"w",stdout); }
	void setIO(string s = "") {
		ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); 
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

/**
 * Description: Link-Cut Tree. Given a function $f(1\ldots N)\to 1\ldots N,$ 
 	* evaluates $f^b(a)$ for any $a,b.$ For subtree size queries use 
 	* \texttt{vir} and \texttt{sub}.
 * Time: O(\log N)
 * Source: Dhruv Rohatgi, Eric Zhang
	* https://sites.google.com/site/kc97ble/container/splay-tree/splaytree-cpp-3
	* https://codeforces.com/blog/entry/67637
 * Verification: 
	* ekzhang Balanced Tokens
	* Dynamic Tree Test (Easy)
	* https://probgate.org/viewproblem.php?pid=578 (The Applicant)
 */

typedef struct snode* sn;
struct snode { 
	//////// VARIABLES
	sn p, c[2]; // parent, children
	bool flip = 0; // subtree flipped or not
	int id, val, sz; // value in node, # nodes in subtree
	sn extra; // extra cycle node for "The Applicant"
	int sub, vir = 0; // stores sum of virtual children
	snode(int _id, int v) {
		p = c[0] = c[1] = extra = NULL;
		id = _id, val = v; calc();
	}
	friend int getSz(sn x) { return x?x->sz:0; }
	friend int getSub(sn x) { return x?x->sub:0; }
	void prop() { // lazy prop
		if (!flip) return;
		swap(c[0],c[1]); F0R(i,2) if (c[i]) c[i]->flip ^= 1;
		flip = 0; 
	}
	ll totVal = 0, virVal = 0;
	void calc() { // recalc vals
		F0R(i,2) if (c[i]) c[i]->prop();
		sz = 1+getSz(c[0])+getSz(c[1]);
		sub = 1+getSub(c[0])+getSub(c[1])+vir;
		totVal = virVal+(c[0]?c[0]->totVal:0)+(c[1]?c[1]->totVal:0);
		totVal += (ll)(getSz(c[0])+1)*((c[1]?c[1]->sub:0)+vir+1);
	}
	//////// SPLAY TREE OPERATIONS
	int dir() {
		if (!p) return -2;
		F0R(i,2) if (p->c[i] == this) return i;
		return -1; // p is path-parent pointer,
		// so not in current splay tree
	}
	// test if root of current splay tree
	bool isRoot() { return dir() < 0; } 
	friend void setLink(sn x, sn y, int d) {
		if (y) y->p = x;
		if (d >= 0) x->c[d] = y;
	}
	void rot() { // assume p and p->p propagated
		assert(!isRoot()); int x = dir(); sn pa = p;
		setLink(pa->p, this, pa->dir());
		setLink(pa, c[x^1], x);
		setLink(this, pa, x^1);
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
	void access() { // bring this to top of tree
		for (sn v = this, pre = NULL; v; v = v->p) {
			v->splay(); 
			if (pre) v->vir -= pre->sub, v->virVal -= pre->totVal;
			if (v->c[1]) v->vir += v->c[1]->sub, v->virVal += v->c[1]->totVal;
			v->c[1] = pre; v->calc();
			pre = v;
			// v->sub should remain the same 
		}
		splay(); // left subtree of this is now path to root
		assert(!c[1]); // right subtree is empty
	}
	void makeRoot() { 
		access(); flip ^= 1; prop(); 
		assert(!c[0]);
	}
	//////// QUERIES
	friend sn lca(sn x, sn y) {
		if (x == y) return x;
		x->access(), y->access(); if (!x->p) return NULL; 
		// access at y did not affect x -> not connected
		x->splay(); return x->p?:x;
	}
	friend bool connected(sn x, sn y) { return lca(x,y); } 
	int distRoot() { access(); return getSz(c[0]); } 
	// # nodes above
	sn getRoot() { // get root of LCT component
		access(); auto a = this; 
		while (a->c[0]) a = a->c[0], a->prop();
		a->access(); return a;
	}
	sn getPar(int b) { // get b-th parent
		access(); b = getSz(c[0])-b; assert(b >= 0);
		auto a = this;
		while (1) {
			int z = getSz(a->c[0]);
			if (b == z) { a->access(); return a; }
			if (b < z) a = a->c[0];
			else a = a->c[1], b -= z+1;
			a->prop();
		}
	}
	//////// MODIFICATIONS
	void set(int v) { access(); val = v; calc(); } 
	friend void link(sn x, sn y, bool force = 0) { // make x par of y
		assert(!connected(x,y));
		if (force) y->makeRoot();
		else { y->access(); assert(!y->c[0]); }
		x->access(); setLink(y,x,0); y->calc();
	}
	friend void cut(sn y) { // cut y from its parent
		y->access(); assert(y->c[0]);
		y->c[0]->p = NULL; y->c[0] = NULL; y->calc(); 
	}
	friend void cut(sn x, sn y) { // if x, y adj in tree
		x->makeRoot(); y->access(); 
		assert(y->c[0] == x && !x->c[0] && !x->c[1]);
		cut(y); 
	}
};
sn LCT[MX];

//////// THE APPLICANT SOLUTION
void setNex(sn a, sn b) { // set f[a] = b
	if (connected(a,b)) a->extra = b;
	else link(b,a);
}
void delNex(sn a) { // set f[a] = NULL
	auto t = a->getRoot();
	if (t == a) { t->extra = NULL; return; }
	cut(a); assert(t->extra);
	if (!connected(t,t->extra)) 
		link(t->extra,t), t->extra = NULL; 
}
sn getPar(sn a, int b) { // get f^b[a]
	int d = a->distRoot(); if (b <= d) return a->getPar(b);
	b -= d+1; auto r = a->getRoot()->extra; assert(r);
	d = r->distRoot()+1; return r->getPar(b%d);
}

/**
 * Description: 1D range minimum query
 * Source: KACTL
 * Verification: 
	* https://cses.fi/problemset/stats/1647/
	* http://wcipeg.com/problem/ioi1223
	* https://pastebin.com/ChpniVZL
 * Memory: O(N\log N)
 * Time: O(1)
 */

template<class T> struct RMQ {
	// floor(log_2(x))
	int level(int x) { return 31-__builtin_clz(x); } 
	vector<T> v; vector<vi> jmp;
	int comb(int a, int b) { // index of min
		return v[a]==v[b] ? min(a,b) : (v[a]>v[b]?a:b); } 
	void init(const vector<T>& _v) {
		v = _v; jmp = {vi(sz(v))}; iota(all(jmp[0]),0);
		for (int j = 1; 1<<j <= sz(v); ++j) {
			jmp.pb(vi(sz(v)-(1<<j)+1));
			F0R(i,sz(jmp[j])) jmp[j][i] = comb(jmp[j-1][i],
									jmp[j-1][i+(1<<(j-1))]);
		}
	}
	int index(int l, int r) { // get index of min element
		int d = level(r-l+1);
		return comb(jmp[d][l],jmp[d][r-(1<<d)+1]); }
	T query(int l, int r) { return v[index(l,r)]; }
};

int N, iA[MX];
ll ans[MX];
vi A; 
RMQ<int> R;

sn makeTree(int l, int r) {
	if (l > r) return NULL;
	int i = R.index(l,r);
	auto L = makeTree(l,i-1);
	if (L) link(LCT[i],L);
	auto R = makeTree(i+1,r);
	if (R) link(LCT[i],R);
	return LCT[i];
}

sn cur;

void process(sn x) {
	if (!x) return;
	sn a = x->c[0], b = x->c[1];
	if (a) a->p = NULL;
	if (b) b->p = NULL;
	x->c[0] = x->c[1] = NULL; x->calc();
	process(a);
	//cout << "DOING " << x->id << " " << x->val << "\n";
	//cout << cur->id << " " << cur->val << "\n";
	sn ins = cur;
	while (1) {
		int d = (x->val < ins->val);
		if (ins->c[d] == NULL) {
			setLink(ins,x,d);
			break;
		} else ins = ins->c[d];
	}
	x->splay(); cur = x;
	process(b);
}

sn getLeft(sn x) {
	if (!x->c[0]) return x;
	return getLeft(x->c[0]);
}

int main() {
	// setIn("E.in");
	setIO(); 
	re(N); A.rsz(N); re(A);
	F0R(i,N) iA[A[i]] = i;
	F0R(i,N) LCT[i] = new snode(i,A[i]);
	R.init(A);
	makeTree(0,N-1);
	// auto z = makeTree(0,N-1); ps(z->id,z->val,z->c[0] == NULL);
	//ps("OK2");
	set<int> vals; F0R(i,N) vals.insert(i);
	ROF(t,1,N+1) {
		int i = iA[t];
		//ps("???",i);
		LCT[i]->access(); 
		if (LCT[i]->c[0]) {
			cout << "AH " << LCT[i]->val << " " << LCT[i]->c[0]->val << "\n";
			ps("ID",LCT[i]->c[0]->id);
		}
		assert(!LCT[i]->c[0]);
		ans[t] = LCT[i]->totVal;
		auto it = vals.erase(vals.find(i));
		sn l = NULL, r = NULL;
		LCT[i]->access();
		//cout << "ORI " << LCT[i]->sub << "\n";
		if (it != end(vals)) {
			r = LCT[*it];
			r->access(); LCT[i]->access();
			r->splay(); assert(r->p == LCT[i]);
			cut(getLeft(r));
		}
		//ps("CUTR");
		LCT[i]->access();
		//cout << "HUH " << LCT[i]->sub << "\n";
		if (it != begin(vals)) {
			l = LCT[*prev(it)];
			l->access(); LCT[i]->access();
			l->splay(); assert(l->p == LCT[i]);
			cut(getLeft(l));
		}
		//ps("CUTL");
		LCT[i]->access();
		//cout << "HUH " << LCT[i]->sub << "\n";
		if (!l || !r) continue;
		l->access(), r->access();
		assert(!l->c[1] && !r->c[1]);
		if (l->sz > r->sz) swap(l,r);
		cur = r; process(l);
	}
	FOR(i,1,N+1) ps(ans[i]);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
*/