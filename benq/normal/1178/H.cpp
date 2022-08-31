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

template<class T> T invGeneral(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modular {
    T val; 
    explicit operator T() const { return val; }
    modular() { val = 0; }
    modular(const ll& v) { 
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
    friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular pow(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { 
        auto i = invGeneral(a.val,MOD); assert(i != -1);
        return i;
    } // equivalent to return exp(b,MOD-2) if MOD is prime
    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

template<class T> T poll(pqg<T>& x) {
    T y = x.top(); x.pop();
    return y;
}

template<int SZ> struct mcf { // assume no negative cycles
    struct Edge { int v, rev; ll flow, cap, cost; };

    vector<Edge> adj[SZ];

    void addEdge(int u, int v, ll cap, ll cost) {
        Edge a{v, sz(adj[v]), 0, cap, cost}, b{u, sz(adj[u]), 0, 0, -cost};
        adj[u].pb(a), adj[v].pb(b);
    }

    int ST, EN;
    pi pre[SZ]; // previous vertex, edge label on path
    pl cost[SZ]; // tot cost of path, amount of flow
    ll totFlow, totCost, curCost;

    void reweight() { // ensures all non-negative edge weights
    	F0R(i,SZ) trav(p,adj[i]) p.cost += cost[i].f-cost[p.v].f;
    }

    bool spfa() { // reweighting will ensure that there will be negative weights only during the first time you run this
        F0R(i,SZ) cost[i] = {INF,0};
        cost[ST] = {0,INF};
        pqg<pair<ll,int>> todo; todo.push({0,ST});

        while (sz(todo)) {
            auto x = poll(todo); if (x.f > cost[x.s].f) continue;
            trav(a,adj[x.s]) if (x.f+a.cost < cost[a.v].f && a.flow < a.cap) {
                pre[a.v] = {x.s,a.rev};
                cost[a.v] = {x.f+a.cost, min(a.cap-a.flow,cost[x.s].s)};
                todo.push({cost[a.v].f,a.v});
            }
        }

        curCost += cost[EN].f; return cost[EN].s;
    }

    void backtrack() {
        auto f = cost[EN].s; totFlow += f, totCost += curCost*f;
        for (int x = EN; x != ST; x = pre[x].f) {
            adj[x][pre[x].s].flow -= f;
            adj[pre[x].f][adj[x][pre[x].s].rev].flow += f;
        }
    }

    pl minCostFlow(int _ST, int _EN) {
        ST = _ST, EN = _EN; totFlow = totCost = curCost = 0;
        spfa();
        while (1) {
            reweight();
            if (!spfa()) return {totFlow, totCost};
            backtrack();
        }
    }
};

mcf<9000> D;

int n;
int lo = 0, hi = 1e9;
vpi ed;
vi v;

bool ok(int mid) { // check if ok
	// exchange with the max at t
	int ind = -1;
	ll mx = 0;
	vl x, y;
	trav(t,v) {
		while (ind+1 < sz(v) && ed[v[ind+1]].s <= ed[t].s) {
			ind ++;
			ckmax(mx,ed[v[ind]].s+(ll)ed[v[ind]].f*mid);
		}
		if (t < n) y.pb(mx);
		else x.pb(ed[t].s+(ll)ed[t].f*mid);
	}
	sort(all(x));
	F0R(i,sz(x)) if (x[i] > y[i]) return 0;
	return 1;
}

ll cost[4400];
vpl x, y;

int solve(int mid) {
	F0R(i,2*n) cost[i] = (ll)ed[i].f*mid+ed[i].s;
	F0R(i,2*n) {
		x.pb({ed[i].s,i});
		y.pb({cost[i],i});
	}
	sort(all(x)), sort(all(y));
	int ind = -1, lst = -MOD; pl bes = {-INF,-INF};
	F0R(i,sz(x)) {
		while (ind+1 < sz(x) && x[ind+1].f <= x[i].f) {
			int t = x[++ind].s;
			ckmax(bes,{cost[t],t});
		}
		int t = x[i].s;
		if (t < n) {
			D.addEdge(0,t+1,1,0);
			D.addEdge(t+1,bes.s+1,1,1); // best
			if (lst != -MOD) D.addEdge(t+1,lst+1,1,1); // last
		} else {
			if (lst != -MOD) D.addEdge(t+1,lst+1,MOD,0); // go prev
			D.addEdge(t+1,t+2*n+1,1,0);
			lst = t;
		}
	}
	ind = -1; vi bad;
	F0R(i,sz(y)) {
		while (ind+1 < sz(y) && y[ind+1].f <= y[i].f) {
			int t = y[++ind].s;
			if (t >= n) bad.pb(t);
		}
		int t = y[i].s;
		if (sz(bad)) D.addEdge(t+1,sz(bad)+2*n,MOD,1);
	}
	F0R(i,n) {
		if (i) D.addEdge(2*n+1+i,2*n+i,MOD,0);
		D.addEdge(2*n+1+i,2*n+1+bad[i],1,0);
	}
	F0R(i,n) D.addEdge(i+3*n+1,4*n+1,1,0);
	auto z = D.minCostFlow(0,4*n+1); assert(z.f == n);
	// ps("HUH",z.f);
	return z.s;
}

int main() {
    setIO(); re(n);
    ed.rsz(2*n); re(ed);
    F0R(i,2*n) v.pb(i);
    sort(all(v),[](int x, int y) { return ed[x].s < ed[y].s; });
    if (!ok(hi)) {
    	ps(-1);
    	exit(0);
    }
    while (lo < hi) {
    	int mid = (lo+hi)/2;
    	if (ok(mid)) hi = mid;
    	else lo = mid+1;
    }
    pr(lo,' ',solve(lo));
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/