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
int N, M;
void solve() {
    cin >> N >> M;
    vector<array<int, 3> > v;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.pb({a, b, i});
    }
    sort(v.begin(), v.end());
    vector<int> pref(N + 10, 0);
    vector<int> z(N + 10, 0);
    int i = 0;
    for (auto [a, b, p] : v) {
        array<int, 3> x = {a - b, -1, -1};
        int k = lower_bound(v.begin(), v.end(), x) - v.begin();
        z[k]++;
        z[i + 1]--;
        pref[k] += b - a;
        pref[i + 1] -= b - a;
        i++;
    }
    vector<int> pref1(N + 10, 0);
    vector<int> z1(N + 10, 0);
    i = 0;
    for (auto [a, b, p] : v) {
        array<int, 3> x = {a + b, (int)1e17, -1};
        int k = lower_bound(v.begin(), v.end(), x) - v.begin();
        z1[i + 1]++;
        z1[k]--;
        pref1[i + 1] += b + a;
        pref1[k] -= b + a;
        i++;
    }
    for (int i = 1; i < pref.size(); i++) pref[i] += pref[i - 1];
    for (int i = 1; i < z.size(); i++) z[i] += z[i - 1];

    for (int i = 1; i < pref1.size(); i++) pref1[i] += pref1[i - 1];
    for (int i = 1; i < z1.size(); i++) z1[i] += z1[i - 1];
    vector<int> val;
    for (int i = 0; i < v.size(); i++) {
        val.pb(pref[i] + v[i][0] * z[i] + pref1[i] - v[i][0] * z1[i]);
        // cout << v[i].fi << ',' << val[i] << "  ";
    }
    // cout << endl;
    vector<int> alti;
    vector<int> alti1;
    for (int i = 0; i < val.size(); i++) {
        if (val[i] > M)
            alti.pb(v[i][0] + val[i] - M);
        else
            alti.pb(-1e13);
        if (val[i] > M)
            alti1.pb(v[i][0] - (val[i] - M));
        else
            alti1.pb(1e13);
    }
    vector<bool> ok;
    int mi = 1e13;
    for (int i = 0; i < alti1.size(); i++) {
        mi = min(mi, alti1[i]);
        if (v[i][0] - v[i][1] <= mi)
            ok.pb(1);
        else
            ok.pb(0);
    }
    int ma = -1e13;
    for (int i = alti.size() - 1; i >= 0; i--) {
        ma = max(ma, alti[i]);
        if (v[i][0] + v[i][1] < ma) ok[i] = 0;
    }
    string ans(N, '0');
    for (int i = 0; i < N; i++) {
        ans[v[i][2]] = ok[i] + '0';
    }
    cout << ans << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}