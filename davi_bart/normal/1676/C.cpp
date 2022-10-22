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
    vector<string> v;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.pb(s);
    }
    int mi = 1e9;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int cnt = 0;
            for (int k = 0; k < M; k++) {
                cnt += max(v[i][k], v[j][k]) - min(v[i][k], v[j][k]);
            }
            mi = min(mi, cnt);
        }
    }
    cout << mi << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}