#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MAX = 1e5 + 5;
const int LOG = 17; 

int depth[MAX];
int par[MAX][LOG];

vi top[MAX][LOG];
vi g[MAX];
vi city[MAX];

int n, m, q;

void dfs(int cur, int prev) {
    par[cur][0] = prev;
    
    if (city[cur].size() > 10) city[cur].resize(10);
    top[cur][0] = city[cur];
    
    for (int nxt : g[cur]) {
        if (nxt == prev) continue;
        
        depth[nxt] = depth[cur] + 1;
        dfs(nxt, cur);
    }
}

vi merge(vi a, vi b) {
    for (int x : a) b.pb(x); 
    sort(b.begin(), b.end());
    if (b.size() <= 10) return b; 
    b.resize(10);
    return b;
}

void process() {
    depth[0] = 0;        
    dfs(0, 0);
    
    F0R (lvl, LOG - 1) F0R (cur, n) {
        int mid = par[cur][lvl];
        par[cur][lvl + 1] = par[mid][lvl];
        if (depth[cur] < (1 << lvl))
            top[cur][lvl + 1] = top[cur][lvl];
        else
            top[cur][lvl + 1] = merge(top[cur][lvl], top[mid][lvl]);
    }
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int it = LOG-1; it >= 0; it--) 
        if (depth[u] - depth[v] >= (1 << it))
            u = par[u][it];
    
    if (u == v) return u;
    
    for (int it = LOG-1; it >= 0; it--)
        if (par[u][it] != par[v][it]) u = par[u][it], v = par[v][it];
    
    return par[u][0];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> q; 
    F0R (i, n-1) {
        int u, v; cin >> u >> v;
        g[u - 1].pb(v - 1), g[v - 1].pb(u - 1);
    }
    F0R (i, m) {
        int c_i; cin >> c_i;
        city[c_i-1].pb(i);    
    }
    
    process();
    
    F0R(i, q) {
        int u, v, a; cin >> u >> v >> a;
        u--, v--;
        vi lhs, rhs;
        int lca = LCA(u, v);
        
        for (int it = LOG-1; it >= 0; it--) {
            if (depth[u] - depth[lca] >= (1 << it)) {
                lhs = merge(lhs, top[u][it]);
                u = par[u][it];
            }
        }
        for (int it = LOG-1; it >= 0; it--) {
            if (depth[v] - depth[lca] >= (1 << it)) {
                rhs = merge(rhs, top[v][it]);
                v = par[v][it];
            }
        }
        
        vi ans = merge(merge(lhs, rhs), top[lca][0]);
        int k = ans.size();
        k = min(k, a);
        cout << k << ' ';
        F0R(i, k) cout << ans[i] + 1 << ' ';
        cout << endl;
    }
}