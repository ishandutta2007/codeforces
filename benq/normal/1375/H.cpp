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
constexpr int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 
int fstTrue(function<bool(int)> f, int lo, int hi) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		int mid = (lo+hi)/2; 
		f(mid) ? hi = mid : lo = mid+1; 
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
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
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
	bool fst = 1; str res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += ts(x);
	}
	res += "}"; return res;
}
template<class A, class B> str ts(pair<A,B> p) {
	return "("+ts(p.f)+", "+ts(p.s)+")"; }

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
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(string s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

const int BLOCK = 1<<8;
int n,q;
vi blocks[16];
vi a;

vpi sets;

int merge(int a, int b) {
	if (!min(a,b)) return max(a,b);
	int label = n+1+sz(sets); sets.pb({a,b});
	return label;
}

vector<vi> construct(vi v) {
	//dbg("HA",v);
	assert(sz(v));
	int mn = MOD, mx = -MOD;
	trav(t,v) ckmin(mn,a[t]), ckmax(mx,a[t]);
	assert(mx-mn+1 == sz(v));
	if (sz(v) == 1) return {{v[0]+1}};
	vi l, r;
	trav(t,v) {
		if (a[t] <= (mn+mx)/2) l.pb(t);
		else r.pb(t);
	}
	auto L = construct(l), R = construct(r);
	vector<vi> res(sz(v),vi(sz(v)));
	int lef = 0, rig = 0;
	F0R(i,sz(v)) {
		while (lef < sz(l) && l[lef] < v[i]) lef ++;
		while (rig < sz(r) && r[rig] < v[i]) rig ++;
		int LEF = lef-1, RIG = rig-1;
		FOR(j,i,sz(v)) {
			if (LEF+1 < sz(l) && l[LEF+1] == v[j]) LEF ++;
			if (RIG+1 < sz(r) && r[RIG+1] == v[j]) RIG ++;
			if (lef <= LEF) res[i][j] = merge(res[i][j],L[lef][LEF]);
			if (rig <= RIG) res[i][j] = merge(res[i][j],R[rig][RIG]);
		}
		assert(LEF == sz(l)-1 && RIG == sz(r)-1);
	}
	return res;
}

int get(int l, int r, vi& v, vector<vi>& b) {
	int lo = 0; while (lo < sz(v) && v[lo] < l) lo ++;
	int hi = -1; while (hi+1 < sz(v) && v[hi+1] <= r) hi ++;
	if (lo > hi) return 0;
	dbg("HUH",v,lo,hi,b[lo][hi]);
	return b[lo][hi];
}

int main() {
	setIO(); re(n,q); // OK
	a.rsz(n); re(a);
	F0R(i,n) { // OK
		int p = cdiv(a[i],BLOCK)-1; assert(p < 16);
		blocks[p].pb(i);
	}
	vector<vector<vi>> BLOCKS;
	F0R(i,16) if (sz(blocks[i])) BLOCKS.pb(construct(blocks[i]));
	vi ans(q);
	F0R(i,q) {
		int l,r; re(l,r); l--,r--;
		F0R(j,sz(BLOCKS)) ans[i] = merge(ans[i],get(l,r,blocks[j],BLOCKS[j])); 
	}
	ps(n+sz(sets));
	trav(t,sets) ps(t.f,t.s);
	trav(t,ans) pr(t,' ');
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/