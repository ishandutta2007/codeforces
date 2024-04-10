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
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

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

const int MAXN = 200001, MAXK = 18;

pi dist[MX];

struct LCA {
    int V, R;
    vi edges[MAXN];
    int parK[MAXK][MAXN];
    pi depth[MAXN];
    bool visit[MAXN];
    
    void addEdge(int u, int v) {
        edges[u].pb(v), edges[v].pb(u);
    }
    
    void dfs(int u, int prev){
        visit[u] = 1;
        parK[0][u] = prev;
        depth[u].f = depth[prev].f+1;
        depth[u].s += depth[prev].s;
        for (int v: edges[u]) if (v != prev) dfs(v, u);
    }
    
    void construct() {
        FOR(i,1,V+1) if (!visit[i]) dfs(i,0);
        FOR(k,1,MAXK) FOR(i,1,V+1)
            parK[k][i] = parK[k-1][parK[k-1][i]];
    }
    
    int lca(int u, int v){
        if (depth[u].f < depth[v].f) swap(u,v);
        
        F0Rd(k,MAXK) if (depth[u].f >= depth[v].f+(1<<k)) u = parK[k][u];
        F0Rd(k,MAXK) if (parK[k][u] != parK[k][v]) u = parK[k][u], v = parK[k][v];
        
        if(u != v) u = parK[0][u], v = parK[0][v];
        return u;
    }
    
    int dist(int u, int v) {
        return depth[u].s+depth[v].s-2*depth[parK[0][lca(u,v)]].s;
    }
};

LCA L;

template<int SZ> struct BCC {
    int N, ti = 0;
    vi adj[SZ];
    int disc[SZ], low[SZ], comp[SZ], par[SZ];
    vector<vpi> fin;
    vpi st;
    
    void addEdge(int u, int v) {
        adj[u].pb(v), adj[v].pb(u);
    }
    
    void BCCutil(int u) {
        disc[u] = low[u] = ti++;
        int child = 0;
        
        for (int i: adj[u]) if (i != par[u]) {
            if (disc[i] == -1) {
                child ++; par[i] = u;
                st.pb({u,i});
                BCCutil(i);
                low[u] = min(low[u],low[i]);
                
                if ((disc[u] == 0 && child > 1) || (disc[u] != 0 && disc[u] <= low[i])) { // articulation point!
                    vector<pi> tmp;
                    while (st.back() != mp(u,i)) tmp.pb(st.back()), st.pop_back();
                    tmp.pb(st.back()), st.pop_back();
                    fin.pb(tmp);
                }
            } else if (disc[i] < disc[u]) {
                low[u] = min(low[u],disc[i]);
                st.pb({u,i});
            }
        }
    }
    
    void bcc() {
        FOR(i,1,N+1) par[i] = disc[i] = low[i] = -1;
        FOR(i,1,N+1) if (disc[i] == -1) {
            BCCutil(i);
            if (sz(st)) fin.pb(st);
            st.clear();
        }
        F0R(i,sz(fin)) {
            set<int> al;
            bool bipart = 1;
            for (auto j: fin[i]) {
                al.insert(j.f), al.insert(j.s);
                if (dist[j.f].f == dist[j.s].f) bipart = 0;
            }
            if (!bipart) L.depth[N+1+i].s ++;
            for (int j: al) L.addEdge(N+1+i,j);
        }
    }
};

BCC<MX> B;
int n,m;

void dfs(int x) {
    for (int i: B.adj[x]) if (dist[i].s == 0) {
        dist[i].f = dist[x].f^1;
        dist[i].s = dist[x].s;
        dfs(i);
    }
}

int ok(int a, int b) {
    if (dist[a].s != dist[b].s) return 0;
    if (dist[a].f != dist[b].f) return 1;
    return L.dist(a,b) > 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,m) {
        int a,b; cin >> a >> b;
        B.addEdge(a,b);
    }
    FOR(i,1,n+1) if (dist[i].s == 0) {
        dist[i].s = i;
        dfs(i);
    }
    B.N = L.V = n;
    B.bcc();
    L.construct();
    int q; cin >> q;
    F0R(i,q) {
        int a,b; cin >> a >> b;
        if (ok(a,b)) cout << "Yes\n";
        else cout << "No\n";
    }
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)