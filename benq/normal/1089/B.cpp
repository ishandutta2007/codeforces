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

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bit(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 

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
template<class A, class B> str ts(pair<A,B> p);
template<class A> str ts(complex<A> c) { return ts(mp(c.real(),c.imag())); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(char c) { str s = ""; s += c; return s; }
str ts(str s) { return s; }
str ts(const char* s) { return (str)s; }
str ts(vector<bool> v) { 
	bool fst = 1; str res = "{";
	F0R(i,sz(v)) {
		if (!fst) res += ", ";
		fst = 0; res += ts(v[i]);
	}
	res += "}"; return res;
}
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class T> str ts(T v) {
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
	cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 42
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

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 


/**
 * Description: Edmond's Blossom Algorithm. 
 	* General unweighted matching with 1-based indexing.
 * Time: O(N^3), fast in practice
 * Source: 
	* https://github.com/koosaga/DeobureoMinkyuParty
	* https://www-m9.ma.tum.de/graph-algorithms/matchings-blossom-algorithm/index_en.html
 * Verification: https://codeforces.com/contest/1089 B
 */

template<int SZ> struct UnweightedMatch {
	int match[SZ], N; vi adj[SZ];
	void ae(int u, int v) { adj[u].pb(v), adj[v].pb(u); }
	queue<int> q;
	int par[SZ], vis[SZ], orig[SZ];
	void augment(int u, int v) { // toggle edges on u-v path
		while (1) { // one more matched pair
			int pv = par[v], nv = match[pv];
			match[v] = pv; match[pv] = v;
			v = nv; if (u == pv) return;
		}
	}
	int lca(int u, int v) { // find LCA of supernodes in O(dist)
		static int t = 0, aux[SZ]; 
		if (!t) F0R(i,N+1) aux[i] = 0;
		for (++t;;swap(u,v)) {
			if (!u) continue;
			if (aux[u] == t) return u; // found LCA
			aux[u] = t; u = orig[par[match[u]]]; // what's orig[...]?
		}
	}
	void blossom(int u, int v, int a) {
		for (; orig[u] != a; u = par[v]) { // go other way around cycle
			par[u] = v; v = match[u]; // treat u as if vis[u] = 1
			if (vis[v] == 1) vis[v] = 0, q.push(v);
			orig[u] = orig[v] = a; // merge into supernode
		}
	}
	bool bfs(int u) { // u is initially unmatched
		F0R(i,N+1) par[i] = 0, vis[i] = -1, orig[i] = i;
		q = queue<int>(); vis[u] = 0, q.push(u);
		dbg("BFS");
		while (sz(q)) {
			int v = q.ft; q.pop(); // 0 -> unmatched vertex
			trav(x,adj[v]) {
				if (vis[x] == -1) { // neither of x, match[x] visited
					vis[x] = 1; par[x] = v;
					if (!match[x]) return augment(u,x),1;
					vis[match[x]] = 0, q.push(match[x]);
				} else if (vis[x] == 0 && orig[v] != orig[x]) {
					int a = lca(orig[v],orig[x]); // odd cycle
					blossom(x,v,a), blossom(v,x,a); // contract O(n) times
				}
			}
		}
		return 0;
	}
	int calc(int _N) { 
		N = _N; F0R(i,N+1) match[i] = 0; 
		// dbg("WUT");
		// find random matching, constant improvement
		int ans = 0; vi V(N-1); iota(all(V),1); shuffle(all(V),rng);
		trav(x,V) if (!match[x]) trav(y,adj[x]) if (!match[y]) { 
			match[x] = y, match[y] = x; ++ans; break; }
		FOR(i,1,N+1) if (!match[i] && bfs(i)) ++ans;
		// dbg("WUT",ans);
		return ans;
	}
};

 
int T;
 
int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(T);
    F0R(i,T) {
    	UnweightedMatch<301> B;
        int N,M; re(N,M);
        FOR(j,1,N+1) B.ae(j,j+N);
        FOR(j,1,N+1) FOR(k,1,M+1) {
            char c; re(c);
            if (c == '1') B.ae(j,k+2*N), B.ae(j+N,k+2*N);
        }
        cout << B.calc(2*N+M)-N << "\n";
    }
    
    // you should actually read the stuff at the bottom
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/