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
const int MX = 300005;
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
    
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
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
int n,m,C;

// answer for last double
// answer for other doubles 
// best one or two singles

int l[MX],r[MX],c[MX],ret[MX];
vector<array<int,3>> tran;
set<int> cur;
vpi query;
int a = -1, b = -1;
int ans0 = -MOD, ans1 = -MOD, ans = 0, zero = 0;

int single[MX];

int bet(int x, int y) { 
	assert(x < y);
	return r[x] > r[y] ? x : y;
}

bool ok(int x, int y) {
	int ret = c[x]+(y==-1?0:c[y]);
	return ret <= C;
}

map<int,int> mm;

void ins(int x, int y) {
	auto it = mm.ub(x);
	if (it != mm.begin() && prev(it)->s >= y) return;
	mm[x] = y; 
	while (it != mm.end() && it->s <= y) {
		it ++;
		mm.erase(prev(it));
	}
}

int getMax(int x) {
	auto it = mm.ub(x);
	if (it == mm.begin()) return -MOD;
	return prev(it)->s;
}

void process(int st, int en) {
	if (sz(cur) > 2) return;
	if (sz(cur) == 0) {
		zero += en-st;
		// ps("HA",st,en);
	} else {
		int x = *cur.begin(), y = -1;
		if (sz(cur) == 2) {
			y = *cur.rbegin();
			if (bet(x,y) == y) swap(x,y);
			assert(r[x] >= r[y]);
		}
		pi z = mp(x,y);
		if (z == mp(a,b)) {
			if (ans0 != -MOD) ans0 += en-st;
		} else {
			ckmax(ans1,ans0); ans0 = -MOD;
			if (ok(x,y)) ans0 = en-st+single[x]+(y==-1?0:single[y]);
		}
		if (x == a) {
			if (ans1 != -MOD && y == -1) ans1 += en-st;
		} else {
			ans1 = -MOD;
			if (a != -1) ins(c[a],single[a]);
		}
		ckmax(ans,max(ans0,ans1)); // check cost, time
		// ps("HUH",st,en,sz(cur),x,y,c[x]+(y==-1?0:c[y]));
		// ps(a,b,z,ans0,ans1,ans);
		tie(a,b) = z;
		if (y == -1) {
			single[x] += en-st; 
			ckmax(ans,single[x]+getMax(C-c[x]));
		} 
	}
	while (sz(query) && ans+zero >= query.back().f) {
		ret[query.back().s] = en-(ans+zero-query.back().f);
		query.pop_back();
	}
}

void init() {
    setIO(); re(n,C);
    F0R(i,n) {
    	re(l[i],r[i],c[i]);
    	tran.pb({l[i],i,1});
    	tran.pb({r[i],i,-1});
    }
    re(m); query.rsz(m);
    F0R(i,m) {
    	re(query[i].f);
    	query[i].s = i;
    }
    tran.pb({0,-MOD,-MOD});
    tran.pb({2*MOD,-MOD,-MOD});
    sort(all(tran));
    sort(all(query)); reverse(all(query));
}

int main() {
	init();
	F0R(i,m) ret[i] = -1;
	F0R(i,sz(tran)-1) {
		auto t = tran[i];
		if (t[1] != -MOD) {
			// ps("HA",t[1]); exit(0);
			if (t[2] == 1) cur.insert(t[1]);
			else cur.erase(t[1]);
		}
		process(tran[i][0],tran[i+1][0]);
	}
    F0R(i,m) ps(ret[i]);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/