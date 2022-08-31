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
const int MX = 2e5+5;
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

int N,M;
vi game;

int mex(set<int> s) {
	int cur = 0; while (s.count(cur)) cur ++;
	return cur;
}

int go(vi a, vi b) {
	while (sz(a) > 2) a.erase(begin(a));
	set<int> vals;
	F0R(i,sz(b)) {
		if (sz(a) == 2) {
			if (!(a[1]-a[0] < b[i]-a[1])) {
				continue;
			}
		}
		vi A = a; A.pb(b[i]);
		vals.ins(go(A,vi(begin(b)+i+1,end(b))));
	}
	return mex(vals);
}

int val() {
	// dbg(game);
	return go({},game);
	// return 1;
}

// int grundy(vi v) {
// 	set<int> mov;
// 	F0R(i,sz(v)) mov.insert(go(v[i],vi(begin(v)+1+i,end(v))));
// 	return mex(mov);
// }

int find_max(vi a, vi b) {
	F0R(i,sz(a)) FOR(j,i+1,sz(a)) FOR(k,j+1,sz(a))
		if (a[j]-a[i] >= a[k]-a[j]) return 0;
	int res = sz(a);
	// dbg("WHOOPS",a,b);
	F0R(i,sz(b)) {
		// if (sz(a) > 1) {
		// 	if (!(a.bk-a[sz(a)-2] < b[i]-a.bk)) {
		// 		continue;
		// 	}
		// }
		vi A = a; A.pb(b[i]);
		ckmax(res,find_max(A,vi(begin(b)+i+1,end(b))));
	}
	return res;
}

int brute() {
	// longest seq+1
	return find_max({},game);
}

int get_brute(vi v) {
	N = sz(v);
	game = v;
	return brute();
}

int get_val(vi v) {
	N = sz(v);
	game = v;
	return val();
}

void verify(vi v) {
	int ans = get_brute(v);
	// dbg(get_brute(v),get_val(v));
	if (ans < sz(v)) {
		F0R(i,sz(v)) {
			vi V = v; V.erase(begin(V)+i);
			dbg(ans,V,get_brute(V),get_val(V));
			if (ans == get_brute(V)) return;
		}
	}
	// dbg("BAD",v,ans); exit(0);
}

/**template<class T> T kruskal(int N, vector<pair<T,pi>> ed) {
	sort(all(ed));
	T ans = 0; DSU D; D.init(N); // edges that unite are in MST
	trav(a,ed) if (D.unite(a.s.f,a.s.s)) ans += a.f; 
	return ans;
}*/

/**
 * Description: Disjoint Set Union with path compression
 	* and union by size. Add edges and test connectivity. 
 	* Use for Kruskal's or Boruvka's minimum spanning tree.
 * Time: O(\alpha(N))
 * Source: CSAcademy, KACTL
 * Verification: *
 */

struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	void unite(int x, int y) { // union by size
		x = get(x), y = get(y); assert(x < y);
		e[x] = y;
	}
};

DSU D;

/**template<class T> T kruskal(int N, vector<pair<T,pi>> ed) {
	sort(all(ed));
	T ans = 0; DSU D; D.init(N); // edges that unite are in MST
	trav(a,ed) if (D.unite(a.s.f,a.s.s)) ans += a.f; 
	return ans;
}*/

int at_least[MX], rkey[MX];
int new_mx[MX];

