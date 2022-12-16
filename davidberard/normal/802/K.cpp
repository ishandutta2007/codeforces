#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 100100;

ll dp[N][2];
vector<pii> adj[N];
int n, k;

void dfs(int u, int p) {
    set<pii> s;
    for (auto& pr : adj[u]) {
        int v = pr.first;
        if (v == p) continue;
        dfs(v, u);
        ll w = pr.second;
        s.insert(pii(w+dp[v][0], v));
    }
    dp[u][0] = 0;
    int i = 0;
    for (auto it=s.rbegin(); it != s.rend() && i < k-1; ++it) {
        dp[u][0] += it->first;
        ++i;
    }
    dp[u][1] = dp[u][0];
    //cerr << " ! dp " << u << " " << 0 << " = " << dp[u][0] << endl;
    //if (k%2 == 0) return;

    ll sum = 0;
    i = 0;
    for (auto it=s.rbegin(); it != s.rend() && i < k; ++it) {
        sum += it->first;
        i++;
    }
    i = 0;
    for (auto it=s.rbegin(); it != s.rend() && i < k; ++it) {
        int v = it->second;
        dp[u][1] = max(dp[u][1], sum + dp[v][1] - dp[v][0]);
        ++i;
    }
    i = 0;
    for (auto it=s.rbegin(); it != s.rend(); ++it) {
        if (i < k) {
            ++i;
            continue;
        }
        int v = it->second;
        dp[u][1] = max(dp[u][1], dp[u][0] + it->first - dp[v][0] + dp[v][1]);
        ++i;
    }
    //cerr << " ! dp " << u << " " << 1 << " = " << dp[u][1] << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i=0; i<n-1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dfs(0, -1);
    cout << dp[0][1] << "\n";
    return 0;
}