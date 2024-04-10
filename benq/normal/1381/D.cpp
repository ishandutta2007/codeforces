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

int n,a,b;
vi adj[MX];
int up[MX], down[MX],depth[MX],par[MX];

void dfs(int x, int y) {
	depth[x] = depth[y]+1; par[x] = y;
	trav(t,adj[x]) if (t != y) {
		dfs(t,x);
		ckmax(down[x],down[t]);
	}
	down[x] ++;
}

int del(pi a, int b) {
	if (a.f == b) return a.s;
	return a.f;
}

void ad(pi& a, int b) {
	if (a.f < b) swap(a.f,b);
	if (a.s < b) swap(a.s,b);
}

void dfs2(int x, int y) {
	pi p = {1+up[x],0};
	trav(t,adj[x]) if (t != y) ad(p,1+down[t]);
	trav(t,adj[x]) if (t != y) {
		up[t] = del(p,1+down[t]);
		dfs2(t,x);
	}
}

int getPath(int x, int y) {
	if (par[y] == x) return down[y]+1;
	assert(par[x] == y); return up[x]+1;
}

int len;

bool visLef[MX], visRig[MX];
int lefVal[MX], rigVal[MX];

void genLefVal(int a, int b) {
	lefVal[a] = lefVal[b]-1;
	trav(t,adj[a]) if (t != b) genLefVal(t,a);
}

void genRigVal(int a, int b) {
	rigVal[a] = rigVal[b]+1;
	trav(t,adj[a]) if (t != b) genRigVal(t,a);
}

bool stuck() {
	FOR(i,1,n+1) {
		visLef[i] = visRig[i] = 0;
	}
	vi path = {b};
	while (path.bk != a) path.pb(par[path.bk]);
	reverse(all(path));
	//dbg("STUCK");
	F0R(i,sz(path)) {
		int x = path[i]; lefVal[x] = rigVal[x] = i;
		trav(t,adj[x]) {
			if (i && t == path[i-1]) continue;
			if (i+1 < sz(path) && t == path[i+1]) continue;
			dbg(path,x,t);
			genLefVal(t,x); genRigVal(t,x);
		}
	}
	// dbg("MIDDLE");
	// return 0;
	int bet = sz(path)-1;
	queue<int> lef, rig;
	auto adRig = [&](int x) {
		if (visRig[x]) return;
		visRig[x] = 1; rig.push(x);
	};
	auto adLef = [&](int x) {
		if (visLef[x]) return;
		visLef[x] = 1; lef.push(x);
	};
	auto processLef = [&](int x) {
		// dbg("PROCESSLEF",x);
		// trav(t,adj[x]) dbg(t,lefVal[t]);
		trav(t,adj[x]) if (lefVal[t] < lefVal[x]) adLef(t);
		int ind = lefVal[x]+bet;
		if (0 <= ind && ind < sz(path)) adRig(path[ind]);
	};
	auto processRig = [&](int x) {
		// dbg("PROCESSRIG",x);
		trav(t,adj[x]) if (rigVal[t] > rigVal[x]) adRig(t);
		int ind = rigVal[x]-bet;
		if (0 <= ind && ind < sz(path)) adLef(path[ind]);
	};
	adLef(a), adRig(b);
	while (sz(lef) || sz(rig)) {
		if (sz(lef)) {
			int x = lef.ft; lef.pop();
			processLef(x);
		}
		if (sz(rig)) {
			int x = rig.ft; rig.pop();
			processRig(x);
		}
	}
	int mn = 0, mx = bet;
	FOR(i,1,n+1) {
		if (visLef[i]) ckmin(mn,lefVal[i]);
		if (visRig[i]) ckmax(mx,rigVal[i]);
	}
	dbg(mn,mx);
	if (mx-bet < mn+bet) return 1;
	return 0;
}

void solve() {
	re(n,a,b); FOR(i,1,n+1) adj[i].clear(), up[i] = 0, down[i] = 0, par[i] = 0, depth[i] = 0;
	F0R(i,n-1) {
		int x,y; re(x,y);
		adj[x].pb(y), adj[y].pb(x);
	}
	//exit(0);
	dfs(a,0); dfs2(a,0);
	len = depth[b];
	// dbg(a,len);
	//FOR(i,1,n+1) dbg(i,up[i],down[i],depth[i]);
	//exit(0);
	bool three = 0;
	FOR(i,1,n+1) {
		vi v;
		trav(t,adj[i]) v.pb(getPath(i,t));
		sort(rall(v));
		//dbg(i,v);
		if (sz(v) >= 3 && v[2] >= len) three = 1;
	}
	if (!three || stuck()) { //  
		ps("NO");
		return;
	}
	ps("YES");
}

int main() {
	setIO();
	int T; re(T);
	F0R(i,T) solve();
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/