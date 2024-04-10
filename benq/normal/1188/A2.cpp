#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
 
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize
 
const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 200005;
const ld PI = 4*atan((ld)1);
 
template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }
 
namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
 
    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
 
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
 
using namespace input;
 
namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);
 
    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }
 
    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}
 
using namespace output;
 
namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}
 
using namespace io;
 
vector<array<int,3>> sol;
int depth[1001], par[1001];
int n, leaf[1001],des[1001],cur[1001];
set<int> adj[1001];

int notLeaf(int x) {
	int res = 0;
	trav(t,adj[x]) if (sz(adj[t]) > 1) res ++;
	return res;
}

vi remLeaves(int x) {
	vi ret;
	trav(t,adj[x]) if (sz(adj[t]) == 1) {
		ret.pb(t);
		leaf[x] = leaf[t];
	}
	trav(t,ret) adj[t].erase(x), adj[x].erase(t);
	return ret;
}

void insLeaves(vi v, int x) {
	trav(t,v) {
		adj[x].insert(t), adj[t].insert(x);
	}
}

void ad(int x, int y, int z) {
    sol.pb({x,y,z});
	while (x != y) {
		if (depth[x] < depth[y]) swap(x,y);
		cur[x] += z; x = par[x];
	}
}

int needDif(pi x) {
	if (depth[x.f] < depth[x.s]) swap(x.f,x.s);
	assert(par[x.f] == x.s);
	return des[x.f]-cur[x.f];
}

void adjust(int a, int b, int c, pi x) {
	a = leaf[a], b = leaf[b];
	int X = needDif(x); assert(X%2 == 0);
	if (c == -1) {
		FOR(i,1,n+1) if (sz(adj[i]) && leaf[i] != a && leaf[i] != b) c = leaf[i];
		assert(c != -1);
	} else c = leaf[c];
	assert(a != b && b != c && c != a);
	ad(a,b,X/2); ad(a,c,X/2); ad(b,c,-X/2);
}

void solve() {
	set<int> bad;
	FOR(i,1,n+1) if (sz(adj[i]) == 1) {
		int x = *adj[i].begin();
		if (bad.count(x) || notLeaf(x) > 1) {
			bad.insert(x);
			continue;
		}
		vi v = remLeaves(x); // ps(v,x,leaf[x]); exit(0);
		assert(sz(v) > 1);
		solve(); 
		if (sz(v) > 2) {
			F0R(i,sz(v)) adjust(v[i],v[(i+1)%sz(v)],v[(i+2)%sz(v)],{v[i],x});
		} else {
			F0R(i,sz(v)) adjust(v[i],v[(i+1)%sz(v)],-1,{v[i],x});
			assert(sz(v) == 2);
		}
		insLeaves(v,x);
		return;
	}
	// ps("??"); exit(0);
	FOR(i,1,n+1) assert(sz(adj[i]) == 0);
}

void dfs(int x) {
	trav(t,adj[x]) if (t != par[x]) {
		par[t] = x;
		depth[t] = depth[x]+1;
		dfs(t);
	}
}

void init() {
    setIO(); re(n);
    vector<array<int,3>> ed;
    F0R(i,n-1) {
    	int a,b,val; re(a,b,val);
    	adj[a].insert(b), adj[b].insert(a);
    	ed.pb({a,b,val});
    	if (n == 2) {
    	    sol.pb({a,b,val});
            ps("YES"); ps(sz(sol));
            trav(t,sol) ps(t[0],t[1],t[2]);
    	    exit(0);
    	}
    }
    dfs(1);
    trav(t,ed) {
    	if (depth[t[0]] < depth[t[1]]) swap(t[0],t[1]);
    	des[t[0]] = t[2];
    	// ps("HA",t[0]);
    }
    // exit(0);
}

int main() {
	init();
    FOR(i,1,n+1) if (sz(adj[i]) == 2) {
    	ps("NO");
    	exit(0);
    }
    FOR(i,1,n+1) if (sz(adj[i]) == 1) leaf[i] = i;
    solve();
    FOR(i,1,n+1) assert(cur[i] == des[i]);
    ps("YES"); ps(sz(sol));
    trav(t,sol) ps(t[0],t[1],t[2]);
    // you should actually read the stuff at the bottom
}
 
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/