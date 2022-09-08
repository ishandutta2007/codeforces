#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, dp[max_n][2];
vector<int> g[max_n];
int ans;

int get_sum(const vector<int> &v) {
    if (v.size() >= 2) {
        return v[0] + v[1];
    }
    if (v.size() == 1) {
        return v[0];
    }
    return 0;
}

void dfs(int v, int p) {
    dp[v][0] = 0;
    dp[v][1] = 0;
    int cnt = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
        dp[v][0] = max(dp[v][0], dp[to][1]);
        dp[v][1] = max(dp[v][1], max(dp[to][0], dp[to][1]));
        ++cnt;
    }
    if (cnt) {
        dp[v][1] += cnt - 1;
    }
    ++dp[v][0];
    vector<int> all;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        all.push_back(dp[to][1]);
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    ans = max(ans, 1 + get_sum(all));
    ans = max(ans, dp[v][1]);
    if (cnt >= 2) {
        all.clear();
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            all.push_back(max(dp[to][0], dp[to][1]));
        }
        sort(all.begin(), all.end());
        reverse(all.begin(), all.end());
        ans = max(ans, (int) g[v].size() - 2 + get_sum(all));
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int root = 0; root < n; ++root) {
        ans = 0;
        dfs(root, -1);
        printf("%d\n", ans);
        return 0;
    }
    return 0;
}