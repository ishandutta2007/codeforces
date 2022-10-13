#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];

        vector<vector<long long>> dp(n, vector<long long>(10, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                long long cost = 1LL * j * b[i];
                if (i == 0) {
                    dp[i][j] = cost;
                } else {
                    long long add = 2e18;
                    for (int k = 0; k < 10; ++k) {
                        if (a[i - 1] + k == a[i] + j) continue;
                        add = min(add, dp[i - 1][k]);
                    }
                    dp[i][j] = cost + add;
                }
            }
        }

        long long ans = 2e18;
        for (int i = 0; i < 10; ++i)
            ans = min(ans, dp[n - 1][i]);
        cout << ans << '\n';
    }


    return 0;
}