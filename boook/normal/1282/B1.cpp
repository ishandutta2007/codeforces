#include <bits/stdc++.h>
using namespace std;
#define maxn 200090


int t, n, p, k, x[maxn], dp[maxn];

int main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> t;
    while (t --) {
        cin >> n >> p >> k;

        for (int i = 1; i <= n; ++ i) cin >> x[i];
        sort(x + 1, x + 1 + n);
        
        int ans = 0;
        for (int i = 1; i <= n; ++ i) {
            if (i >= k) dp[i] = min(dp[i - 1] + x[i], dp[i - k] + x[i]);
            else dp[i] = dp[i - 1] + x[i];
            if (dp[i] <= p) ans = i;
        }
        cout << ans << "\n";
    }
    return 0;
}