#include <bits/stdc++.h>

using namespace std;

const int max_n = 1502, inf = 1000111222, mod = 998244353;
const int max_lev = 11;

template<typename T, int z = 1>
struct sparse_table {
    int num[max_n];
    T mn[max_lev][max_n];

    void init(int n, T a[]) {
        for (int i = 0; i < n; ++i) {
            mn[0][i] = z * a[i];
        }
        for (int i = 1; i < max_lev; ++i) {
            for (int j = 0; j < n && j + (1 << (i - 1)) < n; ++j) {
                mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            }
        }
        for (int i = 1, x = 0; i <= n; i *= 2, ++x) {
            for (int j = i; j <= n && j < i * 2; ++j) {
                num[j] = x;
            }
        }
    }

    T get_min(int l, int r) const {
        if (l > r) {
            return z * inf;
        }
        int lev = num[r - l + 1];
        return z * min(mn[lev][l], mn[lev][r - (1 << lev) + 1]);
    }
};

int n, A[max_n][max_n], a[max_n][max_n], dist[max_n], p[max_n], used[max_n];
int mn[max_n][max_n], mx[max_n][max_n], dp[max_n][max_n];
sparse_table<int> mns[max_n];
sparse_table<int, -1> mxs[max_n];
vector<int> g[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    copy(A[0], A[0] + n, dist);
    p[0] = 0;
    used[0] = 1;
    for (int i = 1; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!used[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }
        used[v] = 1;
        p[i] = v;
        for (int j = 0; j < n; ++j) {
            dist[j] = min(dist[j], A[v][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = A[p[i]][p[j]];
            mn[i][j] = inf;
            mx[i][j] = -inf;
        }
    }
    for (int i = 0; i < n; ++i) {
        mns[i].init(n, a[i]);
        mxs[i].init(n, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        int cur_mx = 0, cur_mn = inf;
        for (int j = i; j < n; ++j) {
            cur_mx = max(cur_mx, mxs[j].get_min(i, j));
            cur_mn = min(cur_mn, mns[j].get_min(0, i - 1));
            mx[i][j] = cur_mx;
            mn[i][j] = min(mn[i][j], cur_mn);
        }
    }
    for (int i = 0; i < n; ++i) {
        int cur_mn = inf;
        for (int j = i; j >= 0; --j) {
            cur_mn = min(cur_mn, mns[j].get_min(i + 1, n - 1));
            mn[j][i] = min(mn[j][i], cur_mn);
        }
    }
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (mx[i][j] < mn[i][j]) {
                g[i].push_back(j + 1);
                ++tot;
            }
        }
    }
    assert(tot <= 2 * n);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int cnt = 0; cnt <= i; ++cnt) {
            if (!dp[i][cnt]) {
                continue;
            }
            for (int to : g[i]) {
                dp[to][cnt + 1] += dp[i][cnt];
                dp[to][cnt + 1] %= mod;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", dp[n][i]);
    }
    puts("");
    return 0;
}