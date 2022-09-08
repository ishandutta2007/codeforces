#include <bits/stdc++.h>

using namespace std;

const int max_n = 4044, max_k = 77, mod = 998244353;

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int n[2], k, ans[max_n], used[max_n], sz[max_n];
int c[max_k][max_k], dp[2][max_n][max_k];
vector<int> G[2][max_n], g[max_n], all;

void calc_sz(int v, int p) {
    all.push_back(v);
    sz[v] = 1;
    memset(dp[0][v], 0, sizeof(dp[0][v]));
    memset(dp[1][v], 0, sizeof(dp[1][v]));
    for (int to : g[v]) {
        if (to != p && used[to] == 0) {
            calc_sz(to, v);
            sz[v] += sz[to];
        }
    }
}

int find_root(int v, int p) {
    int mx = all.size() - sz[v];
    for (int to : g[v]) {
        if (to != p && used[to] == 0) {
            int root = find_root(to, v);
            if (root != -1) {
                return root;
            }
            mx = max(mx, sz[to]);
        }
    }
    if (all.size() >= 2 * mx) {
        return v;
    }
    return -1;
}

void calc_dp(int dp[max_n][max_k], int forbidden) {
    for (int len = 0; len < k; ++len) {
        for (int cur : all) {
            for (int to : g[cur]) {
                if (used[to] || to == forbidden) {
                    continue;
                }
                dp[to][len + 1] += dp[cur][len];
                dp[to][len + 1] %= mod;
            }
        }
    }
}

void rec(int v) {
    all.clear();
    calc_sz(v, -1);
    v = find_root(v, -1);
    dp[0][v][0] = dp[1][v][0] = 1;
    calc_dp(dp[0], v);
    calc_dp(dp[1], -1);
    for (int v : all) {
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; i + j <= k; ++j) {
                ans[i + j] += mul(dp[0][v][i], dp[1][v][j]);
                ans[i + j] %= mod;
            }
        }
    }
    used[v] = 1;
    for (int to : g[v]) {
        if (used[to] == 0) {
            rec(to);
        }
    }
}

vector<int> solve(int tp) {
    memset(ans, 0, sizeof(ans));
    memset(used, 0, sizeof(used));
    for (int i = 1; i <= n[tp]; ++i) {
        g[i] = G[tp][i];
    }
    rec(1);
    vector<int> res(ans, ans + k + 1);
    return res;
}

void get_all_c() {
    c[0][0] = 1;
    for (int i = 1; i < max_k; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n[0] >> n[1] >> k;
    for (int tp = 0; tp < 2; ++tp) {
        for (int i = 1; i < n[tp]; ++i) {
            int u, v;
            cin >> u >> v;
            G[tp][u].push_back(v);
            G[tp][v].push_back(u);
        }
    }
    vector<int> a = solve(0);
    vector<int> b = solve(1);
    get_all_c();
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans += mul(a[i], mul(b[k - i], c[k][i]));
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}