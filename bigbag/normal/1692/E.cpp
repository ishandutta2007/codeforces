/**
 *  created: 14/06/2022, 17:45:02
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, s, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int pos = 0, sum = 0, ans = inf;
        for (int i = 0; i < n; ++i) {
            if (pos < i) {
                pos = i;
                sum = 0;
            }
            while (pos < n && sum + a[pos] <= s) {
                sum += a[pos];
                ++pos;
            }
            if (sum == s) {
                ans = min(ans, i + n - pos);
            }
            sum -= a[i];
        }
        if (ans == inf) {
            ans = -1;
        }
        cout << ans << "\n";
    }
    return 0;
}