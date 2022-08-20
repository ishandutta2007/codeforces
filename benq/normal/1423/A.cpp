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

/**
 * Description: Stable Roommates problem. Exists with -1 if no solution.
 * Time: O(N^3) (idk if this worst case is achievable tho) Can make O(N^2) if needed ...
 * Source:
 	* https://en.wikipedia.org/wiki/Stable_roommates_problem
 	* probably better to check https://codeforces.com/contest/1423/submission/94783878
 * Verification: https://codeforces.com/contest/1423/problem/A
 */

int N,A[1000][1000];
bool active[1000][1000];
deque<int> pref[1000];
int propose[1000], proposed[1000];
 
void fin() {
	ps(-1);
	exit(0);
}
 
void rem(int x, int y) {
	active[x][y] = active[y][x] = 0;
}
 
void clip(int x) {
	while (sz(pref[x]) && !active[x][pref[x].ft]) pref[x].pop_front();
	while (sz(pref[x]) && !active[x][pref[x].bk]) pref[x].pop_back();
	if (!sz(pref[x])) fin();
}
 
void ad(int x, int y) {
	assert(x != y && propose[x] == -1 && proposed[y] == -1);
	propose[x] = y, proposed[y] = x;
	while (1) {
		clip(y);
		if (pref[y].bk != x) rem(y,pref[y].bk);
		else break;
	}
	assert(pref[y].bk == x);
}
 
int nex(int x) {
	assert(sz(pref[x]) > 1);
	clip(x);
	int y = pref[x].ft; pref[x].pop_front();
	clip(x); pref[x].push_front(y);
	return proposed[pref[x][1]];
}
 
int main() {
	setIO(); re(N);
	if (N&1) fin();
	F0R(i,N) {
		F0R(j,N) if (i != j) {
			re(A[i][j]);
			pref[i].pb(j); active[i][j] = 1;
		}
		sort(all(pref[i]),[&](int x, int y) { return A[i][x] < A[i][y]; });
	}
	F0R(i,N) propose[i] = proposed[i] = -1;
	queue<int> q; F0R(i,N) q.push(i);
	while (sz(q)) {
		int x = q.ft; q.pop(); assert(propose[x] == -1);
		while (1) {
			clip(x); int y = pref[x].ft, X = proposed[y];
			if (X != -1 && A[y][X] < A[y][x]) { rem(x,y); continue; }
			if (X != -1) propose[X] = -1, proposed[y] = -1, q.push(X);
			ad(x,y); break;
		}
	}
	F0R(i,N) assert(propose[i] != -1);
	int cur = 0;
	while (1) {
		for (;cur<N;++cur) {
			clip(cur); assert(proposed[cur] != -1 && pref[cur].bk == proposed[cur]);
			if (sz(pref[cur]) > 1) break;
		}
		F0R(i,N) {
			vi tmp;
			trav(j,pref[i]) if (active[i][j]) tmp.pb(j);
		}
		if (cur == N) {
			F0R(i,N) {
				assert(proposed[propose[i]] == i);
				ps(propose[i]+1);
			}
			exit(0);
		}
		vi cyc, CYC;
		{
			int x = cur, y = cur;
			do { x = nex(x), y = nex(nex(y)); } while (x != y);
			do { cyc.pb(y); y = nex(y); } while (x != y);
		}
		trav(x,cyc) {
			int y = propose[x]; CYC.pb(y); assert(y != -1);
			propose[x] = -1, proposed[y] = -1, rem(x,y);
		}
		F0R(i,sz(cyc)) ad(cyc[i],CYC[(i+1)%sz(cyc)]);
	}
}