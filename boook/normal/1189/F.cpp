#include <bits/stdc++.h>
using namespace std;
#define maxn 1010
#define mod 998244353

int n, k, x[maxn], dp[maxn][maxn], sm[maxn];

int solve(int gap) {
    dp[0][0] = 1, x[0] = -200000;
    for (int i = 1; i <= k; ++ i) {
        for (int j = 0; j <= n; ++ j) 
            sm[j] = j == 0 ? dp[i - 1][j] : (dp[i - 1][j] + sm[j - 1]) % mod;
        int pos = 0;
        for (int j = 1; j <= n; ++ j) {
            while (x[j] - x[pos + 1] >= gap) pos ++;
            dp[i][j] = sm[pos];
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; ++ i)
        sum = (sum + dp[k][i]) % mod;
    //cout << "[gap] " << gap << "[ans] " << sum << "\n";
    return sum;
}

int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) cin >> x[i];
    sort(x + 1, x + 1 + n);
    
    int dis = 100000 / (k - 1), pre = solve(1), ans = 0;
    for (int i = 2; i <= dis + 5; ++ i) {
        int now = solve(i);
        ans = (ans + 1ll * (pre - now + mod) * (i - 1)) % mod;
        pre = now;
    }
    cout << ans << "\n";
    return 0;
}