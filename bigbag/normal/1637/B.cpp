/**
 *  created: 12/02/2022, 16:38:25
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int res = 0;
            for (int j = i; j < n; ++j) {
                res += 1 + (a[j] == 0);
                ans += res;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}