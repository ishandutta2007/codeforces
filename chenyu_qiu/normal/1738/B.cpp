#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> s(k);
    for (int i = 0; i < k; ++i) {
        cin >> s[i];
    }

    for (int i = 1; i < k - 1; ++i) {
        if (s[i] - s[i - 1] > s[i + 1] - s[i]) {
            cout << "NO\n";
            return;
        }
    }

    if (k == 1) {
        cout << "YES\n";
        return;
    }

    cout << (1ll * (s[1] - s[0]) * (n - k + 1) >= s[0] ? "YES" : "NO") << "\n";
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