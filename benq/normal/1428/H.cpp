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
void ps() { cout << endl; } // print w/ spaces
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
 
int N,M;
vi lst;
vi rig;
vi actual_rig = {0,1,7};
 
int nor(int x) {
	x %= N*M;
	if (x < 0) x += N*M;
	return x;
}
 
int calc() {
	int ans = 0;
	vb cover(N*M);
	F0R(i,N) F0R(j,M) cover[(actual_rig[i]-j+N*M)%(N*M)] = 1;
	F0R(i,N*M) ans += !cover[i];
	// dbg(actual_rig,ans);
	return ans;
}
 
int query;

int rot(int x, int d) {
	assert(0 <= x && x < N && abs(d) == 1);
	query ++; assert(query <= 15000);
	ps("?",x,d);
	if (rig[x] != -1) rig[x] = nor(rig[x]+d);
	actual_rig[x] = nor(actual_rig[x]+d);
	int res; re(res);
	// int res = calc(); 
	// dbg(actual_rig);
	// dbg(res);
	lst.pb(res);
	return lst.bk;
}
 
void finish() {
	dbg(query);
	trav(t,rig) assert(t != -1);
	pr('!');
	FOR(i,1,N) pr(' ',(rig[i]-rig[0]+N*M)%(N*M));
	ps();
}
 
void start() {
	re(N,M); rig = vi(N,-1); 
	actual_rig.rsz(N);
	FOR(i,1,N) actual_rig[i] = rand()%(N*M);
	rig[0] = 0;
}
 
bool contains(pi p, int x) {
	assert(0 <= p.f && p.s < N*M);
	return p.f <= x && x <= p.s;
}
 
// bool covered(int x) {
// 	FOR(i,1,N) if (rig[i] != -1) {
// 		pi p = {rig[i]-(M-1),rig[i]};
// 		if (contains(p,x)) return 1;
// 	}
// 	return 0;
// }
 
// bool moveExpected() {
// 	int expected = lst.bk+!covered(rig[0]-(M-1))-1;
// 	int actual = rot(0,1);
// 	dbg(expected,actual);
// 	if (expected == actual) return 1;
// 	return 0;
// }
 
bool existsStart() {
	rot(0,-1);
	rot(0,1); rot(0,1);
	bool res = lst[sz(lst)-3] < lst[sz(lst)-2] && lst[sz(lst)-2] >= lst.bk;
	rot(0,-1);
	return res;
}
 
void deal() {
	// dbg(rig,actual_rig);
	lst.clear();
	rot(0,-1); rot(0,1); rot(0,1);
	while (1) {
		if (lst[sz(lst)-3] < lst[sz(lst)-2] && lst[sz(lst)-2] >= lst.bk) {
			rot(0,-1);
			break;
		}
		rot(0,1);
	}
	// while (!existsStart()) {
	// 	rot(0,1);
	// }
	// dbg("AFTER START",rig,actual_rig,lst);
	vi cand; FOR(i,1,N) if (rig[i] == -1) cand.pb(i);
	// shuffle(all(cand),rng);
	int actual = -1;
	bool flag = 0;
	while (1) {
		assert(sz(cand));
		int t = cand.bk; rot(t,-1);
		if (flag == 0) {
			rot(0,-1);
			if (lst.bk >= lst[sz(lst)-2]) {
				rig[actual = cand.bk] = rig[0];
				rot(0,1);
				break;
			}
			flag = 1;
		} else {
			rot(0,1);
			if (lst.bk <= lst[sz(lst)-2]) {
				rig[actual = cand.bk] = nor(rig[0]-1);
				break;
			}
			flag = 0;
		}
		cand.pop_back();
	}
	F0R(_,M) rot(actual,-1);
	// dbg("RESULT",rig,actual_rig);
	// dbg("----");
}
 
int main() {
	start(); 
	F0R(_,N-1) deal();
	// dbg("START",rig,actual_rig);
	// while (1) {
	// 	int ori = rig[0];
	// 	vi bin;
	// 	FOR(i,1,N) if (rig[i] != -1) {
	// 		while (rig[i] > rig[0]) rot(i,-1);
	// 	} else bin.pb(i);
	// 	if (!sz(bin)) break;
	// 	// shuffle(all(bin),rng);
	// 	if (moveExpected()) continue;
	// 	rot(0,-1);
	// 	int ind = 0;
	// 	while (ind < sz(bin)) {
	// 		int t = bin[ind];
	// 		dbg("TESTING",bin,ind,t);
	// 		assert(rig[0] == ori);
	// 		rot(t,1);
	// 		// assert(rig[0] == ori+1);
	// 		if (moveExpected()) {
	// 			dbg("COOL",t);
	// 			rig[t] = rig[0]+M;
	// 			rot(0,-1);
	// 			break;
	// 		}
	// 		dbg("NOT EXPECTED");
	// 		assert(rig[0] == ori+1);
	// 		ind ++;
	// 		rot(0,-1);
	// 		assert(rig[0] == ori);
	// 	}
	// 	dbg(rig);
	// 	assert(ind < sz(bin));
	// 	F0R(i,ind+1) rot(bin[i],-1);
	// }
	finish();
	// you should actually read the stuff at the bottom
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/