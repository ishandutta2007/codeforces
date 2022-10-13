#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
const int kMod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (j == i) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i + 1][j];
            for (int k = i + 1; k < j; ++k) {
                if (v[k + 1] > v[i + 1])
                    dp[i][j] = (dp[i][j] + 
                            1LL * dp[i + 1][k] * dp[k][j]) % kMod;
            }
        }    
    }
    cout << dp[0][n - 1] << endl;


    return 0;
}