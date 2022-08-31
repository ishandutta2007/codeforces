#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
using db = double; 
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
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

// helper funcs
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

#define tcTU tcT, class U
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
	t.erase(u); } // element that doesn't exist from (multi)set

// INPUT
#define tcTUU tcT, class ...U
tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(vector<T>& v);
tcT, size_t SZ> void re(AR<T,SZ>& a);

tcT> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }

tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(vector<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { trav(a,x) re(a); }

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
tcT> str ts(complex<T> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
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

// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

int n;
vi x;
int cool[1200][1200];
int col[1200];

bool get(int l, int r) {
	if (l > r) return 1;
	return cool[l][r];
}

V<AR<int,3>> trip[2];


const AR<int,3> ID = {-1,-1,-1};
bool lef[1200];
int nex[1200];

bool match(int a, pi b) {
	if (b.f > b.s) return 0;
	return col[a] == col[b.f];
}

bool ok[1201][2];
pi pre[1201][2];
bool rooted[1201];

void oops(int i, int j) {
	if (col[i] != col[j]) return;
	for (int k = i+2; k < j; k += 3) if (col[k] == col[k+1])
		cool[i][j] |= get(i,k)&get(k+1,j);
	for (int k = i+1; k < j; k += 3) 
		if (col[i] == col[k] && !match(i,{i+1,k-1}) && !match(i,{k+1,j-1}))
			cool[i][j] |= get(i+1,k-1)&get(k+1,j-1);
}

void gen(int i, int j, int start = 0) {
	if (i > j) return;
	assert(cool[i][j] && col[i] == col[j]);
	for (int k = i+2; k < j; k += 3) if (col[k] == col[k+1])
		if (get(i,k) && get(k+1,j)) {
			assert(!start);
			gen(i,k); gen(k+1,j);
			return;
		}
	for (int k = i+1; k < j; k += 3) 
		if (col[i] == col[k] && !match(i,{i+1,k-1}) && !match(i,{k+1,j-1}))
			if (get(i+1,k-1) && get(k+1,j-1)) {
				trip[col[i]].pb({i,k,j});
				gen(i+1,k-1); gen(k+1,j-1);
				return;
			}
	assert(0);
}


int main() {
	setIO(); re(n); x.rsz(3*n); re(x);
	F0R(i,6*n) col[i] = 1;
	trav(t,x) {
		t --;
		col[t] = 0;
	}
	R0F(i,6*n) for (int j = i+2; j < 6*n; j += 3) {
		oops(i,j);
	}
	// gen(0,6*n-1);
	ok[0][0] = 1;
	F0R(i,6*n) F0R(p,2) if (ok[i][p]) 
		FOR(j,i+1,6*n+1) if (cool[i][j-1]) {
			int P = p|col[i];
			ok[j][P] = 1;
			pre[j][P] = {i,p};
		}
	assert(ok[6*n][1]);
	vi ends; 
	pi cur = {6*n,1};
	while (cur.f) {
		ends.pb(cur.f);
		cur = pre[cur.f][cur.s];
	}
	ends.pb(0);
	reverse(all(ends));
	F0R(i,sz(ends)-1) gen(ends[i],ends[i+1]-1,1);	
	trav(t,ends) rooted[t] = 1;
	F0R(j,6*n) lef[j] = 1;
	F0R(i,2*n) {
		int lst = -1;
		F0R(j,6*n) if (lef[j]) {
			if (lst != -1) nex[lst] = j;
			lst = j;
		}
		AR<int,3> test = ID;
		trav(t,trip[i&1]) if (nex[t[0]] == t[1] && nex[t[1]] == t[2] && !rooted[t[0]])
			test = t;
		if (test == ID) {
			trav(t,trip[i&1]) if (nex[t[0]] == t[1] && nex[t[1]] == t[2] && rooted[t[0]])
				test = t;
		}
		assert(test != ID);
		trip[i&1].erase(find(all(trip[i&1]),test));
		lef[test[0]] = lef[test[1]] = lef[test[2]] = 0;
		ps(test[0]+1,test[1]+1,test[2]+1);
	}
	// dbg(dp[0][6*n-1]);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/