#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, mod = 998244353;

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int n, dp[max_n], sz[max_n], f[max_n];
vector<int> g[max_n];

const int root = 0;

void dfs(int v, int p) {
    sz[v] = 1;
    dp[v] = 1;
    int cnt = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        ++cnt;
        dfs(to, v);
        sz[v] += sz[to];
        dp[v] = mul(dp[v], dp[to]);
    }
    //dp[v] = mul(dp[v], sz[v]);
    dp[v] = mul(dp[v], f[cnt]);
    if (v != root) {
        dp[v] = mul(dp[v], cnt + 1);
    }
    //cout << v << ": " << dp[v] << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    f[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = mul(f[i - 1], i);
    }
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(root, -1);
    printf("%d\n", mul(n, dp[root]));
    return 0;
}