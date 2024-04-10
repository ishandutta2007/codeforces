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
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(str s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

/**
 * Description: range sum queries and point updates for $D$ dimensions
 * Source: https://codeforces.com/blog/entry/64914
 * Verification: SPOJ matsum
 * Usage: \texttt{BIT<int,10,10>} gives 2D BIT
 * Time: O((\log N)^D)
 */

template <class T, int ...Ns> struct BIT {
	T val = 0; void upd(T v) { val += v; }
	T query() { return val; }
};
template <class T, int N, int... Ns> struct BIT<T, N, Ns...> {
	BIT<T,Ns...> bit[N+1];
	template<typename... Args> void upd(int pos, Args... args) { assert(pos > 0);
		for (; pos<=N; pos+=pos&-pos) bit[pos].upd(args...); }
	template<typename... Args> T sum(int r, Args... args) {
		T res=0; for (;r;r-=r&-r) res += bit[r].query(args...); 
		return res; }
	template<typename... Args> T query(int l, int r, Args... 
		args) { return sum(r,args...)-sum(l-1,args...); }
}; 

BIT<int,2000005> B;

/**
 * Description: Used infrequently. Constructs minimal deterministic 
 	* finite automaton (DFA) that recognizes all suffixes of a string.
 	* \texttt{len} corresponds to the maximum length of a string in
 	* the equivalence class, \texttt{pos} corresponds to
 	* the first ending position of such a string, \texttt{lnk}
 	* corresponds to the longest suffix that is in a different class.
 	* Suffix links correspond to suffix tree of the reversed string!
 * Time: O(N\log \sum)
 * Source: *
 * Verification: *
 */

vi cnt;
vector<vi> tmp;
vpi bound;

struct SuffixAutomaton {
	int N = 1; vi lnk{-1}, len{0}, pos{-1}; // max length of state, suffix link, last pos of first occurrence of state
	vector<map<char,int>> nex{1}; vector<bool> isClone{0}; // transitions, cloned -> not terminal state
	vector<vi> iLnk; // inverse links
	vi cnt;
	int add(int p, char c) { // ~p is nonzero if p != -1
		auto getNex = [&]() {
			if (p == -1) return 0;
			int q = nex[p][c]; if (len[p]+1 == len[q]) return q;
			int clone = N++; lnk.pb(lnk[q]); lnk[q] = clone;
			len.pb(len[p]+1); nex.pb(nex[q]), pos.pb(pos[q]), isClone.pb(1);
			for (; ~p && nex[p][c] == q; p = lnk[p]) nex[p][c] = clone;
			return clone;
		};
		if (nex[p].count(c)) return getNex(); // <- need if adding > 1 string
		int cur = N++; // make new state
		lnk.eb(), len.pb(len[p]+1), nex.eb(), pos.pb(pos[p]+1), isClone.pb(0);
		for (; ~p && !nex[p].count(c); p = lnk[p]) nex[p][c] = cur;
		int x = getNex(); lnk[cur] = x;
		return cur;
	}
	void init(str s) { 
		int p = 0; 
		tmp.eb();
		trav(x,s) {
			p = add(p,x);
			tmp.bk.pb(p);
		}
	} // add string to automaton
	int CNT = 0;
	void dfs(int x) {
		bound[x].f = ++CNT;
		trav(t,iLnk[x]) dfs(t);
		bound[x].s = CNT;
	}
	void genIlnk() { iLnk.rsz(N); FOR(v,1,N) iLnk[lnk[v]].pb(v); 
		bound.rsz(N);
		dfs(0);
		dbg("OK");
	} // inverse links
	// APPLICATIONS
	void getAllOccur(vi& oc, int v) {
		if (!isClone[v]) oc.pb(pos[v]); // terminal position
		trav(u,iLnk[v]) getAllOccur(oc,u); }
	vi allOccur(str s) { // get all occurrences of s in automaton
		int cur = 0;
		trav(x,s) {
			if (!nex[cur].count(x)) return {};
			cur = nex[cur][x]; }
		vi oc; getAllOccur(oc,cur); trav(t,oc) t += 1-sz(s); // convert end pos -> start pos
		sort(all(oc)); return oc;
	}
	vl distinct;
	ll getDistinct(int x) { // # of distinct strings starting at state x
		if (distinct[x]) return distinct[x];
		distinct[x] = 1; trav(y,nex[x]) distinct[x] += getDistinct(y.s);
		return distinct[x]; }
	ll numDistinct() { // # distinct substrings including empty
		distinct.rsz(N); return getDistinct(0); }
	ll numDistinct2() { // assert(numDistinct() == numDistinct2());
		ll ans = 1; FOR(i,1,N) ans += len[i]-len[lnk[i]];
		return ans; } 
};

SuffixAutomaton S;
vi sa; str s;
int n,q;
vector<array<int,3>> res[MX];
vi ans;

// void dfs(int x) {
// 	if (!S.isClone[x]) sa.pb(sz(s)-1-S.pos[x]);
// 	vector<pair<char,int>> chr;
// 	trav(t,S.iLnk[x]) chr.pb({s[S.pos[t]-S.len[x]],t});
// 	sort(all(chr)); trav(t,chr) dfs(t.s);
// }

void ad(int x) {
	B.upd(bound[x].f,1);
}

int query(int x) {
	return B.query(bound[x].f,bound[x].s);
}

int main() {
	re(n,q);
	vs v(n); re(v);
	trav(t,v) S.init(t);
	S.genIlnk();
	ans.rsz(q);
	F0R(i,q) {
		int l,r,k; re(l,r,k);
		res[l-1].pb({tmp[k-1].bk,-1,i});
		res[r].pb({tmp[k-1].bk,1,i});
	}
	FOR(i,1,n+1) {
		dbg("HA",tmp[i-1]);
		trav(u,tmp[i-1]) ad(u);
		trav(t,res[i]) ans[t[2]] += t[1]*query(t[0]);
	}
	trav(t,ans) ps(t);
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/