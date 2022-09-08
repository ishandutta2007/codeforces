#include <bits/stdc++.h>

using namespace std;

const int max_n = 150555, inf = 1000111222;
const int max_c = 27;

int n, q, p[max_n], num[max_n], lev[max_n], up[max_n], nxt[max_n], dp[max_n][max_c];
int sum[max_n][max_c];
char c[max_n];
bool bad[max_n];
vector<int> g[max_n];
vector<char> let[max_n];

bool check_height() {
    int last = -1;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 0) {
            if (last == -1) {
                last = lev[i];
            } else if (last != lev[i]) {
                return false;
            }
        }
    }
    return true;
}

void upd_sz2(int i) {
    int need[2] = {0, 0};
    for (int j = 0; j + 1 < max_c; ++j) {
        int val0 = dp[g[i][0]][j] + ('a' + j == let[i][0]);
        int val1 = dp[g[i][1]][j] + ('a' + j == let[i][1]);
        dp[i][j] = max(val0, val1);
        need[0] += dp[i][j] - val0;
        need[1] += dp[i][j] - val1;
    }
    int q0 = dp[g[i][0]][max_c - 1] + ('{' == let[i][0]);
    int q1 = dp[g[i][1]][max_c - 1] + ('{' == let[i][1]);
    if (need[0] <= q0 && need[1] <= q1) {
        assert(q0 - need[0] == q1 - need[1]);
        bad[i] = false;
        dp[i][max_c - 1] = q0 - need[0];
        dp[i][max_c - 1] = min(q0 - need[0], q1 - need[1]);
    } else {
        bad[i] = true;
    }
}

void get_dp() {
    for (int i = n; i >= 1; --i) {
        bad[i] = false;
        for (int j = 0; j < g[i].size(); ++j) {
            if (bad[g[i][j]]) {
                bad[i] = true;
            }
        }
        if (bad[i]) {
            continue;
        }
        if (g[i].empty()) {
        } else if (g[i].size() == 1) {
            for (int j = 0; j < max_c; ++j) {
                dp[i][j] = dp[g[i][0]][j];
            }
            ++dp[i][let[i][0] - 'a'];
        } else {
            upd_sz2(i);
        }
        //cout << i << ": " << dp[i][0] << " " << dp[i][1] << " " << dp[i][max_c - 1] << ", bad = " << bad[i] << endl;
    }
}

void upd(int v, char nc) {
    if (up[v] != v) {
        --sum[up[v]][let[p[v]][num[v]] - 'a'];
    }
    let[p[v]][num[v]] = nc;
    if (up[v] != v) {
        ++sum[up[v]][let[p[v]][num[v]] - 'a'];
    }
    while (v != 1) {
        if (up[v] != v) {
            v = up[v];
            if (bad[nxt[v]]) {
                bad[v] = true;
            } else {
                bad[v] = false;
                for (int j = 0; j < max_c; ++j) {
                    dp[v][j] = sum[v][j] + dp[nxt[v]][j];
                }
            }
        } else {
            v = p[v];
            bad[v] = false;
            for (int j = 0; j < g[v].size(); ++j) {
                if (bad[g[v][j]]) {
                    bad[v] = true;
                }
            }
            if (!bad[v]) {
                upd_sz2(v);
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; ++i) {
        scanf("%d %c", &p[i], &c[i]);
        if (c[i] == '?') {
            c[i] = '{';
        }
        num[i] = g[p[i]].size();
        g[p[i]].push_back(i);
        let[p[i]].push_back(c[i]);
    }
    up[1] = 1;
    for (int i = 2; i <= n; ++i) {
        lev[i] = lev[p[i]] + 1;
        if (g[p[i]].size() == 2) {
            up[i] = i;
        } else {
            up[i] = up[p[i]];
        }
        if (i != up[i]) {
            ++sum[up[i]][c[i] - 'a'];
        }
    }
    if (!check_height()) {
        for (int i = 0; i < q; ++i) {
            puts("Fou");
        }
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 2) {
            nxt[up[i]] = i;
        }
    }
    get_dp();
    while (q--) {
        int v;
        char c;
        scanf("%d %c", &v, &c);
        if (c == '?') {
            c = '{';
        }
        upd(v, c);
        if (bad[1]) {
            puts("Fou");
            continue;
        }
        int ans = 0;
        for (int i = 0; i + 1 < max_c; ++i) {
            ans += (i + 1) * (dp[1][max_c - 1] + dp[1][i]);
        }
        printf("Shi %d\n", ans);
    }
    return 0;
}