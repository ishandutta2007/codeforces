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
vector<bool> prime(2000000, 1);
void solve() {
    int N, e;
    cin >> N >> e;
    vector<int> v(N);
    for (int &i : v) cin >> i;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (prime[v[i]]) {
            int prec = 0;
            for (int j = i - e; j >= 0; j -= e) {
                if (v[j] != 1) break;
                prec++;
            }
            int succ = 0;
            for (int j = i + e; j < N; j += e) {
                if (v[j] != 1) break;
                succ++;
            }
            int poss = (succ + 1) * (prec + 1) - 1;
            ans += poss;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= 1000000; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                prime[j] = 0;
            }
        }
    }
    int T = 1;
    cin >> T;
    while (T--) solve();
}