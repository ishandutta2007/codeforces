#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef string str;
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

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
const int MX = 35005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

namespace treap {
    typedef struct tnode* pt;
    
    struct tnode {
        int pri; pt c[2]; // essential
        int l, r, slope = 0;
        int lx = 0, ly = 0;
    
        tnode (int _l, int _r, int _slope) {
            pri = rand()+(rand()<<15); c[0] = c[1] = NULL;
            l = _l, r = _r; slope = _slope;
        }
        
        ~tnode() {
        	delete c[0]; delete c[1];
        }
    };
    
    pt prop(pt x) {
        if (!x) return x;   
        x->l += x->lx, x->r += x->lx;
        x->slope += x->ly;
        F0R(i,2) if (x->c[i]) {
        	x->c[i]->lx += x->lx;
        	x->c[i]->ly += x->ly;
        }
        x->lx = x->ly = 0;
        return x;
    }
    
    /*
    
    pt calc(pt x) {
        assert(!x->flip);
        prop(x->c[0]), prop(x->c[1]);
        x->sz = 1+getsz(x->c[0])+getsz(x->c[1]);
        x->sum = x->val+getsum(x->c[0])+getsum(x->c[1]);
        return x;
    }
    
    pair<pt,pt> split(pt t, int v) { // >= v goes to the right
        if (!t) return {t,t};
        prop(t);
        if (t->val >= v) {
            auto p = split(t->c[0], v); t->c[0] = p.s;
            return {p.f, calc(t)};
        } else {
            auto p = split(t->c[1], v); t->c[1] = p.f;
            return {calc(t), p.s};
        }
    }
    
    pair<pt,pt> splitsz(pt t, int sz) { // leftmost sz nodes go to left
        if (!t) return {t,t};
        prop(t);
        if (getsz(t->c[0]) >= sz) {
            auto p = splitsz(t->c[0], sz); t->c[0] = p.s;
            return {p.f, calc(t)};
        } else {
            auto p = splitsz(t->c[1], sz-getsz(t->c[0])-1); t->c[1] = p.f;
            return {calc(t), p.s};
        }
    }
        
    pt merge(pt l, pt r) {
        if (!l || !r) return l ? l : r;
        prop(l), prop(r);
        pt t;
        if (l->pri > r->pri) l->c[1] = merge(l->c[1],r), t = l;
        else r->c[0] = merge(l,r->c[0]), t = r;
        return calc(t);
    }
    
    pt ins(pt x, int v) { // insert v
        auto a = split(x,v), b = split(a.s,v+1);
        return merge(a.f,merge(new tnode(v),b.s));
    }
    
    pt del(pt x, int v) { // delete v
        auto a = split(x,v), b = split(a.s,v+1);
        return merge(a.f,b.s);
    }*/
}

using namespace treap;

pt merge(pt l, pt r) {
    if (!l || !r) return l ? l : r;
    prop(l), prop(r);
    pt t;
    if (l->pri > r->pri) l->c[1] = merge(l->c[1],r), t = l;
    else r->c[0] = merge(l,r->c[0]), t = r;
    return t;
}

int fdiv(int a, int b) {
	if (a >= 0 || a%b == 0) return a/b;
	return a/b-1;
}

void tour(pt x, vector<pair<pi,int>>& v) {
    if (!x) return;
    prop(x);
    tour(x->c[0],v); v.pb({{x->l,x->r},x->slope}); tour(x->c[1],v);
}
    
pair<pt,pt> split(pt t) {
	if (!t) return {t,t};
	prop(t);
	if (t->r <= 0) {
		auto p = split(t->c[1]);
		t->c[1] = p.f;
		return {t,p.s};
	}
	if (t->l >= 0) {
		auto p = split(t->c[0]);
		t->c[0] = p.s;
		return {p.f,t};
	}
	return {merge(t->c[0],new tnode(t->l,0,t->slope)),
			merge(new tnode(0,t->r,t->slope),t->c[1])};
}

pair<pt,pt> splitSlope(pt t) {
	if (!t) return {t,t};
	prop(t);
	if (t->slope <= 0) {
		auto p = splitSlope(t->c[1]);
		t->c[1] = p.f;
		return {t,p.s};
	} else {
		auto p = splitSlope(t->c[0]);
		t->c[0] = p.s;
		return {p.f,t};
	}
}
    
int getLst(pt t) {
	prop(t);
	if (t->c[1]) return getLst(t->c[1]);
	return t->r;
}

int getFst(pt t) {
	prop(t);
	if (t->c[0]) return getFst(t->c[0]);
	return t->l;
}

int n,a[MX],l[MX],r[MX];
pt root;
ll st;

void insZero(int x) {
	if (!x) return;
	auto a = splitSlope(root);
	// exit(0);
	int lst = a.f?getLst(a.f):getFst(a.s);
	auto b = new tnode(lst,lst+x,0);
	if (a.s) a.s->lx += x;
	root = merge(a.f,merge(b,a.s));
}

void fin() {
	vector<pair<pi,int>> v; tour(root,v);
	ps(v); exit(0);
}

void addAbs() {
	auto a = split(root); // exit(0);
	if (a.f) a.f->ly --;
	if (a.s) a.s->ly ++;
	if (a.f) st -= getFst(a.f);
	else st += getFst(a.s);
	root = merge(a.f,a.s);
	// fin();
}

ll solve(int lo) {
	st = 0;
	root = new tnode(lo,lo,0); // start, end, slope
	// starting value
	FOR(i,1,n+1) {
		// shift by l[i]
		// insert r[i]-l[i] zeroes
		// add abs(x[i+1])
		// x[i+1]-x[i] in [l[i],r[i]]
		// ps("LOOKING",l[i],r[i]);
		root->lx += l[i]; 
		insZero(r[i]-l[i]);
		addAbs();
	}
	vector<pair<pi,int>> v; tour(root,v);
	trav(t,v) if (t.f.f < lo) st += (ll)t.s*(min(lo,t.f.s)-t.f.f);
	delete root;
	return st;
	// ps("??",st,v); exit(0);
}

int main() {
	setIO(); re(n);
	FOR(i,1,n+1) {
		re(a[i],l[i],r[i]);
		l[i] -= a[i], r[i] -= a[i];
	}
	int lo = -7e8, hi = 7e8;
	while (lo < hi) {
		int mid = fdiv(lo+hi,2);
		if (solve(mid) < solve(mid+1)) hi = mid;
		else lo = mid+1;
	}
	ps(solve(lo));
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/