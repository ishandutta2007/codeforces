/**
 *  created: 25/06/2022, 17:36:21
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, inf = 1000111222;

int t, n, a[max_n], z;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> z;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ans = max(ans, a[i] | z);
        }
        cout << ans << "\n";
    }
    return 0;
}