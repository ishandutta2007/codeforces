#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
    int N, Z;
    cin >> N >> Z;
    int ma = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        ma = max(ma, a | Z);
    }
    cout << ma << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}