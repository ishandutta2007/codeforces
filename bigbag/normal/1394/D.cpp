#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222;
const long long inf = 1000111222000111222LL;

int n, a[max_n], h[max_n];
long long dp[max_n][2];
vector<int> g[max_n];

long long func(int sz, int cnt, int x) {
    return 1LL * x * max(cnt, sz - cnt);
}

void dfs(int v, int p) {
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
    }
    int cnt = 0;
    long long res = 0;
    vector<long long> all;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        if (h[to] == h[v]) {
            res += dp[to][1];
            all.push_back(dp[to][0] - dp[to][1]);
        } else if (h[to] < h[v]) {
            res += dp[to][1];
        } else {
            res += dp[to][0];
            ++cnt;
        }
    }
    sort(all.begin(), all.end());
    dp[v][0] = dp[v][1] = inf;
    for (int i = cnt; i <= cnt + all.size(); ++i) {
        dp[v][0] = min(dp[v][0], res + func(g[v].size(), i, a[v]));
        dp[v][1] = min(dp[v][1], res + func(g[v].size(), i + 1, a[v]));
        if (i < cnt + all.size()) {
            res += all[i - cnt];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &h[i]);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    printf("%I64d\n", dp[0][0]);
    return 0;
}