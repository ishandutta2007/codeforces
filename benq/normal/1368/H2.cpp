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

int n,m,q;
array<str,2> ver, hor;

struct func {
	int lo, L, R;
	int con = 0;
	func() { lo = L = -n; R = n; }
};

const int SZ = 1<<17;

/**
 * Description: 1D range update and query, $SZ=2^p$.
 * Source: USACO Counting Haybales
 * Verification: SPOJ Horrible
 */

array<int,2> operator+(array<int,2> a, array<int,2> b) {
	array<int,2> c; F0R(i,2) c[i] = a[i]+b[i];
	return c;
}

struct Seg { 
	str s;
	array<int,2> sum[2*SZ];
	bool lazy[2*SZ]; 
	void init(str _s) {
		s = _s;
		F0R(i,2*SZ) lazy[i] = 0, sum[i] = {0,0};
		F0R(i,sz(s)) {
			if (s[i] == 'R') sum[SZ+i][0] ++;
			else sum[SZ+i][1] ++;
		}
		build();
	}
	void push(int ind, int L, int R) { /// modify values for current node
		if (!lazy[ind]) return;
		if (L != R) F0R(i,2) lazy[2*ind+i] ^= 1; /// prop to children
		swap(sum[ind][0],sum[ind][1]); lazy[ind] = 0; 
	} // recalc values for current node
	void pull(int ind) { sum[ind] = sum[2*ind]+sum[2*ind+1]; }
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo,int hi,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = 1; push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,2*ind,L,M); 
		upd(lo,hi,2*ind+1,M+1,R); pull(ind);
	}
	pi cum() { // reds, blues
		assert(sum[1][0]+sum[1][1] == sz(s));
		return {sum[1][0],sum[1][1]};
	}
};


int SGN(int x) { return x == 0 ? 1 : -1; }
int sgn(char c) { return c == 'R' ? -1 : 1; }

