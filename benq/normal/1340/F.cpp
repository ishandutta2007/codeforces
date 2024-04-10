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
const int SZ = 1<<17;
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bit(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
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
 * Description: modular arithmetic operations 
 * Source: 
	* KACTL
	* https://codeforces.com/blog/entry/63903
	* https://codeforces.com/contest/1261/submission/65632855 (tourist)
	* https://codeforces.com/contest/1264/submission/66344993 (ksun)
 * Verification: 
	* https://open.kattis.com/problems/modulararithmetic
 */

struct mi {
	typedef decay<decltype(MOD)>::type T; 
 	/// don't silently convert to T
	T v; explicit operator T() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.v < b.v; }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }
	friend str ts(mi a) { return ts(a.v); }
   
	mi& operator+=(const mi& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		v = (ll)v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

vector<vmi> scmb; // small combinations
void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	FOR(i,1,SZ) F0R(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}

/**
 * Description: Polynomial hash for substrings with two bases.
 * Source:
	* KACTL
	* https://codeforces.com/contest/1207/submission/59309672
 * Verification: 
	* USACO Dec 17 Plat 1
	* CF Check Transcription
 */

typedef array<int,2> T; // bases not too close to ends 
uniform_int_distribution<int> BDIST(0.1*MOD,0.9*MOD);
const T base = {BDIST(rng),BDIST(rng)};
const T ibase = {(int)inv(mi(base[0])),(int)inv(mi(base[1]))};
T operator+(T l, T r) { 
	F0R(i,2) if ((l[i] += r[i]) >= MOD) l[i] -= MOD;
	return l; }
T operator-(T l, T r) { 
	F0R(i,2) if ((l[i] -= r[i]) < 0) l[i] += MOD;
	return l; }
T operator*(T l, T r) { 
	F0R(i,2) l[i] = (ll)l[i]*r[i]%MOD;
	return l; }
vector<T> pows = {{1,1}}, ipows = {{1,1}};

struct Hash { 
	int len = 0; T res = T(); int type = -1; 
	Hash() {}
	Hash(int _type) { type = _type; }
	Hash(int _len, T _res, int _type) {
		len = _len; res = _res; type = _type;
		assert(len >= 0);
	}
};

str ts(Hash H) {
	return ts(vi{H.len,H.type,H.res[0],H.res[1]});
}

Hash operator+(Hash a, Hash b) {
	assert(a.type != -1 && b.type != -1 && a.type == b.type);
	T sum = (a.type == 0 ? a.res+pows[a.len]*b.res : b.res+pows[b.len]*a.res);
	return {a.len+b.len,sum,a.type};
}

bool operator==(Hash a, Hash b) {
	assert(a.type != -1 && b.type != -1 && a.type != b.type && a.len == b.len);
	return a.res == b.res;
}
bool operator!=(Hash a, Hash b) {
	if (!(a.type != -1 && b.type != -1 && a.type != b.type && a.len == b.len)) {
		dbg("!=",a.type,b.type,a.len,b.len);
		exit(0);
	}
	return a.res != b.res;
}

int n,k,q;
vi s;
Hash stor[2*SZ][2], tmp[2*SZ];
bool bad[2*SZ];

Hash queryLef(int ind, int l) {
	if (!l) return Hash(0);
	assert(l >= 0 && l <= stor[ind][0].len);
	if (l == stor[ind][0].len) return stor[ind][0];
	int len = max(stor[2*ind][0].len-stor[2*ind+1][1].len,0);
	if (l <= len) return queryLef(2*ind,l);
	return (len > 0 ? tmp[ind] : Hash(0))+queryLef(2*ind+1,l-len);
}

Hash queryRig(int ind, int l) {
	assert(l >= 0 && l <= stor[ind][1].len);
	if (!l) return Hash(1);
	if (l == stor[ind][1].len) return stor[ind][1];
	int len = max(stor[2*ind+1][1].len-stor[2*ind][0].len,0);
	if (l <= len) return queryRig(2*ind+1,l);
	return queryRig(2*ind,l-len)+(len > 0 ? tmp[ind] : Hash(1));
}

Hash lefRange(int ind, int l, int r) {
	assert(l <= r);
	auto a = queryLef(ind,l), b = queryLef(ind,r);
	if (a.len != l) {
		dbg("A",ind,l,a.len);
		exit(0);
	}
	assert(a.len == l && b.len == r);
	return {b.len-a.len,(b.res-a.res)*ipows[l],0};
}

Hash rigRange(int ind, int l, int r) {
	assert(l <= r);
	int len = stor[ind][1].len;
	l = len-l, r = len-r; assert(l >= 0 && r >= 0);
	auto a = queryRig(ind,r), b = queryRig(ind,l);
	assert(a.len == r && b.len == l);
	return {b.len-a.len,(b.res-a.res)*ipows[r],1};
}

void pull(int ind) {
	if (bad[2*ind] || bad[2*ind+1]) { bad[ind] = 1; return; }
	bad[ind] = 0; stor[ind][1] = stor[2*ind][1]; stor[ind][0] = stor[2*ind+1][0];
	int a = stor[2*ind][0].len, b = stor[2*ind+1][1].len;
	/*if (ind == 16384) {
		dbg("HUH",ind,stor[2*ind][1].len,stor[2*ind][0].len,stor[2*ind+1][1].len,stor[2*ind+1][0].len);
		dbg(stor[2*ind][0].res,stor[2*ind+1][1].res);
		exit(0);
	}*/
	if (a > b) {
		if (lefRange(2*ind,a-b,a) != rigRange(2*ind+1,0,b)) { bad[ind] = 1; return; }
		tmp[ind] = lefRange(2*ind,0,a-b); 
		stor[ind][0] = tmp[ind]+stor[ind][0];
	} else {
		if (lefRange(2*ind,0,a) != rigRange(2*ind+1,0,a)) { bad[ind] = 1; return; }
		tmp[ind] = rigRange(2*ind+1,a,b);
		stor[ind][1] = stor[ind][1]+tmp[ind];
	}
	/*if (ind == 16384*2) {
		dbg("WUT",stor[ind][0],stor[ind][1]);
		dbg(stor[2*ind][0],stor[2*ind+1][0]);
		dbg(tmp[ind],pows[2]);
		exit(0);
	}*/
}

void make(int ind, int x) {
	s[ind] = x; ind += SZ;
	if (x > 0) stor[ind][0] = {1,{x,x},0}, stor[ind][1] = {0,{0,0},1};
	else stor[ind][0] = {0,{0,0},0}, stor[ind][1] = {1,{-x,-x},1};
}

int main() {
	setIO(); re(n,k); s.rsz(n); re(s,q);
	while (sz(pows) <= n) pows.pb(base*pows.bk), ipows.pb(ibase*ipows.bk);
	F0R(i,2*SZ) F0R(j,2) stor[i][j] = Hash(j);
	F0R(i,n) make(i,s[i]);
	ROF(i,1,SZ) pull(i);
	F0R(i,q) {
		int t,l,r; re(t,l,r);
		if (t == 1) {
			l --; make(l,r); l += SZ;
			for (l /= 2; l; l /= 2) pull(l);
		} else {
			vi L, R; bool BAD = 0;
			for (l += SZ-1, r += SZ; l < r;l /= 2, r /= 2) {
				if (l&1) {
					dbg(l,bad[l]);
					if (bad[l]) { BAD = 1; break; }
					L.pb(l++);
				}
				if (r&1) {
					R.pb(--r);
					dbg(r,bad[r]);
					if (bad[r]) { BAD = 1; break; }
				}
			}
			reverse(all(R)); L.insert(end(L),all(R));
			vpi cur;
			if (!BAD) trav(ind,L) {
				dbg("OH",ind,stor[ind][1].len,stor[ind][0].len);
				int len = stor[ind][1].len;
				while (len) {
					if (!sz(cur)) { BAD = 1; break; }
					int sub = min(cur.bk.s,len);
					if (lefRange(cur.bk.f,cur.bk.s-sub,cur.bk.s) != rigRange(ind,stor[ind][1].len-len,stor[ind][1].len-len+sub)) {
						BAD = 1;
						break;
					}
					cur.bk.s -= sub; len -= sub;
					if (!cur.bk.s) cur.pop_back();
				}
				len = stor[ind][0].len;
				if (len) cur.pb({ind,len});
			}
			BAD |= sz(cur);
			if (BAD) ps("No");
			else ps("Yes");
		}
	}
	
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/