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
const int MX = 1001;

int n,m,s,t,x[30001],y[30001],w[30001];
bool isBridge[30001];

template<int SZ> struct BCC {
    int N, ti = 0;
    vpi adj[SZ];
    int disc[SZ], low[SZ], comp[SZ], par[SZ];
    vi bridge;
    pi dist[SZ];
    bool visit[SZ];
    
    void addEdge(int u, int v, int z) {
        adj[u].pb({v,z}), adj[v].pb({u,z});
    }
    
    void BCCutil(int u, bool root = 0) {
        disc[u] = low[u] = ti++;
        int child = 0;
        
        int co = 0;
        for (auto i: adj[u]) {
            if (i.f == par[u]) {
                if (!co) {
                    co ++;
                    continue;
                }
            }
            if (disc[i.f] == -1) {
                child ++; par[i.f] = u;
                BCCutil(i.f);
                low[u] = min(low[u],low[i.f]);
                
                if (disc[u] < low[i.f]) bridge.pb(i.s);
            } else if (disc[i.f] < disc[u]) {
                low[u] = min(low[u],disc[i.f]);
            }
        }
    }
    
    pi gen(int x, int y) {
        for (int i: bridge) isBridge[i] = 1;
        // cout << "HI " << sz(bridge) << "\n";
        dist[x] = {MOD,MOD}; visit[x] = 1;
        pi ans = {-1,-1};
        queue<int> q; q.push(x);
        
        while (sz(q)) {
            int z = q.front(); q.pop();
            // cout << "OH " << z << "\n";
            for (auto i: adj[z]) if (!visit[i.f]) {
                // cout << "HUH " << i.f << " " << y << "\n";
                pi ed = {w[i.s],i.s}; if (!isBridge[i.s]) ed.f = MOD;
                dist[i.f] = min(ed,dist[z]);
                visit[i.f] = 1;
                if (i.f == y) {
                    ans = dist[i.f];
                    break;
                }
                q.push(i.f);
                // cout << "ZZ\n";
            }
        }
        
        for (int i: bridge) isBridge[i] = 0;
        return ans;
    }
    
    void bcc() {
        FOR(i,1,N+1) par[i] = disc[i] = low[i] = -1;
        FOR(i,1,N+1) if (disc[i] == -1) {
            BCCutil(i,1);
        }
    }
};

BCC<MX> B;

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

DSU<MX> D[3];

vi posiEdge;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> s >> t;
    FOR(i,1,m+1) {
        cin >> x[i] >> y[i] >> w[i];
        if (D[0].unite(x[i],y[i]) || D[1].unite(x[i],y[i]) || D[2].unite(x[i],y[i])) posiEdge.pb(i);
    }
    if (D[0].get(s) != D[0].get(t)) {
        cout << "0\n0";
        exit(0);
    }
    
    pair<int,vi> ans = {2*MOD,{}};
    F0R(i,sz(posiEdge)) {
        B = BCC<MX>(); B.N = n;
        F0R(j,sz(posiEdge)) if (j != i) B.addEdge(x[posiEdge[j]],y[posiEdge[j]],posiEdge[j]);
        B.bcc();
        pi d = B.gen(s,t); // min edge weight on path 
        if (d.f == MOD) { 
            
        } else if (d.f == -1) { // no path 
            // cout << "A " << w[posiEdge[i]] << "\n";
            ans = min(ans,{w[posiEdge[i]],{posiEdge[i]}});
        } else {
            // cout << "B " << w[posiEdge[i]]+d.f << "\n";
            ans = min(ans,{w[posiEdge[i]]+d.f,{posiEdge[i],d.s}});
        }
    }
    if (ans.f == 2*MOD) {
        cout << -1;
        exit(0);
    }
    cout << ans.f << "\n";
    cout << sz(ans.s) << "\n";
    for (int i: ans.s) cout << i << " ";
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/