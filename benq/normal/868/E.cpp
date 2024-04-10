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
const int MX = 100001;

int n,dist[51][51];
vpi adj[51];
int dp[51][51];
vi leaf;

void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FOR(i,1,n+1) FOR(j,1,n+1) {
        if (i == j) dist[i][j] = 0;
        else dist[i][j] = MOD;
    }
    F0R(i,n-1) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].pb({v,w}), adj[v].pb({u,w});
        dist[u][v] = dist[v][u] = w;
    }
    FOR(i,1,n+1) if (sz(adj[i]) == 1) leaf.pb(i);
    FOR(k,1,n+1) FOR(i,1,n+1) FOR(j,1,n+1) 
        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
}

void gen(int x, int y) {
    array<int,51> co; 
    priority_queue<pi> q;
    for (int z: leaf) q.push({dp[z][co[z] = y-1]+dist[x][z],z});
    F0R(i,y) {
        auto a = q.top(); q.pop();
        if (i == y-1) {
            dp[x][y] = a.f;
            return;
        }
        q.push({dp[a.s][--co[a.s]]+dist[x][a.s],a.s});
    }
}

int par[51];

void dfs(int x, int pre, int lab) {
    par[x] = lab;
    for (auto i: adj[x]) if (i.f != pre) dfs(i.f,x,lab);
}

int GEN(int x, vi y) {
    array<int,51> tmp = array<int,51>();
    array<int,51> co; 
    
    for (auto i: adj[x]) dfs(i.f,x,i.f);
    for (int& i: y) tmp[par[i]] ++;
    
    int ans = MOD;
    FOR(i,1,n+1) if (tmp[i]) {
        priority_queue<pi> q;
        for (int z: leaf) if (par[z] == i) q.push({dp[z][co[z] = sz(y)-1]+dist[x][z],z});
        F0R(j,tmp[i]) {
            auto a = q.top(); q.pop();
            if (j == tmp[i]-1) ans = min(ans,a.f);
            else q.push({dp[a.s][--co[a.s]]+dist[x][a.s],a.s});
        }
    }
    
    return ans;
}

int main() {
    init();
    FOR(j,1,51) for (int i: leaf) gen(i,j);
    int s,m; cin >> s >> m;
    vi v(m);
    F0R(i,m) cin >> v[i];
    cout << GEN(s,v);
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/