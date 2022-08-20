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
const int MX = 2e5+5;
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
	
	void ps() { cout << endl; } // print w/ spaces
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

int n,k;

bool query(int x) {
	ps('?',x+1);
	char c; re(c); return c == 'Y';
}

void fin(int d) {
	ps('!',d);
	exit(0);
}

void reset() {
	ps("R");
}

vi rem[1024];

void red(vi& a, vi& b) {
	if (!sz(a) || !sz(b)) return;
	//ps("RED",a,b);
	reset();
	vi A,B;
	trav(t,a) query(t);
	trav(t,b) if (!query(t)) B.pb(t);
	int pos = sz(a)+sz(b);
	F0R(i,sz(a)) if (i+k < sz(a)+sz(b)-1) {
		while (pos-(i+k) <= k) { query(b.bk); pos ++; }
		pos ++; if (!query(a[i])) A.pb(a[i]);
	} else A.pb(a[i]);
	swap(a,A), swap(b,B);
}

int main() {
	re(n,k);
	// F0R(i,n) rem[i/k].pb(i);
	F0R(i,n) {
		if (i%k == 0) reset();
		if (!query(i)) rem[i/k].pb(i);
	}
	//F0R(i,n/k) ps("HA",rem[i]);
	F0R(i,n/k) FOR(j,i+1,n/k) red(rem[i],rem[j]);
	// ps("??",rem[0],rem[1]);
	int ans = 0; F0R(i,n/k) ans += sz(rem[i]);
	fin(ans);
	// n+3*k*n/k*(n/k-1)/2
	/*vi rem; F0R(i,n) rem.pb(i);
	int ok = 0;
	while (sz(rem)) {
		reset();
		vi CUR, REM;
		int up = min(sz(rem),k);
		F0R(i,up) {
			int x = rem.bk; rem.pop_back();
			if (!query(x)) CUR.pb(x);
		}
		while (sz(rem)) {
			vi v; while (sz(rem) && sz(v) < k) v.pb(rem.bk), rem.pop_back();
			reset();
			trav(t,CUR) query(t);
			trav(t,v) if (!query(t)) REM.pb(t);
			// 0 to sz(CUR)-1
			// sz(CUR) to sz(CUR)+sz(v)-1
			vi cur;
			F0R(i,sz(CUR)) if (i+k < sz(CUR)+sz(v)-1) {
				int pos = sz(CUR)+sz(v);
				while (pos-(i+k) <= k) { query(v.bk); pos ++; }
				if (!query(CUR[i])) cur.pb(CUR[i]);
			}
			swap(cur,CUR);
		}
		ok += sz(CUR); swap(rem,REM);
	}
	fin(ok);*/
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
*/