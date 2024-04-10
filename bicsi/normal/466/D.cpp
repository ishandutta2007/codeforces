#include <bits/stdc++.h>

using namespace std;

const int kMod = 1e9 + 7;

int main() {
    int n, m; cin >> n >> m;
    vector<int> v(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    v[n] = m;

    int have = 0, ans = 1;
    for (int i = 0; i <= n; ++i) {
        if (v[i] + have == m) {
            ans = 1LL * ans * (have + 1) % kMod;
        }
        if (v[i] + have < m) have += 1;
        if (v[i] + have > m) { ans = 1LL * ans * have % kMod; have -= 1; }
        if (have < 0 || v[i] + have != m) ans = 0;
    }
    cout << ans << endl;

    return 0;    
}