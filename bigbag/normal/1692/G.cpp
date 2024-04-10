/**
 *  created: 14/06/2022, 17:52:36
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            cnt += a[i] < 2 * a[i + 1];
        }
        int ans = 0;
        for (int i = 0; i + k < n; ++i) {
            ans += cnt == k;
            cnt -= a[i] < 2 * a[i + 1];
            cnt += a[i + k] < 2 * a[i + k + 1];
        }
        cout << ans << "\n";
    }
    return 0;
}