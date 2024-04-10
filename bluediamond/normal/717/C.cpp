#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
                cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
                ans += a[i] % MOD * a[n - 1 - i] % MOD;
                ans %= MOD;
        }
        cout << ans << "\n";
}