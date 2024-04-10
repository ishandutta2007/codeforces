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
const int MX = 200005;
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

int modsqrt(mi a) { // change modular int to accept long longs
    mi p = pow(a,(MOD-1)/2); if (p != 1) return p == 0 ? 0 : -1;
    ll s = MOD-1, e = 0; while (s % 2 == 0) s /= 2, e ++;
    mi n = 1; while (pow(n,(MOD-1)/2) == 1) n = (int)(n)+1; // find non-square residue

    mi x = pow(a,(s+1)/2), b = pow(a,s), g = pow(n,s);
    int r = e;
    while (1) {
        mi B = b; int m = 0; while (B != 1) B *= B, m ++;
        if (m == 0) break;
        F0R(i,r-m-1) g *= g;
        x *= g; g *= g; b *= g; r = m;

        /* Explanation:
         * Initially, x^2=ab, ord(b) = 2^m, ord(g) = 2^r where m<r
         * g = g^{2^{r-m-1}} -> ord(g) = 2^{m+1}
         * if x'=x*g, then b' = b*g^2
                (b')^{2^{m-1}} = (b*g^2)^{2^{m-1}}
                               = b^{2^{m-1}}*g^{2^m}
                               = -1*-1
                               = 1
            -> ord(b')|ord(b)/2
         * m decreases by at least one each iteration
         */
    }
    return min((int)x,MOD-(int)x);
}

typedef pair<pmi,mi> circ;
mi cx, cy, c;
int n;
vpl a;
vl d;
set<pi> ans;

ll sq(ll x) { return x*x; }
mi sq(mi x) { return x*x; }
mi norm(pmi b) { return sq(b.f)+sq(b.s);}
bool on(circ a, pmi b) {
	return sq(a.f.f-b.f)+sq(a.f.s-b.s) == a.s;
}
ll sim(mi X) {
	int x = (int)X;
	if (x > abs(x-MOD)) x -= MOD;
	return x;
}
ll dis(pl a, pl b) { return sq(a.f-b.f)+sq(a.s-b.s); }

void check(ll dtest, pmi T) {
	pl t = {sim(T.f),sim(T.s)};
	if (dis(t,a[0]) != dtest) return;
	vl D; trav(A,a) D.pb(dis(t,A)); sort(all(D));
	if (d == D) ans.insert(t);
}

vpmi inter(circ a, circ b) {
	// (x-a.f.f)^2+(y-a.f.s)^2=a.s
	// (x-b.f.f)^2+(y-b.f.s)^2=b.s
	
	// 2x(a.f.f-b.f.f)+b.f.f^2-a.f.f^2
	// +2y(a.f.s-b.f.s)+b.f.s^2-a.f.s^2
	// =b.s-a.s
	array<mi,3> eq = {2*(a.f.f-b.f.f),2*(a.f.s-b.f.s),b.s-a.s+norm(a.f)-norm(b.f)};
	
	// eq[0]*x+eq[1]*y == eq[2]
	if (eq[0] != 0) {
		eq[1] /= eq[0], eq[2] /= eq[0]; eq[0] = 0;
		// x == eq[2]-eq[1]*y
		// (-eq[1]*y+eq[2]-a.f.f)^2+(y-a.f.s)^2 = a.s
		mi A = eq[1]*eq[1]+1;
		mi B = -2*eq[1]*(eq[2]-a.f.f)-2*a.f.s;
		mi C = sq(eq[2]-a.f.f)+sq(a.f.s)-a.s;
		if (A == 0) {
			ps("ZERO??");
			exit(0);
		}
		B /= A, C /= A;
		mi dis = B*B-4*C; 
		int s = modsqrt(dis); if (s == -1) return {};
		vmi Y = {(-B+s)/2, (-B-s)/2};
		vpmi SOL; trav(y,Y) SOL.pb({eq[2]-eq[1]*y,y});
		return SOL;
		exit(0);
		// return (-B+-sqrt(B*B-4*C))/2
	} else {
		// ps("ZERO!",eq);
		assert(eq[1] != 0); mi y = eq[2]/eq[1];
		a.s -= sq(y-a.f.s);
		int s = modsqrt(a.s); if (s == -1) return {};
		// exit(0);
		return {mp(a.f.f+s,y),mp(a.f.f-s,y)};
	}
	// ps("HUH",a,b,eq,eq[0]+eq[1] == eq[2]);
}

void solve() {
	ans.clear();
	d.rsz(n); re(d); sort(all(d));
	mi tot = n*(cx*cx+cy*cy)-c; trav(t,d) tot += t;
	tot /= n;
	circ c0 = {{cx,cy},tot};
	F0R(i,n) if (i == 0 || d[i] != d[i-1]) {
		circ c1 = {{a[0].f,a[0].s},d[i]};
		vpmi v = inter(c0,c1);
		trav(t,v) check(d[i],t);
		// ps("??",v);
		// ps(on(c0,{1,1}),on(c1,{1,1}));
	}
	pr(sz(ans),' ');
	trav(t,ans) pr(t.f,' ',t.s,' ');
	ps();
	// sum((x-a.f)^2+sum(y-a.s)^2=tot
	// -> n*(x-a.f)^2+n*(y-a.s)^2=??
}

int main() {
	setIO(); re(n); a.rsz(n); re(a);
	trav(t,a) {
		cx += t.f; cy += t.s;
		c += t.f*t.f+t.s*t.s;
	}
	cx /= n, cy /= n;
	if (a[0].f == cx && a[0].s == cy) swap(a[0],a[1]);
	// ps(cx,cy,c);
	// n*(x-cx)^2+n*(y-cy)^2=c
	int m; re(m);
	F0R(i,m) solve();
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/