#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> b(n + 1), p;
    vector<vector<int>> v(n + 2);
    vector<bool> tag(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        v[b[i]].push_back(i);
        tag[b[i]] = 1;
    }

    int cur = v[0].empty() ? (n + 1) : 0;
    int type = (cur == 0);
    int k = 0;

    while ((int) p.size() < n) {
        auto c = v[cur];
        if (!type) {
            k += c.size();
        }
        sort(c.begin(), c.end(), [&](int x, int y) {
            return tag[x] < tag[y];
        });
        for (auto x : c) {
            p.push_back(x);
        }
        cur = c.back();
        type ^= 1;
    }

    cout << k << "\n";
    for (auto x : p) {
        cout << x << " ";
    }
    cout << "\n";
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