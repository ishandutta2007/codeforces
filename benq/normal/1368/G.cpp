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
int pct(int x) { return __builtin_popcount(x); } 
int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 
int fstTrue(function<bool(int)> f, int lo, int hi) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		int mid = (lo+hi)/2; 
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}

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

/**
 * Description: Calculates min and # of mins
 * Source: Own
 * Verification: FHC19 Final D
 */

typedef pi T;
T operator+(const T& l, const T& r) {
	if (l.f != r.f) return min(l,r);
	return {l.f,l.s+r.s};
}

template<int SZ> struct LazySeg { 
	T sum[2*SZ];
	int lazy[2*SZ];
	LazySeg() {
		memset(sum,0,sizeof sum);
		memset(lazy,0,sizeof lazy);
	}
	void push(int ind, int L, int R) { // modify values for current node
		sum[ind].f += lazy[ind]; 
		if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind]; 
		lazy[ind] = 0; // pushed lazy to children
	}
	void pull(int ind) { // recalc values for current node
		sum[ind] = sum[2*ind]+sum[2*ind+1]; }
	void build() { 
		//FOR(i,SZ,2*SZ) sum[i] = {0,1};
		ROF(i,1,SZ) pull(i); 
	}
	void upd(int lo, int hi, int inc, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) {
			lazy[ind] = inc; 
			push(ind,L,R); return;
		}
		int M = (L+R)/2;
		upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
		pull(ind);
	}
	T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (lo > R || L > hi) return {MOD,0};
		if (lo <= L && R <= hi) return sum[ind];
		int M = (L+R)/2;
		return qsum(lo,hi,2*ind,L,M)+qsum(lo,hi,2*ind+1,M+1,R);
	}
};

ll area(vector<pair<pi,pi>> v) { // area of union of rectangles
	trav(t,v) t.f.s ++, t.s.s ++;
	//dbg("HA",v);
	const int SZ = 1<<20;
    LazySeg<SZ> L = LazySeg<SZ>();
    vi y; trav(t,v) y.pb(t.s.f), y.pb(t.s.s);
    sort(all(y)); y.erase(unique(all(y)),y.end());
    F0R(i,sz(y)-1) L.sum[(SZ)+i].s = y[i+1]-y[i];
    L.build();
    dbg("HUH",L.sum[1]);
    vector<array<int,4>> ev; // sweep line
    trav(t,v) {
        t.s.f = lb(all(y),t.s.f)-begin(y);
        t.s.s = lb(all(y),t.s.s)-begin(y)-1;
        ev.pb({t.f.f,1,t.s.f,t.s.s});
        ev.pb({t.f.s,-1,t.s.f,t.s.s});
    }
    sort(all(ev));
    ll ans = 0;
    F0R(i,sz(ev)-1) {
        const auto& t = ev[i];
        L.upd(t[2],t[3],t[1]);
        int len = y.back()-y.front()-L.sum[1].s; // L.mn[0].f should equal 0
        ans += (ll)(ev[i+1][0]-t[0])*len;
    }
    return ans;
}

int n,m,nex[MX],comp[MX];
pi sub[MX];
vi child[MX];
vs g;

bool valid(pi a) { return 0 <= a.f && a.f < n && 0 <= a.s && a.s < m; }

int hsh(pi p) { return m*p.f+p.s; }

void ae(pi a, pi b) {
	if (!valid(a) || !valid(b)) return;
	int A = hsh(a), B = hsh(b); 
	assert(nex[A] == -1);
	nex[A] = B; child[B].pb(A);
}

int ord = 0;

void makeSub(int x) {
	dbg("OKMAKESUB",x);
	sub[x].f = ord++;
	trav(t,child[x]) if (sub[t] == mp(-1,-1)) {
		comp[t] = comp[x];
		makeSub(t);
	}
	sub[x].s = ord-1;
}

int cnt;
void makeComp(int x) {
	int ori = x;
	dbg("MAKECOMP",x);
	++cnt;
	while (!comp[x]) {
		dbg("SETCOMP",x);
		comp[x] = cnt;
		if (nex[x] == -1) break;
		x = nex[x];
	}
	dbg("MAKESUB",x);
	makeSub(x);
	if (nex[x] != -1) {
		dbg("INCYC");
		int y = nex[x];
		while (y != x) {
			dbg("OOPS",y); if (y == -1) exit(0);
			sub[y] = sub[x];
			y = nex[y];
		}
		dbg("DONECYC");
	}
}

vector<pair<pi,pi>> rect;

void ad(pi a, pi b) {
	int A = hsh(a), B = hsh(b);
	//dbg("HUH",a,b,A,B,sub[A],sub[B]);
	rect.pb({sub[A],sub[B]});
	rect.pb({sub[B],sub[A]});
}

int main() {
	setIO(); re(n,m);
	F0R(i,n*m) nex[i] = -1, sub[i] = {-1,-1};
	g.rsz(n); re(g);
	F0R(i,n) F0R(j,m) {
		if (g[i][j] == 'U') {
			ae({i,j},{i+2,j}); // each vert has <= 1 outdeg
			ae({i+1,j},{i-1,j});
		}
		if (g[i][j] == 'L') {
			ae({i,j},{i,j+2}); // each vert has <= 1 outdeg
			ae({i,j+1},{i,j-1});
		}
	}
	F0R(i,n*m) if (!comp[i]) makeComp(i);
	F0R(i,n*m) dbg(i,sub[i]);
	F0R(i,n) F0R(j,m) {
		if (g[i][j] == 'U') ad({i,j},{i+1,j});
		if (g[i][j] == 'L') ad({i,j},{i,j+1});
	}
	ps(area(rect)/2);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/