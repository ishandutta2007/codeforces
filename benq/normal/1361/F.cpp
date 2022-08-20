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
const int MX = 4e5+5; 
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
 * Description: A set (not multiset!) with support for finding the $n$'th
 * element, and finding the index of an element. Change \texttt{null\_type} for map.
 * Time: O(\log N)
 * Source: KACTL
 * Verification: many
 */

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 
#define ook order_of_key
#define fbo find_by_order

void treeExample() {
	Tree<int> t, t2; t.insert(8);
	auto it = t.insert(10).f; assert(it == t.lb(9));
	assert(t.ook(10) == 1 && t.ook(11) == 2 && *t.fbo(0) == 8);
	t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}

/**
int atMost(Tree<pi>& T, int r) { 
	return T.ook({r,MOD}); }
int getSum(Tree<pi>& T, int l, int r) { 
	return atMost(T,r)-atMost(T,l-1); }
*/

/**
 * Description: 1D range minimum query. Can also do queries 
 	* for any associative operation in $O(1)$ with D\&C
 * Source: KACTL
 * Verification: 
	* https://cses.fi/problemset/stats/1647/
	* http://wcipeg.com/problem/ioi1223
	* https://pastebin.com/ChpniVZL
 * Memory: O(N\log N)
 * Time: O(1)
 */

template<class T> struct RMQ { // floor(log_2(x))
	int level(int x) { return 31-__builtin_clz(x); } 
	vector<T> v; vector<vi> jmp;
	int comb(int a, int b) { // index of min
		return v[a]==v[b]?min(a,b):(v[a]<v[b]?a:b); } 
	void init(const vector<T>& _v) {
		v = _v; jmp = {vi(sz(v))}; iota(all(jmp[0]),0);
		for (int j = 1; 1<<j <= sz(v); ++j) {
			jmp.pb(vi(sz(v)-(1<<j)+1));
			F0R(i,sz(jmp[j])) jmp[j][i] = comb(jmp[j-1][i],
									jmp[j-1][i+(1<<(j-1))]);
		}
	}
	int index(int l, int r) { // get index of min element
		int d = level(r-l+1);
		return comb(jmp[d][l],jmp[d][r-(1<<d)+1]); }
	T query(int l, int r) { return v[index(l,r)]; }
};


RMQ<int> RM;
Tree<int> T[MX];
ll stor[MX];
int n,par[MX];
vi p;
vi child[MX];
ll ans;
int nex;

ll get(int x) {
	ll tot = (ll)sz(T[child[x][0]])*sz(T[child[x][1]]);
	ll res = min(stor[x],tot-stor[x]);
	//dbg("OOPS",x,res,stor[x],tot);
	return res;
}

int abv(Tree<int>& a, int b) { return sz(a)-a.ook(b); }

void del(int q) {
	for (int x = q;;) {
		int y = par[x]; if (y == -1) break;
		ans -= get(y); 
		//dbg("OOPS",y,stor[y],T[child[y][0]],T[child[y][1]]);
		if (x == child[y][0]) stor[y] -= T[child[y][1]].ook(p[q]);
		else stor[y] -= abv(T[child[y][0]],p[q]);
		T[x].erase(p[q]); 
		ans += get(y);
		x = y;
	}
}

void ad(int q) {
	for (int x = q;;) {
		int y = par[x]; if (y == -1) break;
		ans -= get(y); 
		if (x == child[y][0]) stor[y] += T[child[y][1]].ook(p[q]);
		else stor[y] += abv(T[child[y][0]],p[q]);
		T[x].insert(p[q]); 
		ans += get(y);
		x = y;
	}
}

pair<ll,vi> merge(vi a, vi b) {
	int i = 0; ll inv = 0;
	vi res;
	trav(x,a) {
		while (i < sz(b) && b[i] < x) res.pb(b[i++]);
		inv += i;
		res.pb(x);
	}
	while (i < sz(b)) res.pb(b[i++]);
	return {inv,res};
}

pair<int,vi> build(int l, int r) {
	int label;
	if (l == r) {
		label = l;
		T[label].insert(p[l]);
		return {l,{p[l]}};
	}
	label = ++nex;
	int m = RM.index(l,r-1);
	auto L = build(l,m), R = build(m+1,r);
	par[L.f] = label, par[R.f] = label; child[label] = {L.f,R.f};
	ll tmp; vi v;
	tie(tmp,v) = merge(L.s,R.s); T[label] = Tree<int>{all(v)};
	//dbg("???",label,child[label][0],child[label][1],T[child[label][0]],T[child[label][1]]);
	stor[label] = tmp; ans += get(label);
	return {label,v};
}

int main() {
	setIO(); re(n); p.rsz(n); re(p);
	vi w(n-1); re(w); RM.init(w);
	nex = n-1;
	auto t = build(0,n-1); par[t.f] = -1;
	dbg("OK",t);
	int q; re(q);
	F0R(i,q) {
		int x,y; re(x,y); x--,y--;
		del(x), del(y);
		swap(p[x],p[y]);
		ad(x), ad(y);
		ps(ans);
	}
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/