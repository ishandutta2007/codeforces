#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int &i : v) cin >> i;

    for (int i = 0; i < min(N, (int)1000); i++) {
        bool ok = 0;
        for (int j = 0; j <= i; j++) {
            if (v[i] % (j + 2)) {
                ok = 1;
            }
        }
        if (!ok) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}