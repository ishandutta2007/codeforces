/**
 *  created: 03/01/2022, 16:39:57
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, l[max_n], r[max_n], c[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        map<pair<int, int>, int> q;
        int mn = inf, mx = 0, cost_min = inf, cost_max = inf;
        for (int i = 0; i < n; ++i) {
            cin >> l[i] >> r[i] >> c[i];
            if (mn > l[i]) {
                mn = l[i];
                cost_min = inf;
            }
            if (mn == l[i]) {
                cost_min = min(cost_min, c[i]);
            }

            if (mx < r[i]) {
                mx = r[i];
                cost_max = inf;
            }
            if (mx == r[i]) {
                cost_max = min(cost_max, c[i]);
            }
            if (!q.count({l[i], r[i]})) {
                q[{l[i], r[i]}] = inf;
            }
            q[{l[i], r[i]}] = min(q[{l[i], r[i]}], c[i]);
            int res = cost_max + cost_min;
            if (q.count({mn, mx})) {
                res = min(res, q[{mn, mx}]);
            }
            cout << res << "\n";
        }
    }
    return 0;
}