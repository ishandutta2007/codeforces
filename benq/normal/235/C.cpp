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
 * Description: Used infrequently. Constructs minimal deterministic 
 	* finite automaton (DFA) that recognizes all suffixes of a string.
 	* \texttt{len} corresponds to the maximum length of a string in
 	* the equivalence class, \texttt{firstPos} corresponds to
 	* the first ending position of such a string, \texttt{len}
 	* corresponds to the longest suffix that is in a different class.
 * Time: O(N\log \sum)
 * Source: https://cp-algorithms.com/string/suffix-automaton.html
 * Verification: 
	* https://www.spoj.com/problems/SUBLEX/
	* https://open.kattis.com/problems/stringmultimatching
 */
 
struct SuffixAutomaton {
	struct state {
		int len = 0, firstPos = -1; bool isClone = 0;
		int link = -1; vi invLink; 
		map<char, int> next;
	}; vector<state> st;
	int last = 0;
	void extend(char c) {
		int cur = sz(st); st.eb();
		st[cur].len=st[last].len+1, st[cur].firstPos=st[cur].len-1;
		int p = last;
		while (p != -1 && !st[p].next.count(c)) 
			st[p].next[c] = cur, p = st[p].link;
		if (p == -1) st[cur].link = 0;
		else {
			int q = st[p].next[c];
			if (st[p].len+1 == st[q].len) st[cur].link = q;
			else { // new equivalence class
				int clone = sz(st); st.pb(st[q]);
				st[clone].len = st[p].len+1, st[clone].isClone = 1;
				while (p != -1 && st[p].next[c] == q) 
					st[p].next[c] = clone, p = st[p].link;
				st[q].link = st[cur].link = clone;
			} // first pos of longest[link[link[last]]] increases
		} // whenever transition is redirected, amortized linear
		last = cur; 
	}
	void init(str s) { 
		st.eb(); trav(x,s) extend(x); 
		FOR(v,1,sz(st)) st[st[v].link].invLink.pb(v);
	}
	// APPLICATIONS
	vi oc;
	void getAllOccur(int v) {
		if (!st[v].isClone) oc[v] ++;
		trav(u,st[v].invLink) {
			getAllOccur(u);
			oc[v] += oc[u];
		}
	}
	vl distinct;
	ll getDistinct(int x) {
		if (distinct[x]) return distinct[x];
		distinct[x] = 1; 
		trav(y,st[x].next) distinct[x] += getDistinct(y.s);
		return distinct[x];
	}
	ll numDistinct() { // # distinct substrings including empty
		distinct.rsz(sz(st)); return getDistinct(0); }
	ll numDistinct2() { // another way to do above
		ll ans = 1;
		FOR(i,1,sz(st)) ans += st[i].len-st[st[i].link].len;
		return ans; }
};

SuffixAutomaton SA;
str s;
int n;

int main() {
	setIO(); re(s); 
	SA.init(s);
	SA.oc.rsz(sz(SA.st));
	SA.getAllOccur(0);
	//dbg(SA.oc[0]);
	vi lst(sz(SA.st));
	re(n);
	FOR(i,1,n+1) {
		str s; re(s); int len = sz(s);
		s += s;
		int r = -1, cur = 0;
		ll ans = 0;
		F0R(l,len) {
			while (r < l+len-1 && SA.st[cur].next.count(s[r+1])) {
				r ++;
				cur = SA.st[cur].next[s[r]];
			}
			if (r == l+len-1 && lst[cur] != i) {
				lst[cur] = i;
				ans += SA.oc[cur];
			}
			if (l > r) r ++;
			else {
				if (SA.st[SA.st[cur].link].len == r-l) cur = SA.st[cur].link;
			}
		}
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