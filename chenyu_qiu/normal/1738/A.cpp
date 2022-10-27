#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    vector<int> a, b;
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> y[i];
        ans += y[i];
        if (x[i]) {
            a.push_back(y[i]);
        } else {
            b.push_back(y[i]);
        }
    }

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    int l = min(a.size(), b.size());
    for (int i = 0; i < l; ++i) {
        if (i < (int) a.size()) ans += a[i];
        if (i < (int) b.size()) ans += b[i];
    }

    if (a.size() == b.size()) {
        ans -= min(a.back(), b.back());
    }

    cout << ans << "\n";
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