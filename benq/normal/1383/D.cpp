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

int n,m,A[250][250];

int main() {
	setIO(); re(n,m);
	F0R(i,n) F0R(j,m) re(A[i][j]);
	vi row, col;
	F0R(i,n) {
		int res = 0;
		F0R(j,m) ckmax(res,A[i][j]);
		row.pb(res);
	}
	F0R(j,m) {
		int res = 0;
		F0R(i,n) ckmax(res,A[i][j]);
		col.pb(res);
	}
	dbg(row);
	dbg(col);
	sort(all(row)), sort(all(col));
	map<int,int> cnt;
	trav(t,row) cnt[t] ++;
	trav(t,col) cnt[t] ++;
	vi val;
	trav(t,cnt) if (t.s == 2) val.pb(t.f);
	reverse(all(val));
	reverse(all(row));
	reverse(all(col));
	vector<vi> ROW(sz(val)), COL(sz(val));
	auto ins = [&](vector<vi>& a, int b) {
		int ind = 0;
		while (ind+1 < sz(val) && b <= val[ind+1]) ind ++;
		if (val[ind] == b) return;
		if (sz(a[ind])) assert(a[ind].bk > b);
		a[ind].pb(b);
	};
	trav(t,row) ins(ROW,t);
	trav(t,col) ins(COL,t);
	vector<vi> ans(n,vi(m));
	vector<bool> done(n*m+1);
	int r = 0, c = 0;
	F0R(i,sz(val)) {
		int R = r, C = c;
		ans[R][C] = val[i]; r ++, c ++;
		trav(t,ROW[i]) ans[r++][C] = t;
		trav(t,COL[i]) ans[R][c++] = t;
	}
	assert(r == n && c == m);
	vi lef(n,MOD), rig(n,-MOD);
	F0R(i,n) F0R(j,m) if (ans[i][j]) {
		done[ans[i][j]] = 1;
		ckmin(lef[i],j); ckmax(rig[i],j);
	}
	F0R(i,n) assert(lef[i] != MOD);
	auto get = [&](int r, int c) {
		if (r < 0 || r >= n || c < 0 || c >= m) return 0;
		return ans[r][c];
	};
	auto place = [&](int r, int c, int x) -> bool {
		if (c < 0 || c >= m) return 0;
		int a = max(get(r-1,c),get(r+1,c)); if (a < x) return 0;
		int b = max(get(r,c+1),get(r,c-1)); if (b < x) return 0;
		ans[r][c] = x;
		return 1;
	};
	ROF(i,1,n*m+1) if (!done[i]) {
		bool ok = 0;
		F0R(row,n) {
			if (place(row,lef[row]-1,i)) { lef[row] --; ok = 1; break; }
			if (place(row,rig[row]+1,i)) { rig[row] ++; ok = 1; break; }
		}
		assert(ok);
	}
	F0R(i,n) assert(lef[i] == 0 && rig[i] == m-1);
	trav(t,ans) ps(t);
	dbg(val);
	dbg(ROW);
	dbg(COL);
	// somehow modify A to get result?
	// permute rows / cols?
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/