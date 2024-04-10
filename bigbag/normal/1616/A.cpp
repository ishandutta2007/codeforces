/**
 *  created: 29/12/2021, 17:35:18
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, int> q;
        while (n--) {
            int x;
            cin >> x;
            ++q[abs(x)];
        }
        int ans = 0;
        for (auto [x, y] : q) {
            if (x == 0) {
                ++ans;
            } else {
                ans += min(y, 2);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}