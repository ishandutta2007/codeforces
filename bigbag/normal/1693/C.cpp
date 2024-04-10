/**
 *  created: 16/06/2022, 18:11:55
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, m, dp[max_n], mx[max_n], bad[max_n];
vector<int> rg[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        ++bad[u];
        rg[v].push_back(u);
    }
    fill(dp, dp + n, inf);
    fill(mx, mx + n, inf);
    dp[n - 1] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, n - 1});
    while (!q.empty()) {
        auto [val, v] = q.top();
        q.pop();
        val *= -1;
        if (val != dp[v]) {
            continue;
        }
        for (int u : rg[v]) {
            --bad[u];
            if (dp[u] > 1 + dp[v] + bad[u]) {
                dp[u] = 1 + dp[v] + bad[u];
                q.push({-dp[u], u});
            }
        }
    }
    cout << dp[0] << "\n";
    return 0;
}