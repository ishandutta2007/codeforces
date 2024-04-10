#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 100100;

struct edge {
    int a, b, c, i;
    edge() {}
    edge(int w, int x, int y, int z) : a(w), b(x), c(y), i(z) {}
    bool operator < (const edge& o) const {
        return c < o.c;
    }
};

int par[N];
int sz[N];
vector<edge> adj[N];
int sub[N];
ll ans[N];
int vis[N];
int n;

void setup() {
    for (int i=0; i<N; ++i) {
        sz[i] = 1;
        par[i] = -1;
    }
}

int FIND(int u) {
    if (par[u] == -1) return u;
    return par[u] = FIND(par[u]);
}

void UNION(int u, int v) {
    ////cerr << " UNION " << u << " " << v << endl;
    assert(FIND(u) != FIND(v));
    sz[FIND(v)] += sz[FIND(u)];
    sz[FIND(u)] = 0;
    par[FIND(u)] = FIND(v);
}

void dfs_build(int u, int p) {
    vis[u] = 1;
    sub[u] = sz[u];
    for (auto& e : adj[u]) {
        int v = e.b;
        if (v == p) continue;
        dfs_build(v, u);
        sub[u] += sub[v];
    }
}

void dfs_calc(int u, int p, int psz) {
    for (auto& e : adj[u]) {
        int v = e.b;
        if (v == p) continue;
        int z = psz + sub[u] - sub[v];
        dfs_calc(v, u, z);
        ans[e.i] = (ll) z * sub[v];
    }
}

void dfs_clean(int u, int p) {
    for (auto& e : adj[u]) {
        int v = e.b;
        if (v == p) continue;
        dfs_clean(v, u);
        UNION(u, v);
    }
    adj[u].clear();
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    cin >> n;
    vector<edge> edges;
    for (int i=1; i<=n-1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c, i);
    }
    sort(edges.begin(), edges.end());
    
    for (int i=0; i<edges.size(); ++i) {
        int ii = i;
        int j=i;
        for (; j<edges.size() && edges[i].c == edges[j].c; ++j) {
            vis[FIND(edges[j].a)] = 0;
            vis[FIND(edges[j].b)] = 0;
            adj[FIND(edges[j].a)].emplace_back(FIND(edges[j].a), FIND(edges[j].b), edges[j].c, edges[j].i);
            adj[FIND(edges[j].b)].emplace_back(FIND(edges[j].b), FIND(edges[j].a), edges[j].c, edges[j].i);
        }

        for (int k=ii; k<j; ++k) {
            if (!vis[FIND(edges[k].a)]) {
                dfs_build(FIND(edges[k].a), -1);
                dfs_calc(FIND(edges[k].a), -1, 0);
                dfs_clean(FIND(edges[k].a), -1);
            }
        }
        i = j-1;
    }

    pair<ll, vector<int>> best(-1, vector<int>());    

    for (int i=1; i<n; ++i) {
        if (ans[i] > best.first) {
            best = pair<ll, vector<int>>(ans[i], vector<int>({i}));
        } else if (ans[i] == best.first) {
            best.second.push_back(i);
        }
    }
    cout << best.first*2 << " " << best.second.size() << "\n";
    for (auto& x : best.second) {
        cout << x << " ";
    }
    cout << "\n";

    //cerr; for(int i=1; i<=n; ++i) //cerr << " " << i << ": " << adj[i].size() << endl;

    return 0;
}