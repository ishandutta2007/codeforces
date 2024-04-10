#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 222222, inf = 1111111111;

int n, m, a[max_n], dp[2][max_n], ans[2][max_n], f[max_n], used[max_n];
vector<int> g[max_n];
multiset<int> s[max_n];

void dfs(int v) {
    f[v] |= a[v];
    used[v] = 1;
    int res = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i]);
            if (f[g[v][i]]) {
                dp[0][v] += dp[1][g[v][i]] + 2;
                res = max(res, dp[1][g[v][i]] - dp[0][g[v][i]]);
                s[v].insert(dp[1][g[v][i]] - dp[0][g[v][i]]);
                f[v] |= f[g[v][i]];
            }
        }
    }
    if (f[v] == 0) {
        dp[0][v] = dp[1][v] = 0;
        return;
    }
    dp[1][v] = dp[0][v];
    if (dp[0][v]) {
        dp[0][v] -= res + 1;
    }
    //cout << v << " : " << dp[0][v] << " " << dp[1][v] << endl;
}

void dfs2(int v) {
    ans[0][v] = dp[0][v];
    used[v] = 1;
    if (s[v].size() == 0) {
        return;
    }
    int mx = *s[v].rbegin();
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0 && f[g[v][i]]) {
            int kkk = dp[1][g[v][i]] - dp[0][g[v][i]];
            s[v].erase(s[v].find(kkk));
            int k0 = dp[0][v];
            int k1 = dp[1][v];
            if (s[v].size() == 0) {
                dp[0][v] = dp[1][v] = 0;
            } else {
                dp[0][v] -= dp[1][g[v][i]] + 2;
                dp[0][v] += mx;
                dp[1][v] = dp[0][v] + 1;
                dp[0][v] -= *s[v].rbegin();
            }
            //cout << v << " ::: " << dp[0][v] << " " << dp[1][v] << endl;
            if (s[g[v][i]].size()) {
                dp[0][g[v][i]] += *s[g[v][i]].rbegin() + 1;
            }
            if (dp[0][v]) {
                s[g[v][i]].insert(dp[1][v] - dp[0][v]);
                dp[0][g[v][i]] += dp[1][v] + 2;
            } else if (a[v]) {
                s[g[v][i]].insert(dp[1][v] - dp[0][v]);
                dp[0][g[v][i]] += 2;
            }
            dp[1][g[v][i]] = dp[0][g[v][i]];
            if (s[g[v][i]].size()) {
                dp[0][g[v][i]] -= *s[g[v][i]].rbegin() + 1;
            }
            dfs2(g[v][i]);
            dp[0][v] = k0;
            dp[1][v] = k1;
            s[v].insert(kkk);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    while (m--) {
        int x;
        scanf("%d", &x);
        a[x] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        ans[0][i] = inf;
    }
    dfs(1);
    memset(used, 0, sizeof(used));
    dfs2(1);
    int res = inf, poz = -1;
    for (int i = 1; i <= n; ++i) {
        //cout << i << " " << ans[0][i] << endl;
        if (ans[0][i] < res) {
            poz = i;
            res = ans[0][i];
        }
    }
    printf("%d\n%d\n", poz, res);
    return 0;
}