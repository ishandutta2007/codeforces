/**
 *  created: 14/06/2022, 17:35:37
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, a, b, c, d;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        int ans = a < b;
        ans += a < c;
        ans += a < d;
        cout << ans << "\n";
    }
    return 0;
}