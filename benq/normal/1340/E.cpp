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
void ps() { cout << endl; } // print w/ spaces
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
 
int n,m,dist[5001][5001];
vi cur = {1,2,3};
vi adj[MX];
 
int goal = -1;
 
void interact() {
	ps(cur[0],cur[1],cur[2]);
	F0R(i,3) if (cur[i] == goal) exit(0);
	re(goal);
	F0R(i,3) if (cur[i] == goal) exit(0);
}
 
vi getNei(int x) {
	vi v = adj[x]; v.pb(x);
	return v;
}
 
int eval(int a, int b, int c, int goal) {
	if (a == goal || b == goal || c == goal) return -MOD;
	int mx = -MOD;
	trav(t,adj[goal]) {
		if (a == t || b == t || c == t) continue;
		ckmax(mx,dist[a][t]+dist[b][t]+dist[c][t]);
	}
	mx *= 10;
	set<int> dis = {a,b,c};
	mx += sz(dis);
	return mx;
}

void toward(int& a, int b) {
	vi v = getNei(a);
	int dis = MOD;
	trav(t,v) ckmin(dis,dist[t][b]);
	trav(t,v) if (dis == dist[t][b]) {
		a = t;
		return;
	}
}
 
void go() {
	auto Z = adj[goal];
	F0R(i,3) if (dist[cur[i]][goal] == 1) {
		cur[i] = goal;
		interact();
	}
	int mn = MOD; vi bes;
	F0R(i,sz(Z)) F0R(j,sz(Z)) F0R(k,sz(Z)) {
		set<int> s = {i,j,k}; if (sz(s) != sz(Z)) continue;
		int sum = 0;
		sum += dist[cur[0]][Z[i]];
		sum += dist[cur[1]][Z[j]];
		sum += dist[cur[2]][Z[k]];
		if (sum < mn) mn = sum, bes = {Z[i],Z[j],Z[k]};
	}
	F0R(i,3) toward(cur[i],bes[i]);
	interact();
}
 
void genDist(int x) {
	FOR(i,1,n+1) dist[x][i] = MOD;
	dist[x][x] = 0;
	queue<int> q; q.push(x);
	while (sz(q)) {
		int t = q.ft; q.pop();
		trav(u,adj[t]) if (dist[x][u] == MOD) {
			dist[x][u] = dist[x][t]+1;
			q.push(u);
		}
	}
}
 
int main() {
	re(n,m);
	F0R(i,m) {
		int u,v; re(u,v);
		adj[u].pb(v), adj[v].pb(u);
	}
	FOR(i,1,n+1) genDist(i);
	FOR(i,1,n+1) FOR(j,1,n+1) dbg(i,j,dist[i][j]);
	interact();
	while (1) go();
	// you should actually read the stuff at the bottom
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/