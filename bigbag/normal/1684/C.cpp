/**
 *  created: 19/05/2022, 17:51:51
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, m;
vector<int> a[max_n];

bool solve() {
    for (int i = 0; i < n; ++i) {
        auto v = a[i];
        sort(v.begin(), v.end());
        vector<int> ids;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != v[j]) {
                ids.push_back(j);
            }
        }
        if (ids.size()) {
            assert(ids.size() >= 2);
            if (ids.size() > 2) {
                return false;
            }
            for (int j = 0; j < n; ++j) {
                swap(a[j][ids[0]], a[j][ids[1]]);
            }
            bool ok = 1;
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k + 1 < m; ++k) {
                    ok &= a[j][k] <= a[j][k + 1];
                }
            }
            if (ok) {
                cout << ids[0] + 1 << " " << ids[1] + 1 << "\n";
                return true;
            }
            return false;
        }
    }
    cout << "1 1\n";
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            a[i].resize(m);
            for (int &x : a[i]) {
                cin >> x;
            }
        }
        if (!solve()) {
            cout << "-1\n";
        }
    }
    return 0;
}