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

ll n,a,b,c;

/*bool dumb(int x, int y, pi p, ll lef) {
	
}*/

ll  dist(pi a, pi b) {
	return abs(a.f-b.f)+abs(a.s-b.s);
}

bool valid(array<array<ll,2>,2> lef) {
	F0R(i,2) F0R(j,2) if (lef[i][j] < 0) return 0;
	return 1;
}

ll sum(ll B, ll C) { return (C-B+1)*(B+C)/2; }

ll arith(pi a, pi b, pi c) {
	ll B = dist(a,b), C = dist(a,c);
	if (B < C) return sum(B+1,C);
	return sum(C,B-1);
}

bool ok(ll x, ll y, array<array<ll,2>,2> lef) {
	// ps("START",x,y,lef);
	if (x < a) {
		F0R(i,2) F0R(j,2)
			lef[i][j] -= arith({a+i*c,b+j*c},{x,y},{a,y});
		x = a;
	}
	if (y < b) {
		F0R(i,2) F0R(j,2)
			lef[i][j] -= arith({a+i*c,b+j*c},{x,y},{x,b});
		y = b;
	}
	if (x >= a+c && y < b+c) {
		F0R(i,2) F0R(j,2)
			lef[i][j] -= arith({a+i*c,b+j*c},{x,y},{x,b+c});
		y = b+c;
	}
	if (x < a+c && y >= b+c) {
		F0R(i,2) F0R(j,2)
			lef[i][j] -= arith({a+i*c,b+j*c},{x,y},{a+c,y});
		x = a+c;
	}
	// ps("OK",x,y,a,b,a+c,b+c,lef);
	if (x >= a+c && y >= b+c) {
		F0R(i,2) F0R(j,2) 
			lef[i][j] -= arith({a+i*c,b+j*c},{x,y},{n,n});
		x = n, y = n;
		// ps("??",lef);
		// ps();
		return valid(lef);
	}
	assert(x < a+c && y < b+c);
	F0R(i,2) F0R(j,2) lef[i][j] -= arith({a+i*c,b+j*c},{a+c,b+c},{n,n});
	F0R(i,2) lef[i][i] -= arith({a+i*c,b+i*c},{x,y},{a+c,b+c});
	return valid(lef)
		&& lef[1][0] >= arith({a+c,b},{x,y},{a+c,y})+arith({a+c,b},{a+c,y},{a+c,b+c}) 
		&& lef[0][1] >= arith({a,b+c},{x,y},{x,b+c})+arith({a,b+c},{x,b+c},{a+c,b+c})
		&& lef[1][0]+lef[0][1] >= 2*c*((a+c)+(b+c)-x-y);
	// F0R(i,2) F0R(j,2)
		// if (dumb(x,y,{a+i*c,b+j*c},lef[i][j])) return 0;
	// return 1; // tot decrease of up-left and bot-right <= smth
}

void bad() {
	ps("Impossible");
	exit(0);
}

ll sum(ll x) {
	return x*(x+1)/2;
}

int main() {
	// setIO("Z"); 
	ll t; re(n,t,a,b,c); c --;
	int z = a+b;
	
	// (1,1) to (n,n)
	// x = a or a+c-1, y = b or b+c-1
	array<array<ll,2>,2> lef; F0R(i,2) F0R(j,2) lef[i][j] = t;
	int x = 1,y = 1;
	if (!ok(x,y,lef)) bad();
	while (x+y < 2*n) {
		int X = x+1;
		auto LEF = lef;
		F0R(i,2) F0R(j,2) LEF[i][j] -= dist({a+c*i,b+c*j},{X,y});
		if (x < n && ok(X,y,LEF)) {
			x ++;
			pr('R');
		} else {
			y ++;
			pr('U');
		}
		F0R(i,2) F0R(j,2) lef[i][j] -= dist({a+c*i,b+c*j},{x,y});
		// ps("HUH",x,y,lef);
	}
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/