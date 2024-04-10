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
const int MX = 500005;

template<int SZ> struct DSU {
    int par[SZ], sz[SZ];
    DSU() {
        F0R(i,SZ) par[i] = i, sz[i] = 1;
    }
    
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

vpi adj[MX];
int N,M,ans[MX]; 

struct {
    int par[20][MX], mn[20][MX];
    int key[MX], depth[MX];
    bool good[MX];
    
    void dfs(int cur) {
        for (auto a: adj[cur]) if (a.f != par[0][cur]) {
            good[a.f] = a.s;
            par[0][a.f] = cur;
            key[a.f] = a.s;
            depth[a.f] = depth[cur]+1;
            dfs(a.f);
        }
    }
    
    void gen() {
        FOR(i,1,N+1) key[i] = -1;
        F0R(j,20) FOR(i,1,N+1) mn[j][i] = MOD;
        dfs(1);
        FOR(j,1,20) FOR(i,1,N+1) par[j][i] = par[j-1][par[j-1][i]];
    }
    
    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a,b);
        F0Rd(i,20) if ((depth[a]-depth[b])&(1<<i)) a = par[i][a];
        F0Rd(i,20) if (par[i][a] != par[i][b]) a = par[i][a], b = par[i][b];
        if (a == b) return a;
        return par[0][a];
    }
    
    void AD(int a, int x, int c) {
        F0Rd(i,20) if (x&(1<<i)) {
            mn[i][a] = min(mn[i][a],c);
            a = par[i][a];
        }
    }
    
    void ad(int a, int b, int c) {
        int x = lca(a,b);
        // cout << a << " " << b << " " << x << "\n";
        AD(a,depth[a]-depth[x],c);
        AD(b,depth[b]-depth[x],c);
    }
    
    void push() {
        FORd(j,1,20) FOR(i,1,N+1) {
            mn[j-1][i] = min(mn[j-1][i],mn[j][i]);
            mn[j-1][par[j-1][i]] = min(mn[j-1][par[j-1][i]],mn[j][i]);
        }
    }
    
    void solve(vector<array<int,3>> no) {
        gen();
        for (auto x: no) ad(x[1],x[2],x[0]);
        push();
    }
} L;

void addEdge(int a, int b, int t) {
    adj[a].pb({b,t}), adj[b].pb({a,t});
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k;
    cin >> N >> k >> M;
    F0R(i,k) {
        int a,b; cin >> a >> b;
        D.unite(a,b);
        addEdge(a,b,1);
    }
    vector<array<int,3>> ed, no;
    F0R(i,M) {
        int a,b,w; cin >> a >> b >> w;
        ed.pb({w,a,b});
    }
    sort(all(ed));
    for (auto a: ed) {
        if (D.unite(a[1],a[2])) {
            addEdge(a[1],a[2],0);
        } else {
            no.pb(a);
        }
    }
    
    L.solve(no);
    
    ll cost = 0;
    FOR(i,1,N+1) if (L.good[i]) {
        cost += L.mn[0][i];
        if (L.mn[0][i] == MOD) {
            cout << -1;
            exit(0);
        }
    }
    cout << cost;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/