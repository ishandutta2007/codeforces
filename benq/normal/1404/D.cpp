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
const int MX = 5e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
 
// helper funcs
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
ll half(ll x) { return fdiv(x,2); }
 
tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }
 
#define tcTU tcT, class U
tcTU> T fstTrue(T lo, T hi, U f) { 
	// note: if (lo+hi)/2 is used instead of half(lo+hi) 
	// then this will loop infinitely when lo=hi
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = half(lo+hi);
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = half(lo+hi+1);
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
 
// constexpr int n = 6;
 
// // 1,2 -> second wins
// // 1,2,3,4 -> first wins, try 1,3 and 2,4
 
// bitset<2*n> shift(bitset<2*n> a, int b) {
// 	bitset<2*n> rec;
// 	F0R(i,2*n) if (a[i]) rec[(i+b)%(2*n)] = 1;
// 	return rec;
// }
 
// vpi st;
 
// void go(bitset<2*n> use, bitset<2*n> posi) {
// 	int i = 0; while (i < 2*n && use[i]) i ++;
// 	// dbg("GOING",i);
// 	if (i == 2*n) {
// 		if (!posi[0]) {
// 			ps("First",st);
// 		}
// 		return;
// 	}
// 	FOR(j,i+1,2*n) if (!use[j]) {
// 		st.pb({i,j});
// 		auto USE = use; USE[i] = USE[j] = 1;
// 		go(USE,shift(posi,i)|shift(posi,j));
// 		st.pop_back();
// 	}
// }
 
// using B = bitset<2*n>;
 
int n; 
vi todo[MX];
bool mark[MX];
 
void fin() {
	dbg("FIN");
	FOR(j,1,n+1) {
		assert(sz(todo[j]) == 2);
		if (mark[j]) pr(todo[j][1]);
		else pr(todo[j][0]);
		pr(' ');
	}
	ps();
	exit(0);
}
 
V<AR<int,3>> adj[MX];
bool vis[MX];

vi path;
void dfs(int x) {
	if (vis[x]) return;
	vis[x] = 1; path.pb(x);
	trav(t,adj[x]) dfs(t[0]);
}

AR<int,2> nex(int a, int b, int c = -1) {
	trav(t,adj[a]) if (t[0] == b && t[2] != c) return {t[1],t[2]};
	assert(0);
}

int main() {
	setIO();
	re(n);
	if (n%2 == 0) {
		ps("First");
		FOR(i,1,2*n+1) {
			int res = i;
			if (i > n) res -= n;
			pr(res,' ');
		}
		ps();
		exit(0);
	}
	ps("Second");
	FOR(i,1,2*n+1) {
		int p; re(p);
		// dbg("?????",p);
		todo[p].pb(i);
	}
	FOR(i,1,n+1) {
		int a = todo[i][0], b = todo[i][1];
		adj[a%n].pb({b%n,b,i});
		adj[b%n].pb({a%n,a,i});
	}
	F0R(i,n) assert(sz(adj[i]) == 2);
	vb use(2*n+1);
	F0R(i,n) if (!vis[i]) {
		path.clear();
		dfs(i);
		// dbg("???",path);
		// dbg("HA",path);
		dbg("OOPS",path);
		int lst = -1;
		F0R(j,sz(path)) {
			AR<int,2> a = nex(path[j],path[(j+1)%sz(path)],lst);
			// dbg("WUT",);
			// // dbg(path[j],path[(j+1)%sz(path)],nex(path[j],path[(j+1)%sz(path)]));
			use[a[0]] = 1;
			lst = a[1];
		}
	}
	FOR(i,1,2*n+1) if (use[i]) dbg(i);
	ll sum = 0;
	FOR(i,1,2*n+1) if (use[i]) {
		// dbg("UH",i);
		sum = (sum+i)%(2*n);
	}
	if (sum != 0) {
		// dbg("BAD");
		assert(sum == n);
		FOR(i,1,2*n+1) use[i] = use[i]^1;
	}
	FOR(i,1,2*n+1) if (use[i]) pr(i,' ');
	ps();
	FOR(i,1,n+1) {
		int x = todo[i][0], y = todo[i][1];
		dbg("????",x,y,(int)use[x],(int)use[y]);
		assert(use[x]+use[y] == 1);
		// if (use[x]) pr(x,' ');
		// if (use[y]) pr(y,' ');
	}
	// ps();
	// ps("OK");
	sum = 0;
	FOR(i,1,2*n+1) if (use[i]) sum = (sum+i)%(2*n);
	assert(sum == 0);
	// ll sum = 0;
	// vpi dif;
	// FOR(i,1,n+1) {
	// 	assert(sz(todo[i]) == 2);
	// 	if (rng()&1) swap(todo[i][0],todo[i][1]);
	// 	sum = (sum+todo[i][0])%(2*n);
	// 	dif.pb({(todo[i][1]-todo[i][0]+2*n)%(2*n),i});
	// }
	// while (1) {
	// 	shuffle(all(dif),rng);
	// 	// dbg("HA",sum,dif);
	// 	vi present(2*n,-1);
	// 	int cur = 0;
	// 	F0R(i,sz(dif)+1) {
	// 		// dbg("DOING",i,sz(dif));
	// 		if (i > 0) cur = (cur+dif[i-1].f)%(2*n);
	// 		present[cur] = i;
	// 		int z = present[(sum+cur)%(2*n)];
	// 		// dbg("???",z);
	// 		if (z != -1) {
	// 			FOR(j,z,i) mark[dif[j].s] = 1;
	// 			fin();
	// 		}
	// 	}
	// 	// trav(t,dif) {
	// 	// 	cur = (cur+t)%(2*n);
	// 	// 	if (prese)
	// 	// }
	// }
	// if (n == 1) {
	// 	ps("First");
	// 	ps(1,1);
	// }
	// B huh = B(); huh[0] = 1;
	// go(B(),huh);
	// you should actually read the stuff at the bottom
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/