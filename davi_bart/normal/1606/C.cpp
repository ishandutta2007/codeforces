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
int pot[15];
void solve() {
    pot[0] = 1;
    for (int i = 1; i < 10; i++) pot[i] = pot[i - 1] * 10;
    int N, K;
    cin >> N >> K;
    K++;
    vector<int> v(N);
    for (int &i : v) cin >> i;
    vector<int> p;
    for (int i = 1; i < v.size(); i++) {
        p.pb(pot[v[i] - v[i - 1]] - 1);
    }
    p.pb(1e10);
    // for (int j : p) cout << j << " ";
    // cout << endl;
    for (int i = 0; i < p.size(); i++) {
        if (K <= p[i]) {
            cout << K;
            for (int j = 0; j < i; j++) cout << p[j];
            cout << endl;
            break;
        } else {
            K -= p[i];
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}