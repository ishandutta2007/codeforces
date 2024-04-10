#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int j = 0; j + 1 < n; ++j) {
        for (int i = 0; i < n; ++i) {
            a[i][j + 1] = (a[i][j] + i + j) % n;
        }
    }

    for (int i = 0; i < n; ++i) {
        int x = (b[i] - a[i][i] + n) % n;
        for (int j = 0; j < n; ++j) {
            cout << (a[i][j] + x) % n << " \n"[j == n - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}