/**
 *  created: 23/05/2022, 17:42:40
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n;
pair<int, int> a[max_n];
vector<pair<int, int>> ans;

void proc(int l, int r) {
    for (int i = l; i < r; ++i) {
        for (int j = i + 1; j < r; ++j) {
            if (a[i].first > a[j].first) {
                swap(a[i], a[j]);
                ans.push_back({i, j});
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
        }
        ans.clear();
        proc(0, n);
        for (int i = 0; i < n; ) {
            int start = i, x = a[i].first;
            while (i < n && a[i].first == x) {
                swap(a[i].first, a[i].second);
                ++i;
            }
            proc(start, i);
        }
        bool ok = 1;
        for (int i = 0; i + 1 < n; ++i) {
            ok &= a[i].first <= a[i + 1].first;
            ok &= a[i].second <= a[i + 1].second;
        }
        if (ok) {
            cout << ans.size() << "\n";
            for (auto [i, j] : ans) {
                cout << i + 1 << " " << j + 1 << "\n";
            }
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}