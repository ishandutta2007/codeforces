/**
 *  created: 19/05/2022, 18:00:17
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
        long long ans = -1LL * k * (k - 1) / 2;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ans += a[i];
            a[i] -= n - 1 - i;
        }
        sort(a, a + n);
        reverse(a, a + n);
        ans -= accumulate(a, a + k, 0LL);
        cout << ans << "\n";
    }
    return 0;
}