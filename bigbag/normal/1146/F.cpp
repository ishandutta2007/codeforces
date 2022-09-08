#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, mod = 998244353;

int n, dp[max_n], dp2[max_n];
vector<int> g[max_n];

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

void dfs(int v) {
    if (g[v].empty()) {
        dp[v] = dp2[v] = 1;
        return;
    }
    dp[v] = 1;
    vector<int> pr(g[v].size()), suf(g[v].size());
    for (int to : g[v]) {
        dfs(to);
        dp[v] = mul(dp[v], dp[to] + dp2[to]);
    }
    for (int i = 0; i < g[v].size(); ++i) {
        pr[i] = dp[g[v][i]];
        if (i) {
            pr[i] = mul(pr[i - 1], pr[i]);
        }
    }
    for (int i = g[v].size() - 1; i >= 0; --i) {
        suf[i] = dp[g[v][i]];
        if (i + 1 < g[v].size()) {
            suf[i] = mul(suf[i], suf[i + 1]);
        }
    }
    for (int i = 0; i < g[v].size(); ++i) {
        int c = dp2[g[v][i]];
        if (i) {
            c = mul(c, pr[i - 1]);
        }
        if (i + 1 < g[v].size()) {
            c = mul(c, suf[i + 1]);
        }
        dp[v] += mod - c;
        dp[v] %= mod;
    }

    dp2[v] = 1;
    for (int to : g[v]) {
        dp2[v] = mul(dp2[v], (dp[to] + dp2[to]));
    }
    dp2[v] = (dp2[v] + mod - pr.back()) % mod;
    //cout << v << ": " << dp[v] << " " << dp2[v] << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int p;
        scanf("%d", &p);
        --p;
        g[p].push_back(i);
    }
    dfs(0);
    printf("%d\n", dp[0]);
    return 0;
}