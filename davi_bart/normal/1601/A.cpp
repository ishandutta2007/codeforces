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
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<int> b(32, 0);
    for (int x : a) {
        for (int i = 0; i < 32; i++) {
            if (x & (1 << i)) b[i]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        ans = gcd(ans, b[i]);
    }

    for (int i = 1; i <= N; i++) {
        if (ans % i == 0) cout << i << " ";
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}