#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 3030;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

pii dp[N][N];
int g[N];
ll diff[N];
vector<int> adj[N];
int n, m;
pii tmp[N];

pii operator+ (const pii& a, const pii& b) {
    return pii(a.first+b.first, a.second+b.second);
}

void dfs(int u, int p) {
    g[u] = 0;
    dp[u][0] = pii(0, 0);
    for (auto& v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int i=g[u]; i>=0; --i) {
            tmp[i] = dp[u][i];
            dp[u][i] = pii(0, -INFLL);
        }
        for (int i=g[u]; i>=0; --i) {
            for (int j=g[v]; j>=0; --j) {
                dp[u][i+j] = max(dp[u][i+j], tmp[i]+dp[v][j]);
            }
        }
        g[u] += g[v];
    }
    for (int i=g[u]; i>=0; --i) {
        pii spl(dp[u][i].first + (dp[u][i].second+diff[u] > 0), 0);
        dp[u][i+1] = max(dp[u][i+1], spl);
        dp[u][i] = dp[u][i] + pii(0, diff[u]);
    }
    ++g[u];
}

void solve() {
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        adj[i].clear();
        cin >> diff[i];
        for (int j=0; j<=n; ++j) {
            dp[i][j] = pii(0, -INFLL);
            g[i] = 0;
        }
    }
    for (int i=1; i<=n; ++i) {
        int w;
        cin >> w;
        diff[i] = w-diff[i];
    }
    for (int i=0; i<n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    pii pr = dp[1][m-1];
    ll ans = pr.first + (pr.second > 0);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        solve();
    }
    return 0;
}