#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
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

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
constexpr int pct(int x) { return __builtin_popcount(x); } 
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
ll half(ll x) { return fdiv(x,2); }

template<class T, class U> T fstTrue(T lo, T hi, U f) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = half(lo+hi);
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
template<class T, class U> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = half(lo+hi+1);
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
template<class T> void remDup(vector<T>& v) { 
	sort(all(v)); v.erase(unique(all(v)),end(v)); }

// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }

// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	#ifdef LOCAL
		return b ? "true" : "false"; 
	#else 
		return ts((int)b);
	#endif
}
template<class A> str ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { // containers with begin(), end()
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
template<class A, class B> str ts(pair<A,B> p) {
	#ifdef LOCAL
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
}

// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
	pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) { 
	pr(h); if (sizeof...(t)) pr(" "); ps(t...); }

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
	#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
	#define dbg(...) 0
#endif

// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(str s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

/**
 * Description: Disjoint Set Union with Rollback
 * Source: see DSU
 * Verification: *
 */

struct DSUrb {
	vi e, off; void init(int n) { e = vi(n,-1); off = vi(n); }
	pi get(int x) {
		int OFF = 0;
		while (e[x] >= 0) {
			OFF ^= off[x];
			x = e[x];
		}
		return {x,OFF};
	}
	vector<array<int,4>> mod;
	int unite(int _x, int _y) { // union by size
		pi x = get(_x), y = get(_y);
		if (x.f == y.f) {
			if (x.s == y.s) return 0;
			mod.pb({-1,-1,-1,-1});
			return 1;
		}
		if (e[x.f] > e[y.f]) swap(x,y);
		mod.pb({x.f,y.f,e[x.f],e[y.f]});
		e[x.f] += e[y.f]; e[y.f] = x.f; off[y.f] = x.s^y.s^1;
		return 1;
	}
	void rollback() {
		auto a = mod.bk; mod.pop_back();
		if (a[0] != -1) e[a[0]] = a[2], e[a[1]] = a[3];
	}
};

DSUrb D;
int N,M,Q;
int fst[MX],u[MX],v[MX];

bool ad(int ind) { 
	dbg("AD",ind);
	if (ind == M+1) return 1;
	return D.unite(u[ind],v[ind]); 
}
void restore(int _sz) { 
	while (sz(D.mod) > _sz) {
		D.rollback(); 
		dbg("ROLLBACK");
	}
}

void divi(int xl, int xr, int yl, int yr) { 
	// removing xr ... yr is bipartite, move ? left while possible
	if (xl > xr) return;
	dbg("DIVI",xl,xr,yl,yr,sz(D.mod));
	assert(yl <= yr);
	int xm = (xl+xr)/2;
	int res = -1;
	int _sz = sz(D.mod);
	FOR(i,xl,xm) if (!ad(i)) { 
		res = yr; assert(res == M+1);
		break;
	}
	int _sz2 = sz(D.mod);
	if (res == -1) {
		int i = yr; while (i > yl && ad(i)) i --;
		res = i;
	}
	fst[xm] = res;
	dbg("SET",xm,fst[xm]);
	if (fst[xm] == M+1) {
		FOR(i,xm+1,xr+1) fst[i] = M+1;
	} else {
		restore(_sz2);
		if (!ad(xm)) {
			FOR(i,xm+1,xr+1) fst[i] = M+1;
		} else {
			divi(xm+1,xr,fst[xm],yr);
		}
	}
	restore(_sz);
	FOR(i,fst[xm]+1,yr+1) assert(ad(i));
	divi(xl,xm-1,yl,fst[xm]); // add those from fst[xm] to r-1
	restore(_sz);
}

int main() {
	setIO(); re(N,M,Q); D.init(N+1);
	FOR(i,1,M+1) re(u[i],v[i]);
	divi(1,M,1,M+1);
	FOR(i,1,M+1) dbg(i,fst[i]);
	// FOR(i,1,M+1) {
	// 	DSUrb D; D.init(N+1);
	// 	FOR(j,1,i) {
	// 		if (!D.unite(u[j],v[j])) {
	// 			fst[i] = M+1;
	// 			break;
	// 		}
	// 		dbg("UNITED",u[j],v[j]);
	// 	}
	// 	if (fst[i] == M+1) continue;
	// 	int j = M; 
	// 	while (j >= i) {
	// 		if (D.unite(u[j],v[j])) j --;
	// 		else {
	// 			dbg("NOPE",u[j],v[j]);
	// 			break;
	// 		}
	// 	}
	// 	fst[i] = j;
	// 	dbg(i,fst[i]);
	// }
	F0R(i,Q) {
		int l,r; re(l,r);
		if (r >= fst[l]) ps("NO");
		else ps("YES");
	}
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/