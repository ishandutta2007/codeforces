#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<int> dp(k + 1, 0), nxt(dp);
    dp[0] = m;
    for (int i = 1; i < n; ++i) {
        fill(nxt.begin(), nxt.end(), 0);
        for (int j = 0; j <= k; ++j) {
            dp[j] %= 998244353;
            if (j < k) 
                nxt[j + 1] += 1LL * dp[j] * (m - 1) % 998244353;
            nxt[j] += dp[j];
        }
        swap(dp, nxt);
    }

    cout << dp[k] % 998244353 << endl;
    return 0;
}