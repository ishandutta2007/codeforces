#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define maxn 101010
#define mod ((long)1e9 + 7)

long dp[maxn] = {0}, sum[maxn] = {0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; long k; cin >> t >> k;
    dp[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        dp[i] = dp[i - 1];
        if (i >= k) dp[i] = (dp[i] + dp[i - k]) % mod;
        sum[i] = (sum[i - 1] + dp[i]) % mod;
        //clog << i << ' ' << dp[i] << ' ' << sum[i] << endl;
    }
    while (t--) {
        int l, r; cin >> l >> r;
        long ans = (sum[r] - sum[l - 1]) % mod;
        if (ans < 0) ans += mod;
        cout << ans << endl;
    }
    return 0;
}