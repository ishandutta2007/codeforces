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
    map<int, int> v;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v[x]++;
    }
    vector<int> q;
    for (auto [x, y] : v) {
        if (y >= M) q.pb(x);
    }
    if (q.size() == 0) {
        cout << -1 << '\n';
        return;
    }
    array<int, 2> ma = {q[0], q[0]};
    int cur = -1;
    int prec = -1;
    for (int i : q) {
        if (i != prec + 1) {
            cur = i;
        }
        prec = i;
        if (ma[1] - ma[0] < i - cur) {
            ma[0] = cur;
            ma[1] = i;
        }
    }
    cout << ma[0] << " " << ma[1] << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}