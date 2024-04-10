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
const int MX = 500001;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

ll mul(ll a, ll b) { return a*b%MOD; }
ll sub(ll a, ll b) { return (a-b+MOD)%MOD; }
ll ad(ll a, ll b) { return (a+b)%MOD; }
ll po(ll a, ll b) { return !b?1:po(a*a%MOD,b/2)*(b&1?a:1)%MOD; }

int n,m,k;
ll ans,c[MX];
map<ll,vpi> bad;

template<int SZ> struct DSU {
    int par[SZ], sz[SZ];
    
    int get(int x) { // path compression
    	if (par[x] != x) par[x] = get(par[x]);
    	return par[x];
    }
    
    bool unite(int x, int y) { // union-by-rank
    	x = get(x), y = get(y);
    	if (x == y) return 0;
    	if (sz[x] < sz[y]) swap(x,y);
    	sz[x] += sz[y], par[y] = x;
    	return 1;
    }
};

DSU<MX> D;

void process(vpi v) {
    map<int,int> m;
    for (auto a: v) m[a.f] = m[a.s] = 0;
    int co = 0;
    for (auto& a: m) a.s = co++;
    
    int res = n;
    F0R(i,sz(m)) D.par[i] = i, D.sz[i] = 1;
    for (auto& a: v) {
        a.f = m[a.f], a.s = m[a.s];
        if (D.unite(a.f,a.s)) res --;
    }
    ans = ad(ans,po(2,res));
}

int main() {
    io();
    cin >> n >> m >> k;
    F0R(i,n) cin >> c[i];
    F0R(i,m) {
        int u,v; cin >> u >> v; u--, v--;
        bad[c[u]^c[v]].pb({u,v});
    }
    ans = mul(po(2,n),sub(po(2,k),sz(bad)));
    for (auto a: bad) process(a.s);
    cout << ans;
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/