#pragma GCC optimize("O3")
#pragma GCC target("avx2")
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
    for (int &x : a) cin >> x;
    int y = 0;
    for (int i = 0; i < N; i++) {
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            y++;
        }
    }
    sort(a.begin(), a.end());
    int tot = 0;
    a.back() <<= y;
    for (int x : a) tot += x;
    cout << tot << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}