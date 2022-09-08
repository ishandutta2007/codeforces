#include <bits/stdc++.h>

using namespace std;

const int max_n = 505, mod = 998244353, inf = 1000111222;

int n, m, a[max_n], mn[max_n][max_n], dp[max_n][max_n];

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int get_dp(int l, int r) {
    return dp[r - l + 1][l];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int l = 0; l < n; ++l) {
        int x = inf, pos = inf;
        for (int r = l; r <= n; ++r) {
            if (x > a[r]) {
                x = a[r];
                pos = r;
            }
            mn[l][r] = pos;
        }
        dp[0][l] = 1;
    }
    dp[0][n] = 1;
    for (int len = 1; len <= n; ++len) {
        for (int L = 0; L + len <= n; ++L) {
            const int R = L + len - 1;
            int pos = mn[L][R];
            int cl = 0, cr = 0;
            for (int l = L; l <= pos; ++l) {
                cl += mul(get_dp(L, l - 1), get_dp(l, pos - 1));
                cl %= mod;
            }
            for (int r = pos; r <= R; ++r) {
                cr += mul(get_dp(pos + 1, r), get_dp(r + 1, R));
                cr %= mod;
            }
            dp[len][L] = mul(cl, cr);
            //cout << L << " " << R << ": " << dp[len][L] << endl;
        }
    }
    printf("%d\n", dp[n][0]);
    return 0;
}