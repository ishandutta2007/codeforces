#include <bits/stdc++.h>

using namespace std;

const int max_n = 222, mod = 1000000007;

int n, p[max_n], to[max_n][2];
string s;

void get_prefix_function(const string &s, int p[]) {
    p[0] = 0;
    for (int i = 1; i < s.length(); ++i) {
        p[i] = p[i - 1];
        while (p[i] > 0 && s[i] != s[p[i]]) {
            p[i] = p[p[i] - 1];
        }
        if (s[i] == s[p[i]]) {
            ++p[i];
        }
    }
}

int calc_all() {
    int dp[max_n][max_n];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < 2 * n; ++i) {
        for (int bal = 0; bal <= i; ++bal) {
            dp[i + 1][bal + 1] += dp[i][bal];
            dp[i + 1][bal + 1] %= mod;
            if (bal) {
                dp[i + 1][bal - 1] += dp[i][bal];
                dp[i + 1][bal - 1] %= mod;
            }
        }
    }
    return dp[2 * n][0];
}

int calc_bad() {
    int dp[max_n][max_n][max_n];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 0; i < 2 * n; ++i) {
        for (int bal = 0; bal <= i; ++bal) {
            for (int cnt = 0; cnt < s.length(); ++cnt) {
                for (int tp = 0; tp < 2; ++tp) {
                    int nbal = bal;
                    if (tp == 0) {
                        ++nbal;
                    } else {
                        --nbal;
                    }
                    if (nbal >= 0) {
                        dp[i + 1][nbal][to[cnt][tp]] += dp[i][bal][cnt];
                        dp[i + 1][nbal][to[cnt][tp]] %= mod;
                    }
                }
            }
        }
    }
    int res = 0;
    for (int cnt = 0; cnt < s.length(); ++cnt) {
        res += dp[2 * n][0][cnt];
        res %= mod;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    get_prefix_function(s, p);
    for (int cnt = 0; cnt < s.length(); ++cnt) {
        for (int tp = 0; tp < 2; ++tp) {
            char c = '(' + tp;
            int cur = cnt;
            while (cur && s[cur] != c) {
                cur = p[cur - 1];
            }
            if (s[cur] == c) {
                ++cur;
            }
            to[cnt][tp] = cur;
        }
    }
    int all = calc_all();
    int bad = calc_bad();
    int ans = (all + mod - bad) % mod;
    cout << ans << endl;
    return 0;
}