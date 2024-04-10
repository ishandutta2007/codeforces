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
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007;
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

template<int SZ> struct Dinic {
    struct Edge { int v, rev; ll flow, cap; };

    vector<Edge> adj[SZ];

    void addEdge(int u, int v, ll cap) {
        Edge a{v, sz(adj[v]), 0, cap}, b{u, sz(adj[u]), 0, 0};
        adj[u].pb(a), adj[v].pb(b);
    }

    int ST, EN, level[SZ], ind[SZ];

    bool bfs() { // level = shortest distance from source
        // after computing flow, edges {u,v} such that level[u] \neq -1, level[v] = -1 are part of min cut
        F0R(i,SZ) level[i] = -1, ind[i] = 0;
        level[ST] = 0;

        queue<int> q; q.push(ST);
        while (sz(q)) {
            int u = q.front(); q.pop();
            trav(e,adj[u]) if (level[e.v] < 0 && e.flow < e.cap) {
                level[e.v] = level[u] + 1;
                q.push(e.v);
            }
        }

        return level[EN] >= 0;
    }

    ll sendFlow(int s, ll flow) {
        if (s == EN) return flow;

        for (  ; ind[s] < sz(adj[s]); ind[s] ++) {
            Edge& e = adj[s][ind[s]];

            if (level[e.v] != level[s]+1 || e.flow == e.cap) continue;
            ll f = sendFlow(e.v, min(flow, e.cap - e.flow));

            if (f) { // saturate at least one edge
                e.flow += f; adj[e.v][e.rev].flow -= f;
                return f;
            }
        }

        return 0;
    }

    ll maxFlow(int _ST, int _EN) {
        ST = _ST, EN = _EN;
        if (ST == EN) return -1;
        ll tot = 0;
        while (bfs()) while (auto flow = sendFlow(ST, LLONG_MAX)) tot += flow;
        return tot;
    }
};

vector<array<int,6>> ed;

const ll BIG = 1e7;
int n,m;

ll solve(ll x) {
	Dinic<1002> D = Dinic<1002>();
	ll suml = 0;
	trav(t,ed) {
		ll l = t[2]*x+t[3]*BIG, r = t[4]*x+t[5]*BIG;
		D.addEdge(0,t[1],l); D.addEdge(t[0],n+1,l);
		D.addEdge(t[0],t[1],r-l);
		suml += l;
	}
	return suml-D.maxFlow(0,n+1);
}

ll fst(ll l, ll r) {
	while (l < r) {
		ll m = (l+r)/2;
		if (solve(m) > 0) l = m+1;
		else r = m;
	}
	return l;
}

ll lst(ll l, ll r) {
	while (l < r) {
		ll m = (l+r+1)/2;
		if (solve(m) > 0) r = m-1;
		else l = m;
	}
	return l;
}

void fin(ll x) {
	cout << fixed << setprecision(7) << (ld)x/BIG;
	exit(0);
}

int main() {
    setIO();
    re(n,m); ed.resz(m); re(ed);
    ll l = 0, r = BIG;
    //cout << solve(1) << " " << solve(2); exit(0);
    while (l+2 < r) {
    	ll m1 = (2*l+r)/3, m2 = (l+2*r)/3;
    	if (solve(m1) <= solve(m2)) r = m2;
    	else l = m1;
        // cerr << "WHAT " << l << " " << r << "\n";
    }
    pl bes = {INF,INF};
    FOR(i,l,r+1) ckmin(bes,{solve(i),i});
    if (bes.f > 0) fin(0);
    else fin(lst(bes.s,BIG)-fst(0,bes.s));
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/