#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 ID(const vector<int> &c) {
    i64 res = 0;
    for (auto x : c) {
        res = res * 3 + x;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> c(n);
    for (int i = 0; i < n; ++i) {
        vector<int> a(k);
        for (int j = 0; j < k; ++j) {
            cin >> a[j];
        }
        c[i] = a;
    }

    map<i64, int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vector<int> a(k);
            for (int x = 0; x < k; ++x) {
                a[x] = (6 - c[i][x] - c[j][x]) % 3;
            }
            ++mp[ID(a)];
        }
    }

    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        i64 val = mp[ID(c[i])];
        ans += val * (val - 1) / 2;
    }
    cout << ans << "\n";
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) { 
        solve();
    }

    return 0;
}