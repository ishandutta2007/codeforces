/**
 *  created: 03/01/2022, 16:36:23
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (2 * k - 1 <= n) {
            vector<string> ans(n, string(n, '.'));
            for (int i = 0; i < 2 * k; i += 2) {
                ans[i][i] = 'R';
            }
            for (int i = 0; i < n; ++i) {
                cout << ans[i] << "\n";
            }
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}