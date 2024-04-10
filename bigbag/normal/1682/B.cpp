/**
 *  created: 22/05/2022, 17:55:40
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = (1 << 30) - 1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] != i) {
                ans &= a[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}