#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 200200;

int k;
vector<pii> adj[N];
int n;

pii dp[N]; // pairity, cost
int sz[N];

ll B;

void dfs(int u, int p, ll d) {
    dp[u] = pii(1, 0);
    sz[u] = 1;
    for (auto& pr : adj[u]) {
        int v = pr.first;
        ll w = pr.second;
        if (v == p) continue;
        dfs(v, u, d+w);
        sz[u] += sz[v];
        if (dp[v].first) {
            dp[u].first++;
            dp[u].second += w + dp[v].second;
        } else {
            dp[u].second += dp[v].second;
        }
    }
    dp[u].first%=2;
    for (auto& pr : adj[u]) {
        int v = pr.first;
        ll w = pr.second;
        if (v == p) continue;
        B += min(sz[v], n-sz[v])*w;
    }
    //cerr << " : " << u << " : " << in[u] << " " << out[u] << endl;
}

void solve() {
    B = 0;
    cin >> k;
    n = k*2;
    for (int i=1; i<=n; ++i) {
        adj[i].clear();
    }
    for (int i=0; i<n-1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dfs(1, 0, 0);

    cout << dp[1].second << " " << B << endl;
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