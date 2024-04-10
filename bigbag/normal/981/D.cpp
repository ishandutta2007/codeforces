#include <bits/stdc++.h>

using namespace std;

const int max_n = 53, inf = 1000111222;

int n, k;
char dp[max_n][max_n];
long long a[max_n], ans;

void get_dp() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (dp[i][j]) {
                long long sum = 0;
                for (int to = i; to < n; ++to) {
                    sum += a[to];
                    if ((sum & ans) == ans) {
                        dp[to + 1][j + 1] = 1;
                    }
                }
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 62; i >= 0; --i) {
        ans += (1LL << i);
        get_dp();
        if (dp[n][k] == 0) {
            ans -= (1LL << i);
        }
    }
    cout << ans << endl;
    return 0;
}