int actual() {
	// store max slope such that answer will be x
	FOR(i,1,100005) at_least[i] = 100004;
	trav(t,game) at_least[t] = t;
	F0R(i,sz(game)) rkey[game[i]] = i;
	ROF(i,1,100004) ckmin(at_least[i],at_least[i+1]);
	vi mx(sz(game),MOD);
	set<int> all_vals;
	for (int val = 0;;++val) {
		bool not_done = 0;
		trav(t,mx) if (t > -MOD) not_done = 1;
		if (!not_done) break;
		F0R(i,sz(game)) new_mx[i] = -MOD;
		trav(t,game) D.e[t] = -1;
		R0F(i,sz(game)) {
			ckmin(new_mx[i],mx[i]);
			// int new_mx = mx[i]; ckmin(new_mx,tmp[i]-game[i]-1);
			if (mx[i] > -MOD && new_mx[i] <= -MOD) all_vals.ins(val);
			int lo = game[i]-mx[i], hi = game[i]-new_mx[i]; mx[i] = new_mx[i];
			ckmax(lo,1); ckmin(hi,game[i]); if (lo >= hi) continue;
			int huh = at_least[lo];
			while (1) {
				huh = D.get(huh);
				if (huh >= hi) break;
				new_mx[rkey[huh]] = game[i]-huh-1;
				D.unite(huh,at_least[huh+1]);
			}
		}
	}
	return mex(all_vals);
	// F0R(i,sz(game)) F0R(j,500) tmp_max[i][j] = -MOD;
	// set<int> vals;

	// R0F(i,sz(game)) {
	// 	vi mx{MOD};
	// 	for (int val = 1;;++val) {
	// 		mx.pb(mx.bk);
	// 		ckmin(mx.bk,tmp_max[i][val-1]-game[i]-1);
	// 		if (mx.bk <= -MOD) break;
	// 	}
	// 	// if game[i]-x is in range (mx[i][1],mx[i][0]] -> result is 0
	// 		// x is in range [game[i]-mx[i][0],game[i]-mx[i][1])
	// 	// if game[i]-x is in range (mx[i][2],mx[i][1]] -> result is 1

	// 	// game[x] is in range [game[i]-mx[i][0],game[i]-mx[i][1])
	// 	// [game[i]-mx[i][val-1],game[i]-mx[i][val]) -> tmp_max[x][val-1]
	// 	int pos = 0;
	// 	F0R(ind,i) {
	// 		while (game[i]-game[ind] <= mx[pos+1]) pos ++;
	// 		if (tmp_max[ind][pos] == -MOD) tmp_max[ind][pos] = game[i];
	// 	}
	// 	vals.ins(sz(mx)-2);
	// }
	// dbg("WUT",vals);
	// return mex(vals);
	// for (int val = 1;;++val) {
	// 	bool flag = 0;
	// 	F0R(a,sz(game)) {
	// 		int bes = -MOD;
	// 		FOR(b,a+1,sz(game))
	// 			if (game[b]-game[a] <= mx[b]) ckmax(bes,game[b]-game[a]-1);
	// 		assert(bes <= mx[a]);
	// 		mx[a] = bes;
	// 		if (mx[a] != -MOD) flag = 1;
	// 	}
	// 	dbg("HUH",mx);
	// 	if (!flag) return val;
	// }
}

int dumb() {
	V<vi> ans(sz(game),vi(sz(game)));
	set<int> al;
	R0F(j,sz(game)) {
		R0F(i,j) {
			set<int> bad;
			FOR(k,j+1,sz(game)) if (game[k]-game[j] > game[j]-game[i]) 
				bad.ins(ans[j][k]);
			ans[i][j] = mex(bad);
		}
		set<int> wut;
		FOR(k,j+1,sz(game)) wut.insert(ans[j][k]);
		al.ins(mex(wut));
		// start[j] = mex(ans[j][?]);
	}
	// dbg(ans)
	// dbg("???",al);
	return mex(al);
}

int main() {
	setIO();
	// N = 4;
	// game = {14,8,3,2};
	// ps(actual());
	// ps(dumb());
	// ps(find_max({},{15, 10, 6, 7, 5}));
	// N = 5; game = {15, 10, 6, 7, 5};
	// dbg(brute());
	// dbg(val());
	// dbg(get_val({1,2,4}));
	// dbg(get_val({1,2,0}));
	// verify({15, 10, 6, 7, 5});
	// dbg(brute());
	D.init(100005);
	// F0R(_,100000) {
	// 	dbg(_);
	// 	N = rng()%10+1;
	// 	game = vi(N);
	// 	trav(t,game) t = rng()%20+1;
	// 	sort(all(game)); game.erase(unique(all(game)),end(game));
	// 	N = sz(game);
	// 	if (actual() != val()) {
	// 		dbg(game,actual(),val());
	// 		exit(0);
	// 	}
	// 	dbg("OK");
	// }
	// exit(0);
	re(N);
	int ans = 0;
	F0R(i,N) {
		rv(M,game);
		ans ^= actual();
	}
	// dbg(ans);
	if (ans) ps("YES");
	else ps("NO");
	
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/