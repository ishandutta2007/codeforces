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
const ll INF = 2e9;
const int MX = 100005;
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

int n,q;
mi ans[MX], pref[MX];
vi A;
vpi todo[MX];

struct state {
	ll act; mi val;
	pi range;
	mi a, b; // a*x+b for all x in this range
	state() {}
	state(int x) {
		act = 2*A[x];
		val = 2*A[x];
		range = {x,x};
		pref[x] = val;
		a = 1, b = 0;
	}
};

ll pow2(int len) {
	if (len == 0) return 1;
	auto a = pow2(len/2); a = min(a*a,INF);
	if (len&1) a = min(a*2,INF);
	return a;
}

state operator+(state l, state r) {
	int len0 = l.range.s-l.range.f+1, len1 = r.range.s-r.range.f+1;
	state z;
	mi p2 = pow(mi(2),len0);
	z.act = min(l.act+pow2(len0)*r.act,INF);
	z.val = l.val+p2*r.val;
	// ps("WUT",z.act,z.val,l.act,l.val,r.act,r.val);
	z.range = {l.range.f,r.range.s};
	if (len0 <= len1) {
		r.a *= p2, r.b = l.val+p2*r.b;
		// ps("WUT",r.a,r.b); exit(0);
		mi in = 1/r.a;
		FOR(i,l.range.f,l.range.s+1) {
			pref[i] = l.a*pref[i]+l.b;
			pref[i] = (pref[i]-r.b)*in;
		}
		z.a = r.a, z.b = r.b;
	} else {
		mi in = 1/l.a;
		FOR(i,r.range.f,r.range.s+1) {
			pref[i] = r.a*pref[i]+r.b;
			pref[i] = l.val+p2*pref[i];
			pref[i] = (pref[i]-l.b)*in;
		}
		z.a = l.a, z.b = l.b;
	}
	assert(z.a != 0);
	return z;
	
}

vector<state> block;
vmi sumVal;

mi solve(int l) {
	// trav(t,block) ps(t.range.f,t.range.s,t.val);
	int lo = 0, hi = sz(block)-1;
	while (lo < hi) {
		int mid = (lo+hi)/2;
		if (block[mid].range.s >= l) hi = mid;
		else lo = mid+1;
	}
	mi ret = sumVal.back()-sumVal[lo];
	// ps("HUH",ret,lo,sumVal);
	// l -> block[lo].range.s;
	mi x = pref[block[lo].range.s]*block[lo].a+block[lo].b;
	// ps("HUH",l,x,sumVal.back()); exit(0);
	if (l > block[lo].range.f) x -= pref[l-1]*block[lo].a+block[lo].b;
	x /= pow(mi(2),l-block[lo].range.f+1);
	ret += x;
	return ret;
}

int main() {
    setIO(); re(n,q); A.rsz(n); re(A);
    F0R(i,q) {
    	int l,r; re(l,r);
    	todo[r-1].pb({l-1,i});
    }
    F0R(i,n) { 
    	auto a = state(i);
    	while (sz(block) && a.act > 0) {
    		a = block.back()+a;
    		block.pop_back(); sumVal.pop_back();
    	}
    	// ps("??",a.act,a.val);
    	block.pb(a);
    	sumVal.pb(block.back().val+(sz(sumVal)?sumVal.back():0));
    	trav(t,todo[i]) ans[t.s] = solve(t.f);
    }
    F0R(i,q) ps(ans[i]);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/