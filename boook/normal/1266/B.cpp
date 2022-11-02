#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[1000 + 10];
int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);

    int t, n = 1000;

    for (int i = 1; i <= 6; ++ i) {
        int val = 21 - i;
        dp[val] = 1;
    }
    for (int j = 14; j <= n; ++ j)
        dp[j] |= dp[j - 14];

    // for (int i = 0; i <= n; ++ i) if (dp[i] == 0) cout << i << endl;
    cin >> t;
    while (t --) {
        int now;
        cin >> now;
        if (now <= 100) {
            if (dp[now]) cout << "YES" << "\n";
            else cout << "NO\n";
        }
        else {
            now %= 14;
            now += 14;
            if (15 <= now && now <= 20) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}