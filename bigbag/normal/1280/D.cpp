#include <bits/stdc++.h>

using namespace std;

const int max_n = 3033, inf = 1000111222;

int t, n, m, a[max_n], sz[max_n];
pair<int, long long> dp[max_n][max_n], tmp[2][max_n];
vector<int> g[max_n];

void dfs(int v, int p) {
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
    }
    int q1 = 0, q2 = 1;
    sz[v] = 1;
    tmp[q1][1] = {0, a[v]};
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        for (int i = 1; i <= sz[v] + sz[to]; ++i) {
            tmp[q2][i] = {-inf, -inf};
        }
        for (int cur = 1; cur <= sz[v]; ++cur) {
            for (int j = 1; j <= sz[to]; ++j) {
                pair<int, long long> upd = tmp[q1][cur];
                upd.first += dp[to][j].first + (dp[to][j].second > 0);
                tmp[q2][cur + j] = max(tmp[q2][cur + j], upd);

                upd.first -= dp[to][j].second > 0;
                upd.second += dp[to][j].second;
                tmp[q2][cur + j - 1] = max(tmp[q2][cur + j - 1], upd);
            }
        }
        swap(q1, q2);
        sz[v] += sz[to];
    }
    copy(tmp[q1] + 1, tmp[q1] + sz[v] + 1, dp[v] + 1);
}

void clr() {
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            a[i] = x - a[i];
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
        printf("%d\n", dp[0][m].first + (dp[0][m].second > 0));
        clr();
    }
    return 0;
}