/**
 *  created: 12/06/2022, 18:45:48
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, mod = 998244353, inf = 1000111222;

void inc(int &x, int y) {
    x += y;
    x %= mod;
}

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int n, x[max_n], y[max_n], d[max_n][max_n], mn[max_n], used[max_n];
int cv, ce, q1 = 0, q2 = 1, dp[2][max_n], c[max_n][max_n];
bool bad;

void dfs(int v) {
    ++cv;
    used[v] = 1;
    for (int i = 0; i < n; ++i) {
        if (d[v][i] == mn[v]) {
            ++ce;
            if (d[i][v] != mn[i]) {
                bad = 1;
            } else if (!used[i]) {
                dfs(i);
            }
        }
    }
}

void proc(int d) {
    for (int i = 0; i + d < max_n; ++i) {
        inc(dp[q2][i + d], dp[q1][i]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        }
        d[i][i] = inf;
        mn[i] = *min_element(d[i], d[i] + n);
    }
    dp[q1][0] = 1;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            memset(dp[q2], 0, sizeof(dp[q2]));
            cv = 0;
            ce = 0;
            bad = 0;
            dfs(i);
            proc(cv);
            if (!bad && ce == cv * (cv - 1) && cv != 1) {
                proc(1);
            }
            swap(q1, q2);
        }
    }
    for (int i = 0; i < max_n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
    int ans = 0, f = 1;
    for (int i = 1; i <= n; ++i) {
        f = mul(f, i);
        inc(ans, mul(c[n][i], mul(f, dp[q1][i])));
    }
    cout << ans << endl;
    return 0;
}