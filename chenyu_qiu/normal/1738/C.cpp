#include <bits/stdc++.h>
using namespace std;

using ll = long long;

map<pair<int, int>, int> mp;
int dfs(int x, int y) {
    auto p = make_pair(x, y);
    if (mp.count(p)) {
        return mp[p];
    }
    if (x == 0 && y == 0) {
        return 1;
    }

    int res = 0;
    if (y > 0) {
        int val = dfs(x, y - 1);
        if (val != 3 && val) {
            int t = val == 1 ? (y & 1) : !(y & 1);
            res |= 1 << t;
        }
    }
    if (x > 0) {
        int val = dfs(x - 1, y);
        if (val != 3 && val) {
            int t = val == 1 ? (y & 1) : !(y & 1);
            res |= 1 << t;
        }
    }

    return mp[p] = res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            ++x;
        } else {
            ++y;
        }
    }

    cout << ((dfs(x, y) & 1) ? "Alice" : "Bob") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}