Seg side[2];
func plu, minu;
pi eval(func F, pi p) { // initial term, dif
	p.f += F.con+min(p.s,F.L)+n;
	p.s = F.lo+max(0,min(p.s,F.R)-F.L);
	//dbg("AH",p.s);
	assert(-n <= p.s && p.s <= n);
	return p;
}
func ad(func a, func b) {
	pi x = eval(a,{0,-n});
	func c; c.con = eval(b,x).f; c.lo = eval(b,x).s;
	if (a.lo <= b.L) {
		if (a.lo+a.R-a.L <= b.L) {
			//dbg("C1");
			c.L = c.R = a.R;
		} else if (a.lo+a.R-a.L <= b.R) {
			//dbg("C2");
			c.L = a.L+b.L-a.lo; // < a.R
			c.R = a.R;
			// when it hits b.L
		} else {
			//dbg("C3");
			c.L = a.L+b.L-a.lo; // < a.R
			c.R = a.L+b.R-a.lo;
		}
	} else if (x.s <= b.R) {
		c.L = a.L;
		if (a.lo+a.R-a.L <= b.R) {
			//dbg("C4");
			c.R = a.R;
		} else {
			//dbg("C5");
			c.R = a.L+b.R-a.lo;
		}
	} else {
		//dbg("C6");
		c.L = c.R = a.L;
	}
	assert(c.L <= c.R);
	assert(eval(c,{0,-n}) == eval(b,eval(a,{0,-n})));
	assert(eval(c,{0,n}) == eval(b,eval(a,{0,n})));
	// FOR(i,-n,n+1) if (eval(c,{0,i}) != eval(b,eval(a,{0,i}))) {
	// 	dbg("HUH",i,eval(c,{0,i}),eval(b,eval(a,{0,i})));
	// 	exit(0);
	// }
	return c;
}
bool lazy[2*SZ][2];
func cur[2*SZ][2][2];
void pull(int ind) {
	F0R(i,2) F0R(j,2) 
		cur[ind][i][j] = ad(cur[2*ind][i][j],cur[2*ind+1][i][j]);
}
void push(int ind, int L, int R) {
	if (lazy[ind][0]) {
		F0R(j,2) swap(cur[ind][0][j],cur[ind][1][j]);
		lazy[ind][0] = 0;
		if (L != R) F0R(j,2) lazy[2*ind+j][0] ^= 1; 
	}
	if (lazy[ind][1]) {
		F0R(j,2) swap(cur[ind][j][0],cur[ind][j][1]);
		lazy[ind][1] = 0;
		if (L != R) F0R(j,2) lazy[2*ind+j][1] ^= 1; 
	}
}
void build(int ind, int L, int R) {
	F0R(i,2) lazy[ind][i] = 0;
	if (L == R) {
		F0R(i,2) F0R(j,2) cur[ind][i][j] = func();
		if (L < m) {
			//dbg("OK",L);
			F0R(i,2) F0R(j,2) {
				int sum = SGN(i)*sgn(hor[0][L])+SGN(j)*sgn(hor[1][L]);
				//dbg("HUH",i,j,sum);
				if (sum == 2) cur[ind][i][j] = ad(plu,plu);
				else if (sum == -2) cur[ind][i][j] = ad(minu,minu);
				else cur[ind][i][j].con ++;
			}
		}
		return;
	}
	int M = (L+R)/2;
	build(2*ind,L,M); build(2*ind+1,M+1,R);
	pull(ind);
}
void init() {
	F0R(i,2) side[i].init(ver[i]);
	plu.lo = 1-n; plu.L = -n; plu.R = n-1;
	minu.lo = -n; minu.L = -n+1; minu.R = n;
	FOR(i,-n,n+1) dbg(i,eval(plu,pi{0,i}),eval(minu,pi{0,i}));
	FOR(i,-n,n+1) assert(eval(func(),{0,i}) == mp(0,i));
	dbg("START BUILD");
	build(1,0,SZ-1);
	dbg("END BUILD");
}
void updFlip(int lo, int hi, int x, int ind = 1, int L = 0, int R = SZ-1) {
	push(ind,L,R); if (R < lo || hi < L) return;
	if (lo <= L && R <= hi) {
		lazy[ind][x] = 1; push(ind,L,R);
		return;
	}
	int M = (L+R)/2;
	updFlip(lo,hi,x,2*ind,L,M); updFlip(lo,hi,x,2*ind+1,M+1,R);
	pull(ind);
}

int getAns() {
	pi p = side[0].cum(); dbg("START",p);
	p.s -= p.f; dbg("AA",p);
	p = eval(cur[1][0][0],p); dbg("BB",p);
	p.s += p.f; dbg("END",p);
	pi P = side[1].cum(); dbg("HA",P);
	return min(p.f+P.f,p.s+P.s);
}

vi res;
vector<pair<char,pi>> query; // OK

void dump() {
	F0R(i,q+1) ps(res[i]);
	exit(0);
}

void go() {
	init();
	int cnt = 0;
	ckmin(res[cnt++],getAns());
	trav(t,query) {
		if (t.f == 'L') side[0].upd(t.s.f,t.s.s);
		if (t.f == 'R') side[1].upd(t.s.f,t.s.s);
		if (t.f == 'U') updFlip(t.s.f,t.s.s,0);
		if (t.f == 'D') updFlip(t.s.f,t.s.s,1);
		ckmin(res[cnt++],getAns());
	}
}

int main() {
	setIO(); re(n,m,q);
	re(ver,hor);
	res = vi(q+1,MOD);
	F0R(i,q) {
		char s; int l,r; re(s,l,r);
		query.pb({s,{l-1,r-1}});
	}
	go();
	swap(ver,hor); swap(n,m);
	trav(t,query) {
		if (t.f == 'L') t.f = 'U';
		else if (t.f == 'U') t.f = 'L';
		else if (t.f == 'R') t.f = 'D';
		else if (t.f == 'D') t.f = 'R';
	}
	go();
	dump();
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/