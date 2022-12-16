#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int N = 200200;

int sz[N];
int vis[N];
int cnt[1<<21];
ll ans[N];
char label[N];
int path[N];
vector<int> adj[N];

void dfs_sz(int u, int p) {
    sz[u] = 1;
    for (auto& v : adj[u]) {
        if (v != p && !vis[v]) {
            dfs_sz(v, u);
            sz[u] += sz[v];
        }
    }
}

int dfs_centroid(int u, int p, int n) {
    for (auto& v : adj[u]) {
        if (v != p && !vis[v]) {
            if (sz[v] > n/2) {
                return dfs_centroid(v, u, n);
            }
        }
    }
    return u;
}

void dfs_path(int u, int p, int cur) {
    cur ^= 1<<(label[u]-'a');
    path[u] = cur;
    //cerr << "   path " << u << " = " << path[u] << endl;
    for (auto& v : adj[u]) {
        if (v != p && !vis[v]) {
            dfs_path(v, u, cur);
        }
    }
}

void dfs_count(int u, int p, int dir) {
    cnt[path[u]] += dir;
    for (auto& v : adj[u]) {
        if (v != p && !vis[v]) {
            dfs_count(v, u, dir);
        }
    }
}

ll dfs_pass(int u, int p, int extra) {
    int pa = path[u]^extra;
    ll through = cnt[pa];
    for (int i=0; i<20; ++i) {
        through += cnt[pa^(1<<i)];
    }
    //cerr << "  got " << through << " from " << u << endl;
    for (auto& v : adj[u]) {
        if (v != p && !vis[v]) {
            through += dfs_pass(v, u, extra);
        }
    }
    ans[u] += through;
    return through;
}

void solve(int r) {
    dfs_path(r, -1, 0);
    dfs_count(r, -1, 1);
    ll for_r = 0;
    for (auto& v : adj[r]) {
        if (!vis[v]) {
            dfs_count(v, r, -1);
            for_r += dfs_pass(v, r, path[r]);
            dfs_count(v, r, 1);
        }
    }
    //cerr << "    (before " << for_r << ")" << endl;
    for_r += cnt[0];
    //cerr << "    from 0diff " << cnt[0] << endl;
    for (int i=0; i<20; ++i) {
        //cerr << "    from " << i << "diff " << cnt[(1<<i)] << endl;
        for_r += cnt[1<<i];
    }
    ++for_r;
    //cerr << "  for_r = " << for_r << " -> " << for_r/2 << endl;
    for_r /= 2;
    ans[r] += for_r;
    dfs_count(r, -1, -1);
}

void dfs_run(int u) {
    dfs_sz(u, -1);
    int r = dfs_centroid(u, -1, sz[u]);
    //cerr << " from " << u << " centroid " << r << endl;
    solve(r);
    vis[r] = 1;
    for (auto& v : adj[r]) {
        if (!vis[v]) {
            dfs_run(v);
        }
    }
}

int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i=0; i<n-1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> (label+1);
    //cerr << (label+1) << endl;
    dfs_run(1);
    for (int i=1; i<=n; ++i) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}