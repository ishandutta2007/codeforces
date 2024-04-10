#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;
 
typedef double db;
typedef long long ll;
typedef long double ld;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define rsz resize
#define ins insert

const int MOD = 1e9+7; // 998244353 = (119<<23)+1
const ll INF = 1e18;
const int MX = 2e5+5;
const ld PI = 4*atan((ld)1);

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ook order_of_key
#define fbo find_by_order

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

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
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
        cin.sync_with_stdio(0); cin.tie(0); // fast I/O
        cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
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

struct DSUrb {
	vi e;
	void init(int n) { e = vi(n,-1); }
	int get(int x) { return e[x] < 0 ? x : get(e[x]); } // path compression
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	vector<array<int,4>> mod;
	bool unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y); 
		if (x == y) {
			mod.pb({MOD,MOD,MOD,MOD});
			return 0;
		}
		if (e[x] > e[y]) swap(x,y);
		mod.pb({x,y,e[x],e[y]});
		e[x] += e[y]; e[y] = x;
		return 1;
	}
	void rollback() {
		auto a = mod.back(); mod.pop_back();
		if (a[0] != MOD) e[a[0]] = a[2], e[a[1]] = a[3];
	}
};

struct Edge { int a, b; ll w; };
struct Node { /// lazy skew heap node
	Edge key;
	Node *l, *r;
	ll delta;
	void prop() {
		key.w += delta;
		if (l) l->delta += delta;
		if (r) r->delta += delta;
		delta = 0;
	}
	Edge top() { prop(); return key; }
};
Node *merge(Node *a, Node *b) {
	if (!a || !b) return a ?: b;
	a->prop(), b->prop();
	if (a->key.w > b->key.w) swap(a, b);
	swap(a->l, (a->r = merge(b, a->r)));
	return a;
}
void pop(Node*& a) { a->prop(); a = merge(a->l, a->r); }

pair<ll,vi> dmst(int n, int r, const vector<Edge>& g) {
	DSUrb dsu; dsu.init(n);
	vector<Node*> heap(n); // store edges entering each vertex in increasing order of weight
	trav(e,g) heap[e.b] = merge(heap[e.b], new Node{e});
	ll res = 0; vi seen(n,-1); seen[r] = r; 
	vpi in(n,{-1,-1});
	vector<pair<int,vector<Edge>>> cycs;
	F0R(s,n) {
		int u = s, w;
		vector<pair<int,Edge>> path;
		while (seen[u] < 0) {
			if (!heap[u]) return {-1,{}};
			seen[u] = s;
			Edge e = heap[u]->top(); path.pb({u,e}); 
			heap[u]->delta -= e.w, pop(heap[u]);
			res += e.w, u = dsu.get(e.a); 
			if (seen[u] == s) { // compress verts in cycle
				Node* cyc = 0; vector<Edge> cycEd;
				do {
					cyc = merge(cyc, heap[w = path.back().f]);
					cycEd.pb(path.back().s); 
					path.pop_back();
				} while (dsu.unite(u, w));
				u = dsu.get(u); heap[u] = cyc, seen[u] = -1;
				cycs.pb({u,cycEd});
			}
		}
		trav(t,path) in[dsu.get(t.s.b)] = {t.s.a,t.s.b};
	}
	while (sz(cycs)) {
		auto c = cycs.back(); cycs.pop_back();
		pi inEdge = in[c.f];
		trav(t,c.s) dsu.rollback();
		trav(t,c.s) in[dsu.get(t.b)] = {t.a,t.b};
		in[dsu.get(inEdge.s)] = inEdge;
	}
	vi inv; 
	F0R(i,n) { 
		assert(i == r ? in[i].s == -1 : in[i].s == i);
		inv.pb(in[i].f); 
	} 
	return {res,inv};
}

/*ll dmst(int n, int r, vector<Edge>& g) {
	DSUrb dsu; dsu.init(n);
	vector<Node*> heap(n);
	trav(e, g) heap[e.b] = merge(heap[e.b], new Node{e});
	ll res = 0;
	vi seen(n, -1); seen[r] = r;
	F0R(s,n) {
		int u = s, w; vi path;
		while (seen[u] < 0) {
			if (!heap[u]) return -1;
			ps("SEEN",u);
			seen[u] = s;
			Edge e = heap[u]->top(); path.pb(u);
			heap[u]->delta -= e.w, pop(heap[u]);
			res += e.w, u = dsu.get(e.a);
			if (seen[u] == s) {
				Node* cyc = 0;
				do {
					cyc = merge(cyc, heap[w = path.back()]);
					path.pop_back();
				} while (dsu.unite(u, w));
				ps("HA",sz(path));
				u = dsu.get(u);
				heap[u] = cyc, seen[u] = -1;
			}
		}
	}
	return res;
}*/

int n, m;
vector<array<int,3>> bef[MX];

int main() {
	setIn("input.txt");
	setOut("output.txt");
	re(n,m);
	vector<Edge> ed;
	F0R(i,m) {
		int a,b,c; re(a,b,c); a--, b--;
		ed.pb({a,b,c});
		bef[b].pb({a,c,i+1});
	}
	auto x = dmst(n,0,ed); 
	ps(x.f); if (x.f == -1) exit(0);
	FOR(i,1,n) {
		pi bes = {MOD,MOD};
		trav(t,bef[i]) if (t[0] == x.s[i]) ckmin(bes,{t[1],t[2]});
		if (bes.f) pr(bes.s,' ');
	}
	
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/