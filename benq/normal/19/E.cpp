#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 10005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}

using namespace io;

template<class T> T invGeneral(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modular {
    T val; 
    explicit operator T() const { return val; }
    modular() { val = 0; }
    modular(const ll& v) { 
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    
    // friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend void pr(const modular& a) { pr(a.val); }
    friend void re(modular& a) { ll x; re(x); a = modular(x); }
   
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
    friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular pow(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { 
        auto i = invGeneral(a.val,MOD); assert(i != -1);
        return i;
    } // equivalent to return exp(b,MOD-2) if MOD is prime
    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef struct snode* sn;

struct snode {
    //////// VARIABLES
    sn p, c[2]; // parent, children
    int id, val, sz; // value in node 
    pi mn; // sum of values in subtree, min and max prefix sum 
    bool flip = 0; 
    // int vir = 0; stores sum of virtual children
    
    snode(int _id, int _val) {
        p = c[0] = c[1] = NULL;
        id = _id, val = _val; calc();
    }
    
    friend pi getMn(sn x) { return x?x->mn:mp(MOD,MOD); }
    friend int getSz(sn x) { return x?x->sz:0; }
    
    void prop() {
        if (!flip) return;
        swap(c[0],c[1]); 
        F0R(i,2) if (c[i]) c[i]->flip ^= 1;
        flip = 0; 
    }
    void calc() { 
        mn = {val,id}; F0R(i,2) ckmin(mn,getMn(c[i]));
        sz = 1+getSz(c[0])+getSz(c[1]);
    }
    
    //////// SPLAY TREE OPERATIONS
    int dir() {
        if (!p) return -2;
        F0R(i,2) if (p->c[i] == this) return i;
        return -1; // p is path-parent pointer, not in current splay tree
    }
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

    //////// LINK CUT TREE BASE OPERATIONS
    void access() { // bring this to top of tree
        for (sn v = this, pre = NULL; v; v = v->p) {
            v->splay(); 
            // if (pre) v->vir -= pre->sz;
            // if (v->c[1]) v->vir += v->c[1]->sz;
            v->c[1] = pre; v->calc();
            pre = v;
            // v->sz should remain the same if using vir
        }
        splay(); assert(!c[1]); // left subtree of this is now path to root, right subtree is empty
    }
    
    void makeRoot() { access(); flip ^= 1; }
    void set(int v) { splay(); val = v; calc(); } // change value in node, splay suffices instead of access because it doesn't affect values in nodes above it
    
    //////// LINK CUT TREE QUERIES
    friend sn lca(sn x, sn y) {
        if (x == y) return x;
        x->access(), y->access(); if (!x->p) return NULL; // access at y did not affect x, so they must not be connected
        x->splay(); return x->p ? x->p : x;
    }
    friend bool connected(sn x, sn y) { return lca(x,y); }
    
    //////// LINK CUT TREE MODIFICATIONS
    friend bool link(sn x, sn y) { // make x parent of y
        if (connected(x,y)) return 0; // don't induce cycle
        y->makeRoot(); y->p = x; 
        // x->access(); x->sz += y->sz; x->vir += y->sz;
        return 1; // success!
    }
    friend bool cut(sn x, sn y) { // x is originally parent of y
        x->makeRoot(); y->access(); 
        if (y->c[0] != x || x->c[0] || x->c[1]) return 0; // splay tree with y should not contain anything else besides x
        x->p = y->c[0] = NULL; y->calc(); return 1; // calc is redundant as it will be called elsewhere anyways?
    }
    friend pi pathMin(sn x, sn y) {
        x->makeRoot(); y->access(); 
        return y->mn;
    }
    friend int dist(sn x, sn y) {
        x->makeRoot(); y->access(); 
        return y->sz-1;
    }
};

vector<sn> LCT;
map<array<int,3>,int> tmp;

pi cor[100001];

void rem(int x) {
	assert(cor[x].f && cor[x].s);
	cut(LCT[cor[x].f],LCT[x]);
	cut(LCT[cor[x].s],LCT[x]);
}

bool add(int a, int b, int c) {
	// ps("ADD",a,b,c);
	if (connected(LCT[a],LCT[b])) {
		int d = dist(LCT[a],LCT[b]); 
		if (d%2 != 0) {
			ps("??",a,b,d);
			exit(0);
		}
		if ((d/2)%2 == 0) return 0;
		pi t = pathMin(LCT[a],LCT[b]);
		if (t.f >= c) return 1;
		rem(t.s);
	} 
	int x = sz(LCT);
	tmp[{a,b,c}] = x; cor[x] = {a,b};
	LCT.pb(new snode(x,c));
	// ps("HAHA",a,x,b);
	link(LCT[a],LCT[x]); link(LCT[b],LCT[x]);
	return 1;
}

void del(int a, int b, int c) {
	// ps("DEL",a,b,c);
	if (!tmp.count({a,b,c})) return;
	rem(tmp[{a,b,c}]);
}

map<pi,int> M;
pi ed[MX];
int n,m,par[MX],col[MX],depth[MX];
vi adj[MX];

void dfs(int x) {
	trav(t,adj[x]) if (!col[t]) {
		par[t] = x; depth[t] = depth[x]+1;
		col[t] = col[x]^3;
		dfs(t);
	}
}

vi cyc;

void bad(int a, int b) {
	if (sz(cyc)) return;
	vi A, B;
	while (a != b) {
		if (depth[a] > depth[b]) {
			A.pb(a);
			a = par[a];
		} else {
			B.pb(b);
			b = par[b];
		}
	}
	// ps("??",a,b,col[a],col[b],depth[a],depth[b]); exit(0);
	reverse(all(B));
	cyc = A; cyc.pb(a); cyc.insert(end(cyc),all(B));
}

void fin(vi v) {
	ps(sz(v)); sort(all(v));
	trav(t,v) pr(t,' ');
	exit(0);
}

bool inCYC[MX];

int main() {
    setIO(); re(n,m);
    FOR(i,1,m+1) {
    	re(ed[i]);
    	adj[ed[i].f].pb(ed[i].s);
    	adj[ed[i].s].pb(ed[i].f);
    	M[ed[i]] = M[{ed[i].s,ed[i].f}] = i;
    }
    FOR(i,1,n+1) if (!col[i]) {
    	col[i] = 1;
    	dfs(i);
    }
    FOR(i,1,n+1) trav(t,adj[i]) if (col[i] == col[t]) bad(i,t);
	if (!sz(cyc)) {
		vi v; FOR(i,1,m+1) v.pb(i);
		fin(v);
	}
	assert(sz(cyc)&1);
	vi CYC;
	F0R(i,sz(cyc)) {
		int a = cyc[i], b = cyc[(i+1)%sz(cyc)];
		int x = M[{a,b}]; assert(x); CYC.pb(x); inCYC[x] = 1;
	}
	F0R(i,n+1) LCT.pb(new snode(i,MOD));
	FOR(i,1,m+1) if (!inCYC[i]) {
		if (!add(ed[i].f,ed[i].s,MOD)) {
			/*if (ed[1].f == 6411) {
				ps("BAD");
				ps(cyc);
			}*/
			fin({});
		}
		//ps(dist(LCT[3],LCT[4]));
		//exit(0);
	}
			
	/*ps(dist(LCT[3],LCT[4]));
	ps(dist(LCT[1],LCT[4]));
	ps(dist(LCT[1],LCT[3]));
	exit(0);*/
	// if (ed[1].f == 6411) ps("OK");
	// ps("HA");
	int l = 0; vi sol;
	F0R(r,2*sz(CYC)-2) {
		int i = CYC[r%sz(CYC)];
		while (l <= r && !add(ed[i].f,ed[i].s,r)) {
			if (l < r) {
				int I = CYC[l%sz(CYC)];
				del(ed[I].f,ed[I].s,l);
			}
			l ++;
		}
		if (r-l+1 == sz(CYC)-1) {
			//ps("WUT",l,r,i);
			sol.pb(CYC[(r+1)%sz(CYC)]);
		}
	}
	fin(sol);
	// ps(CYC);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/