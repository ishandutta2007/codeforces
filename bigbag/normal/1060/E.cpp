#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n;
long long ans, sz[max_n], dp[max_n], sum_dp[max_n];
vector<int> g[max_n];

void dfs(int v, int p) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
            sum_dp[v] += dp[to];
            sz[v] += sz[to];
            dp[v] += sum_dp[to] + sz[to];
        }
    }

}

void calc(int v, int p) {
    //cout << v << " " << dp[v] << endl;
    ans += dp[v];
    for (int to : g[v]) {
        if (to != p) {
            sum_dp[v] -= dp[to];
            sz[v] -= sz[to];
            dp[v] -= sum_dp[to] + sz[to];

            sum_dp[to] += dp[v];
            sz[to] += sz[v];
            dp[to] += sum_dp[v] + sz[v];
            calc(to, v);
            sum_dp[to] -= dp[v];
            sz[to] -= sz[v];
            dp[to] -= sum_dp[v] + sz[v];

            sum_dp[v] += dp[to];
            sz[v] += sz[to];
            dp[v] += sum_dp[to] + sz[to];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    calc(1, -1);
    cout << ans / 2 << "\n";
    return 0;
}