#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> v[5000];
string col;
int ans = 0;
array<int, 2> calc(int pos) {
    array<int, 2> k = {0, 0};
    for (int x : v[pos]) {
        auto o = calc(x);
        k[0] += o[0];
        k[1] += o[1];
    }
    k[col[pos - 1] == 'B']++;
    if (k[0] == k[1]) ans++;
    return k;
}

void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N + 10; i++) v[i].clear();
    for (int i = 2; i <= N; i++) {
        int x;
        cin >> x;
        v[x].pb(i);
    }
    ans = 0;
    cin >> col;
    calc(1);
    cout << ans << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}