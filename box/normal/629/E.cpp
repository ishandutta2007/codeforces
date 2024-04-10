//writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

vector<int> elist[100005];
int fa[100005][18];
int dep[100005];
ll rl[100005];
ll sz[100005];

ll tmprl[100005];
ll tmpsz[100005];
ll ael[100005];

void dfs(int node, int par) {
    fa[node][0] = par;
    if(par == -1) dep[node] = 0;
    else dep[node] = dep[par]+1;
    int pt = 0;
    while(fa[node][pt] != -1) {
        fa[node][pt+1] = fa[fa[node][pt]][pt];
        pt++;
    }
    while(pt != 18) fa[node][pt++] = -1;
    rl[node] = 0;
    sz[node] = 1;
    for(int& v:elist[node]) if(v != par) {
        dfs(v, node);
        sz[node] += sz[v];
        rl[node] += rl[v] + sz[v];
    }
}

void dfs2(int node, int par) {
    ael[node] = tmprl[node];
    int ps = tmpsz[node];
    for(int& v:elist[node]) {
        if(v == par) continue;
        tmprl[node] -= tmprl[v] + tmpsz[v];
        tmpsz[node] -= tmpsz[v];
        
        tmprl[v] += tmprl[node] + tmpsz[node];
        tmpsz[v] += tmpsz[node];
        
        dfs2(v, node);

        tmprl[node] = ael[node];
        tmpsz[node] = ps;
    }
}

pii distt(int u, int v) {
    int ans = 0;
    if(dep[u] > dep[v]) swap(u, v);
    for(int cnt=17; cnt>=0; cnt--) {
        if(fa[v][cnt] != -1 && dep[u] <= dep[fa[v][cnt]]) {
            ans += dep[v] - dep[fa[v][cnt]];
            v = fa[v][cnt];
        }
    }
    for(int cnt=17; cnt>=0; cnt--) {
        if(fa[v][cnt] != -1 && fa[u][cnt] != -1 && fa[v][cnt] != fa[u][cnt]) {
            ans += dep[v] - dep[fa[v][cnt]]; v = fa[v][cnt];
            ans += dep[u] - dep[fa[u][cnt]]; u = fa[u][cnt];
        }
    }
    if(v != u) return {fa[v][0], ans+2};
    return {v, ans};
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    rep(i, n-1) {
        int u, v; cin >> u >> v;
        elist[u].pb(v); elist[v].pb(u);
    }
    dfs(1, -1);
    memcpy(tmprl, rl, sizeof tmprl);
    memcpy(tmpsz, sz, sizeof tmpsz);
    dfs2(1, -1);
    rep(i, m) {
        int a, b; cin >> a >> b;
        ll k = distt(a, b).se;
        if(k != abs(dep[a] - dep[b])) {
            long double v1 = rl[a]; v1 /= sz[a];
            long double v2 = rl[b]; v2 /= sz[b];
            cout << fixed << setprecision(12) << 1 + k + v1 + v2 << endl;
        } else {
            if(dep[a] > dep[b]) swap(a, b);
            // a is tol
            int underA = b;
            for(int cnt=17; cnt>=0; cnt--) {
                if(fa[underA][cnt] != -1 && dep[a] < dep[fa[underA][cnt]])
                    underA = fa[underA][cnt];
            }
            long double v1 = (ael[a] - (rl[underA] + sz[underA]));
            v1 /= (n - sz[underA]);
            long double v2 = rl[b]; v2 /= sz[b];
            cout << fixed << setprecision(12) << 1 + k + v1 + v2 << endl;
        }
    }
}