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
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;

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
const int MX = 1<<18;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

// helper funcs
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

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
	t.erase(it); } // element that doesn't exist from (multi)set

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
tcT> void rv(int& n, vector<T>& x) { re(n); x.rsz(n); trav(a,x) re(a); }

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

int N;

/**
 * Description: 1D range increment and sum query.
 * Source: USACO Counting Haybales
 * Verification: SPOJ Horrible
 */

template<class T, int SZ> struct LazySeg { 
	static_assert(pct(SZ) == 1); // SZ must be power of 2
	const T ID = {MOD,-MOD}; 
	T comb(T a, T b) { 
		return {min(a[0],b[0]),max(a[1],b[1])}; 
	}
	T seg[2*SZ];
	int lazy[2*SZ]; 
	LazySeg() { F0R(i,2*SZ) seg[i] = {0,0}, lazy[i] = 0; }
	void push(int ind, int L, int R) { /// modify values for current node
		F0R(_,2) seg[ind][_] += lazy[ind]; // dependent on operation
		if (L != R) F0R(i,2) lazy[2*ind+i] += lazy[ind]; /// prop to children
		lazy[ind] = 0; 
	} // recalc values for current node
	bool contains(T a, int b) { return a[0] <= b && b <= a[1]; }
	void pull(int ind) { seg[ind] = comb(seg[2*ind],seg[2*ind+1]); }
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo,int hi,int inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	int query(int pos, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R);
		if (L == R) return seg[ind][0];
		int M = (L+R)/2; 
		if (pos <= M) return query(pos,2*ind,L,M);
		return query(pos,2*ind+1,M+1,R);
	}
	int getFst(int val, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R); 
		if (!contains(seg[ind],val)) return MOD;
		if (L == R) return L;
		int M = (L+R)/2; 
		int a = getFst(val,2*ind,L,M);
		if (a != MOD) return a;
		return getFst(val,2*ind+1,M+1,R);
	}
	int getLst(int val, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R); 
		if (!contains(seg[ind],val)) return MOD;
		if (L == R) return L;
		int M = (L+R)/2; 
		int a = getLst(val,2*ind+1,M+1,R);
		if (a != MOD) return a;
		return getLst(val,2*ind,L,M);
	}
};

LazySeg<AR<int,2>,MX> LS;

vi A;
map<int,int> m;
int ans;

void suf(int a, int b) {
	LS.upd(a+1,MX-1,b);
}

// void tri(int a, int b) {
// 	assert(a != b);
// 	vi fst(2*N+1,MOD);
// 	// dbg(a,b);
// 	int cnt = N;
// 	F0R(i,N+1) {
// 		if (fst[cnt] != MOD) {
// 			ckmax(ans,i-fst[cnt]);
// 		} else {
// 			fst[cnt] = i;
// 		}
// 		if (i < N) {
// 			if (A[i] == a) cnt ++;
// 			if (A[i] == b) cnt --;
// 		}
// 	}
// 	// int cnt = N;
// 	// trav(t,A) {
// 	// 	if (t == A) cnt ++;
// 	// }
// }

vi oc[MX];
int maxAft[MX];

void tri(int x) {
	// dbg("TRI",x);
	vi todo;
	trav(t,oc[x]) {
		suf(t,-1);
		// todo.pb(maxAft[t]);
	}
	vi val;
	trav(t,oc[x]) {
		val.pb(LS.query(t));
		val.pb(LS.query(t+1));
	}
	// dbg("OOPS",val);
	// dbg("HA",sz(oc[x]),LS.query(N,N),todo);
	trav(t,val) {
		ckmax(ans,min(N,LS.getLst(t))-LS.getFst(t));
	}
	trav(t,oc[x]) {
		suf(t,1);
	}
}

int main() {
	setIO(); re(N); A.rsz(N); re(A);
	F0R(i,N) oc[A[i]].pb(i);
	trav(t,A) m[t] ++;
	// suf(N,1);
	// FOR()
	// LS.upd(N+1,(1<<18)-1,1000000);
	// dbg("??",LS.query(0,N));
	pi BIG = {0,0};
	trav(t,m) ckmax(BIG,mp(t.s,t.f));
	int big = BIG.s;
	F0R(i,N) if (A[i] == big) suf(i,1);
	maxAft[N] = N;
	R0F(i,N) {
		if (A[i] == big) maxAft[i] = i;
		else maxAft[i] = maxAft[i+1];
	}
	trav(t,m) if (t.f != big) {
		tri(t.f);
	}
	ps(ans);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/