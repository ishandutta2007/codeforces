/**
 *  created: 14/06/2022, 18:00:47
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, vector<int>> q;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            q[a[i]].push_back(i);
        }
        vector<int> ans{-1};
        for (auto [x, v] : q) {
            pair<int, int> mn{inf, inf};
            for (int i = 0; i < v.size(); ++i) {
                int val = 2 * i - v[i];
                mn = min(mn, {val, v[i]});
                ans = max(ans, {val - mn.first + 1, x, mn.second, v[i]});
            }
        }
        cout << ans[1] << " " << ans[2] + 1 << " " << ans[3] + 1 << "\n";
    }
    return 0;
}