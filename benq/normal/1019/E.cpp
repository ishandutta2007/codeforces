#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
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

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

bool Q;

struct Line {
	mutable ll k, m, p; // slope, y-intercept, last optimal x
	bool operator<(const Line& o) const {
		return Q ? p < o.p : k < o.k;
	}
};

struct LineContainer : multiset<Line> { 
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
	    if (b < 0) a *= -1, b *= -1;
	    if (a >= 0) return a/b;
	    return -((-a+b-1)/b);
	}
	
	// updates x->p, determines if y is unneeded
	bool isect(iterator x, iterator y) { 
		if (y == end()) { x->p = inf; return 0; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
	
	ll query(ll x) { // gives max value
		assert(!empty());
		Q = 1; auto l = *lb({0,0,x}); Q = 0;
		return l.k * x + l.m;
	}
};

pl operator+(const pl& l, const pl& r) { return {l.f+r.f,l.s+r.s}; }

LineContainer cand;

template<int SZ> struct centroidDecomp {
    int N;
    bool done[SZ];
    int sub[SZ], par[SZ], ans[SZ], cen[SZ];
    vector<array<int,3>> adj[SZ];
    
    // INITIALIZE
    
    void addEdge(int u, int v, int a, int b) { 
        adj[u].pb({v,a,b});
        adj[v].pb({u,a,b});
    }
    
    void dfs (int no) {
        sub[no] = 1;
        for (auto i: adj[no]) if (!done[i[0]] && i[0] != par[no]) {
            par[i[0]] = no;
            dfs(i[0]);
            sub[no] += sub[i[0]];
        }
    }
    
    LineContainer cur;
    
    void genDist(int par, int no, int t, pl dis) {
        cur.add(dis.f,dis.s);
        for (auto i: adj[no]) if (!done[i[0]] && i[0] != par) {
            cen[i[0]] = t;
            genDist(no,i[0],t,dis+mp(i[1],i[2]));
        }
    }
    
    int getCentroid(int x) {
        par[x] = 0; dfs(x);
        int sz = sub[x];
        while (1) {
            pi mx = {0,0};
            for (auto i: adj[x]) if (!done[i[0]] && i[0] != par[x]) mx = max(mx,{sub[i[0]],i[0]});
            if (mx.f*2 > sz) x = mx.s;
            else return x;
        }
    }
    
    void tri(LineContainer& a, LineContainer& b) {
        auto ita = a.begin(), itb = b.begin();
        while (ita != a.end() && itb != b.end()) {
            cand.add(ita->k+itb->k,ita->m+itb->m);
            if (ita->p < itb->p) ita = next(ita);
            else itb = next(itb);
        }
    }
    
    void compress(vector<LineContainer>& v, int l, int r) {
        if (l == r) return;
        int m = (l+r)/2;
        compress(v,l,m), compress(v,m+1,r);
        tri(v[l],v[m+1]);
        for (auto a: v[m+1]) v[l].add(a.k,a.m);
    }
    
    void solve (int x) {
        x = getCentroid(x); done[x] = 1;
        vector<LineContainer> v;
        for (auto i: adj[x]) if (!done[i[0]]) {
            cur.clear();
            genDist(x,i[0],x,{i[1],i[2]});
            v.pb(cur);
        }
        if (sz(v)) {
            compress(v,0,sz(v)-1);
            for (auto a: v[0]) cand.add(a.k,a.m);
        }
        for (auto i: adj[x]) if (!done[i[0]]) solve(i[0]);
    }
};

centroidDecomp<MX> c;

int n,m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,n-1) {
        int u,v,a,b; cin >> u >> v >> a >> b;
        c.addEdge(u,v,a,b);
    }
    c.solve(1);
    int nex = 0;
    cand.add(0,0);
    for (auto a: cand) {
        while (nex <= a.p) {
            if (nex == m) break;
            cout << a.k*nex+a.m << " ";
            nex ++;
        }
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/