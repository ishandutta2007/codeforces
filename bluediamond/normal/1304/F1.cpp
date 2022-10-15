#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 50 + 7;
const int M = (int) 2e4 + 7;
const int INF = (int) 1e9;
int n, m, k, a[N][M], dp[N][M], prefix[N][M], pm[M], sm[M];

int sum(int i, int l, int r) {
    return prefix[i][r] - prefix[i][l - 1];
}

struct segTree {
    int t[4 * M];
    void make(int v, int tl, int tr, int p, int x) {
        if (tr < p || p < tl)
            return;
        if (tl == tr)
            t[v] = x;
        else {
            int tm = (tl + tr) / 2;
            make(2 * v, tl, tm, p, x);
            make(2 * v + 1, tm + 1, tr, p, x);
            t[v] = max(t[2 * v], t[2 * v + 1]);
        }
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (tr < l || r < tl)
            return -INF;
        if (l <= tl && tr <= r)
            return t[v];
        else {
            int tm = (tl + tr) / 2;
            return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
        }
    }
    void make(int p, int x) {
        make(1, 1, m, p, x);
    }
    int get(int l, int r) {
        return get(1, 1, m, l, r);
    }
};

segTree x, y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            prefix[i][j] = prefix[i][j - 1] + a[i][j];
        }
    m = m - k + 1;
    for (int l = 1; l <= m; l++) {
        int r = l + k - 1;
        dp[1][l] = sum(1, l, r) + sum(2, l, r);
    }
    for (int l = 1; l <= m; l++)
        pm[l] = max(pm[l - 1], dp[1][l]);
    for (int l = m; l >= 1; l--)
        sm[l] = max(sm[l + 1], dp[1][l]);
    for (int l = 1; l <= m; l++) {
        int i = 1;
        x.make(l, dp[i][l] - prefix[i + 1][l + k - 1]);
        y.make(l, dp[i][l] + prefix[i + 1][l - 1]);
    }
    for (int i = 2; i <= n; i++) {
        for (int l = 1; l <= m; l++) {
            int r = l + k - 1, go = max(l - k + 1, 1);
            dp[i][l] = max(dp[i][l], x.get(go, l) + prefix[i][l - 1]);
            dp[i][l] = max(dp[i][l], y.get(l, r) - prefix[i][r]);
            dp[i][l] = max(dp[i][l], pm[go - 1]);
            dp[i][l] = max(dp[i][l], sm[r + 1]);
            dp[i][l] += sum(i, l, r) + sum(i + 1, l, r);
        }
        for (int l = 1; l <= m; l++)
            pm[l] = max(pm[l - 1], dp[i][l]);
        for (int l = m; l >= 1; l--)
            sm[l] = max(sm[l + 1], dp[i][l]);
        for (int l = 1; l <= m; l++) {
            x.make(l, dp[i][l] - prefix[i + 1][l + k - 1]);
            y.make(l, dp[i][l] + prefix[i + 1][l - 1]);
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; j++)
        ans = max(ans, dp[n][j]);
    cout << ans << "\n";
}