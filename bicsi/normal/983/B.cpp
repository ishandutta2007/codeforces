#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> low_bit(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        int lg = -1;
        for (int auxx = i; auxx; auxx /= 2)
            lg += 1;

        low_bit[i] = i - (1 << lg);
//        cerr << i << " -> " << low_bit[i] << endl;
    }  

    vector<vector<int>> dp(n, vector<int>(n, 0)); 
    for (int i = n - 1; i >= 0; --i) {
        dp[i][i] = a[i];
        for (int j = i + 1; j < n; ++j) {
            int len = j - i;
            int low = low_bit[len];
            dp[i][j] = dp[i][i + low] ^ dp[j - low][j];
        } 
    }  
/*
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    } 
*/
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            dp[i][j] = max(dp[i][j], dp[i + 1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }    
    }


    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r; --l; --r;
        cout << dp[l][r] << '\n';
    }

    return 0;
}