#include <bits/stdc++.h>
using namespace std;

const int N = 210000;

int p[N];
vector<int> adj[N];
int f[3], g[3], dp[N][3];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    const int P = 998244353;
    function<void(int)> dfs = [&](int u) {
        for (int v : adj[u]) dfs(v);
        if (adj[u].empty()) {
            dp[u][2] = 1;
            dp[u][1] = 0;
            dp[u][0] = 0;
            return;
        }
        f[1] = f[2] = 0, f[0] = 1;
        for (int v : adj[u]) {
            for (int j = 0; j < 3; j++) g[j] = 0;
            g[0] = f[0] * 1LL * (dp[v][0] + dp[v][2]) % P;
            g[1] = (f[1] * 1LL * (dp[v][0] + dp[v][2]) + 1LL * f[0] * (dp[v][1] + dp[v][2])) % P;
            g[2] = (1LL * f[1] * (dp[v][1] + dp[v][2]) + 1LL * f[2] * (dp[v][0] + dp[v][1] + 2LL * dp[v][2])) % P;
            for (int j = 0; j < 3; j++) f[j] = g[j];
        }
        dp[u][0] = f[0];
        dp[u][1] = f[1];
        dp[u][2] = f[2];
    };
    dfs(1);
    cout << (dp[1][0] + dp[1][2]) % P << endl;
    return 0;
}