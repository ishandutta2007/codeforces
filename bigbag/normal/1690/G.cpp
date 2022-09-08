/**
 *  created: 07/06/2022, 18:01:53
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, m, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int mn = inf;
        set<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            if (mn > a[i]) {
                mn = a[i];
                q.insert({i, mn});
            }
        }
        while (m--) {
            int i, x;
            cin >> i >> x;
            --i;
            a[i] -= x;
            auto it = prev(q.upper_bound({i, inf}));
            if (it->second > a[i]) {
                int old_pos = it->first, old_val = it->second;
                q.erase(it);
                if (old_pos < i) {
                    q.insert({old_pos, old_val});
                }
                while (true) {
                    auto it = q.lower_bound({i, -1});
                    if (it == q.end() || it->second < a[i]) {
                        break;
                    }
                    q.erase(it);
                }
                q.insert({i, a[i]});
            }
            cout << q.size() << " ";
        }
        cout << "\n";
    }
    return 0;
}