#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python!
 
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
 
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;
 
#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;
 
// pairs
#define mp make_pair
#define f first
#define s second
 
// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front
 
#define lb lower_bound
#define ub upper_bound 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
 
// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
 
// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
	return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }
 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
 
tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }
 
tcTU> T fstTrue(T lo, T hi, U f) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo+1)/2;
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
tcT> void remDup(vector<T>& v) { // sort and remove duplicates
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { // don't erase
	auto it = t.find(u); assert(it != end(t));
	t.erase(it); } // element that doesn't exist from (multi)set
 
// INPUT
#define tcTUU tcT, class ...U
tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(V<T>& v);
tcT, size_t SZ> void re(AR<T,SZ>& a);
 
tcT> void re(T& x) { cin >> x; }
void re(double& d) { str t; re(t); d = stod(t); }
void re(long double& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }
 
tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(V<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { trav(a,x) re(a); }
tcT> void rv(int n, V<T>& x) { x.rsz(n); re(x); }
 
// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	// #ifdef LOCAL
	// 	return b ? "true" : "false"; 
	// #else 
	return ts((int)b);
	// #endif
}
tcT> str ts(complex<T> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(V<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
tcTU> str ts(pair<T,U> p);
tcT> str ts(T v) { // containers with begin(), end()
	#ifdef LOCAL
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;
 
	#endif
}
tcTU> str ts(pair<T,U> p) {
	#ifdef LOCAL
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
}
 
// OUTPUT
tcT> void pr(T x) { cout << ts(x); }
tcTUU> void pr(const T& t, const U&... u) { 
	pr(t); pr(u...); }
void ps() { pr("\n"); } // print w/ spaces
tcTUU> void ps(const T& t, const U&... u) { 
	pr(t); if (sizeof...(u)) pr(" "); ps(u...); }
 
// DEBUG
void DBG() { cerr << "]" << endl; }
tcTUU> void DBG(const T& t, const U&... u) {
	cerr << ts(t); if (sizeof...(u)) cerr << ", ";
	DBG(u...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif
 
void setPrec() { cout << fixed << setprecision(15); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void setIO(str s = "") {
	unsyncIO(); setPrec();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for USACO
}
 
/**
 * Description: modular arithmetic operations 
 * Source: 
	* KACTL
	* https://codeforces.com/blog/entry/63903
	* https://codeforces.com/contest/1261/submission/65632855 (tourist)
	* https://codeforces.com/contest/1264/submission/66344993 (ksun)
	* also see https://github.com/ecnerwala/cp-book/blob/master/src/modnum.hpp (ecnerwal)
 * Verification: 
	* https://open.kattis.com/problems/modulararithmetic
 */
 
template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint() { v = 0; }
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	friend void re(mint& a) { ll x; re(x); a = mint(x); }
	friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = int((ll)v*m.v%MOD); return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};
 
typedef mint<MOD,5> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;
 
vector<vmi> scmb; // small combinations
void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	FOR(i,1,SZ) F0R(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}
 
// mi dp[][];
int N;
map<pair<vi,pi>,mi> dp;
 
// vi x;
// int bef, rem;
mi perm[45][45];
 
// mi no(int len) {
// 	return pow(perm[bef-1][rem],len);
// }
 
// mi whatever(int len) {
// 	return pow(perm[bef][rem],len);
// }
 
// mi yes(int len) {
// 	return whatever(len)-no(len);
// 	// return rem*perm[bef-1][rem-1];
// }
 
vi cyc_len;
 
// void dfs_add(vi y, mi num, int ind) {
// 	if (ind == sz(x)) {
// 		dp[{x,y}] += num;
// 		return;
// 	}
// 	num *= pow(whatever(cyc_len[ind]),y[ind]);
// 	int dif = x[ind]-y[ind];
// 	mi YES = yes(cyc_len[ind]), NO = no(cyc_len[ind]);
// 	F0R(j,dif+1) {
// 		mi mul = num*scmb[dif][j]*pow(YES,j)*pow(NO,dif-j);
// 		vi Y = y; Y[ind] = y[ind]+j;
// 		dfs_add(Y,mul,ind+1);
// 	}
// 	// y[ind] are available: do whatever
// 		// perm(bef,rem)
// 	// x[ind]-y[ind] are not
// 		// either rem*perm(bef-1,rem-1) -> make available
// 		// or perm(bef-1,rem) -> not make available
// }

void dfs_add(vi rem, pi lst, mi ways, int ind, int nex_lst) {
	if (ind == sz(cyc_len)) {
		if (nex_lst) dp[{rem,{lst.f+lst.s,nex_lst}}] += ways;
		return;
	}
	mi whoops;
	if (lst == mp(0,0)) {
		whoops = pow(perm[N-1][N-1],cyc_len[ind]);
	} else {
		whoops =  pow(perm[N][lst.f]*perm[N-lst.f][lst.s]  *perm[N-1-lst.f-lst.s][N-1-lst.f-lst.s],cyc_len[ind]);
		whoops -= pow(perm[N][lst.f]*perm[N-1-lst.f][lst.s]*perm[N-1-lst.f-lst.s][N-1-lst.f-lst.s],cyc_len[ind]);
		// perm[N][lst.f]
		// perm[N-lst.f][lst.s]: first
		// perm[N-1-lst.f][lst.s]: not first
		// perm[N-1-lst.f-lst.s][N-1-lst.f-lst.s]
	}
	// dbg(lst,whoops);
	// mi whoops = ways_to_assign();
	F0R(i,rem[ind]+1) {
		vi REM = rem; REM[ind] -= i;
		dfs_add(REM,lst,ways*pow(whoops,i)*scmb[rem[ind]][i],ind+1,nex_lst+i*cyc_len[ind]);
	}
}

int sum(vi v) { // OK
	int res = 0;
	F0R(i,sz(v)) res += v[i]*cyc_len[i];
	return res;
}
 
int main() {
	setIO();
	re(N);
	genComb(45);
	F0R(i,45) {
		perm[i][0] = 1;
		FOR(j,1,i+1) perm[i][j] = perm[i][j-1]*(i+1-j);
	}
	// dbg(perm[4][3], perm[4][2]);
 
	vi P(N); re(P);
	trav(t,P) --t;
	vb vis(N);
	map<int,int> cyc;
	F0R(i,N) if (!vis[i]) {
		int cnt = 0;
		int cur = i;
		while (!vis[cur]) {
			vis[cur] = 1;
			++cnt;
			cur = P[cur];
		}
		++ cyc[cnt];
	}
	vi st;
	trav(t,cyc) {
		cyc_len.pb(t.f);
		st.pb(t.s);
	}
	// how many left, how many processed on previous round
	dp[{st,{0,0}}] = 1;
	assert(sum(st) == N);
	mi ans = 0;
	while (sz(dp)) {
		auto it = prev(end(dp));
		pair<pair<vi,pi>,mi> a = *it; dp.erase(it);
		if (sum(a.f.f) == 0) {
			assert(a.f.s.f+a.f.s.s == N);
			ans += a.s;
		} else {
			dfs_add(a.f.f,a.f.s,a.s,0,0);
		}
		// dbg("DOING",a);
		// int ind = 0; while (ind < sz(a.f.s) && a.f.s[ind] == 0) ++ind;
		// bef = sum(a.f.f);
		// if (ind == sz(a.f.s)) { // none to remove
		// 	if (bef == 0) ans += a.s;
		// 	continue;
		// }
		// { // just ignore it
		// 	x = a.f.f; --a.f.s[ind]; 
		// 	dp[{x,a.f.s}] += a.s;
		// }
		// --x[ind];
		// rem = cyc_len[ind]; // # that were removed
		// a.s *= pow(perm[bef-1][bef-1],rem);
		// dfs_add(a.f.s,a.s,0);
	}
	ps(ans);
	
	// you should actually read the stuff at the bottom
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/