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

const int max_n = 100111, max_x = 15, mod = 1000000007;

int n, m, k, x, q1, q2, dp[max_n][max_x][2][2], a[2][max_x][2];
vector<int> g[max_n];

void upd(int q, int b, int c, int x) {
    a[q][b][c] += x;
    a[q][b][c] %= mod;
}

void dfs(int v, int p) {
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
        }
    }
    for (int tp = 0; tp < 2; ++tp) {
        q1 = 0;
        q2 = 1;
        memset(a, 0, sizeof(a));
        a[q1][0][0] = 1;
        for (int to : g[v]) {
            if (to != p) {
                for (int i = 0; i <= x; ++i) {
                    memset(a[q2], 0, sizeof(a[q2]));
                }
                for (int i = 0; i <= x; ++i) {
                    for (int tp1 = 0; tp1 < 2; ++tp1) {
                        for (int j = 0; i + j <= x; ++j) {
                            for (int tp2 = 0; tp2 < 2; ++tp2) {
                                upd(q2, i + j, tp1 | tp2, (1LL * a[q1][i][tp1] * dp[to][j][1][tp2]) % mod);
                            }
                        }
                    }
                }
                swap(q1, q2);
            }
        }
        for (int i = 0; i <= x; ++i) {
            for (int tp1 = 0; tp1 < 2; ++tp1) {
                int coef = m - 1;
                if (tp1 || tp == 0) {
                    coef = k - 1;
                }
                dp[v][i][tp][0] += (1LL * coef * a[q1][i][tp1]) % mod;
                dp[v][i][tp][0] %= mod;
            }
        }
    }
    for (int tp = 1; tp < 2; ++tp) {
        q1 = 0;
        q2 = 1;
        memset(a, 0, sizeof(a));
        a[q1][1][0] = 1;
        for (int to : g[v]) {
            if (to != p) {
                for (int i = 0; i <= x; ++i) {
                    memset(a[q2], 0, sizeof(a[q2]));
                }
                for (int i = 0; i <= x; ++i) {
                    for (int tp1 = 0; tp1 < 2; ++tp1) {
                        for (int j = 0; i + j <= x; ++j) {
                            for (int tp2 = 0; tp2 < 1; ++tp2) {
                                upd(q2, i + j, tp1 | tp2, (1LL * a[q1][i][tp1] * dp[to][j][0][tp2]) % mod);
                            }
                        }
                    }
                }
                swap(q1, q2);
            }
        }
        for (int i = 0; i <= x; ++i) {
            for (int tp1 = 0; tp1 < 2; ++tp1) {
                dp[v][i][tp][1] += a[q1][i][tp1];
                dp[v][i][tp][1] %= mod;
            }
        }
    }
    if (0) {
        for (int tp = 0; tp < 2; ++tp) {
            cout << v << " " << tp << ": ";
            for (int i = 0; i <= x; ++i) {
                cout << "(" << dp[v][i][tp][0] << " " << dp[v][i][tp][1] << ") ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int C[max_n];

int solve(int pos = 1) {
    if (pos == n + 1) {
        int f = 1;
        int cnt = 0;
        for (int u = 1; u <= n && f; ++u) {
            if (C[u] == k) {
                ++cnt;
            }
            for (int v : g[u]) {
                if ((C[v] == k && C[u] >= k) || (C[u] == k && C[v] >= k)) {
                    f = 0;
                    break;
                }
            }
        }
        if (cnt > x) {
            f = 0;
        }
        return f;
    }
    int res = 0;
    for (int i = 1; i <= m; ++i) {
        C[pos] = i;
        res += solve(pos + 1);
        res %= mod;
    }
    return res;
}

void clr() {
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        memset(dp[i], 0, sizeof(dp[i]));
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &n, &m) == 2) {
        clr();
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        scanf("%d%d", &k, &x);
        dfs(1, -1);
        int ans = 0;
        for (int i = 0; i <= x; ++i) {
            ans += dp[1][i][1][0];
            ans %= mod;
            ans += dp[1][i][1][1];
            ans %= mod;
        }
        printf("%d\n", ans);
        if (0) {
            int ok = solve();
            cout << ok << endl;
            if (ok != ans) {
                cout << "F" << endl;
                cout << n << " " << m << endl;
                for (int u = 1; u <= n; ++u) {
                    for (int v : g[u]) {
                        if (u < v) cout << u << " " << v << endl;
                    }
                }
                cout << k << " " << x << endl;
                return 0;
            }
        }
    }
    return 0;
}