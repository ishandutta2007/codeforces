#include <bits/stdc++.h>
using namespace std;
#define maxn 200009

int t, n, x[maxn], c[maxn], dp[maxn];

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
    while (t --) {
        memset(c, 0, sizeof c);
        memset(dp, 0, sizeof dp);
        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> x[i], c[x[i]] ++;

        dp[1] = c[1];

        int ans = 0;

        for (int i = 1; i < maxn; ++ i) {
            ans = max(ans, dp[i]);
            for (int j = i + i; j < maxn; j += i) {
                dp[j] = max(dp[j], dp[i] + c[j]);
            }
        }
        cout << n - ans << "\n";
    }
    return 0;
}