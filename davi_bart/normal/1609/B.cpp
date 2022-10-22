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
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<bool> x(N, 0);
    int tot = 0;
    for (int i = 0; i < N - 2; i++) {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
            x[i] = 1;
            tot++;
        }
    }
    while (Q--) {
        int a;
        char b;
        cin >> a >> b;
        a--;
        s[a] = b;
        for (int i = max(a - 3, (int)0); i < min(a + 2, N - 2); i++) {
            tot -= x[i];
            x[i] = 0;
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                x[i] = 1;
                tot++;
            }
        }
        cout << tot << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}