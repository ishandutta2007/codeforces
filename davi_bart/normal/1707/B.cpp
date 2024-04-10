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
    vector<int> v;
    int zeri = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (!x)
            zeri++;
        else
            v.pb(x);
    }
    while (v.size() > 1) {
        vector<int> p;
        if (zeri) {
            p.pb(v[0]);
            zeri--;
        }
        for (int i = 1; i < v.size(); i++) {
            int x = v[i] - v[i - 1];
            if (!x)
                zeri++;
            else
                p.pb(x);
        }
        sort(p.begin(), p.end());
        v = p;
    }
    if (v.size() == 0)
        cout << 0 << '\n';
    else
        cout << v[0] << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}