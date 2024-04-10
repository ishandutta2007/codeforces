/**
 *  created: 25/06/2022, 17:43:34
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 50555, inf = 1000111222;

int t, n, m, a[max_n];

vector<pair<int, long long>> solve() {
    vector<pair<int, long long>> v;
    for (int i = 0; i < n; ++i) {
        int k = 1;
        while (a[i] % m == 0) {
            a[i] /= m;
            k *= m;
        }
        if (!v.empty() && v.back().first == a[i]) {
            v.back().second += k;
        } else {
            v.push_back({a[i], k});
        }
    }
    return v;
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
            cin >> a[i];
        }
        auto v1 = solve();
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        auto v2 = solve();
        if (v1 == v2) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}