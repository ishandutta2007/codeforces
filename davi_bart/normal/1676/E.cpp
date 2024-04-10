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
    int N, M;
    cin >> N >> M;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.pb(x);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 1; i < N; i++) v[i] += v[i - 1];
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        int o = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
        if (o > N) o = -1;
        cout << o << '\n';
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}