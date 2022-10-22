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
const int mod = 998244353;
int pot(int a, int b) {
    if (b == 0) return 1;
    int x = pot(a, b / 2);
    if (b % 2) return x * x % mod * a % mod;
    return x * x % mod;
}
vector<int> fact;
int memo[600][600];
int vis[600][600];
int solve(int N, int X) {
    if (X <= 0) return 1;
    if (N == 1) return 0;
    if (N <= 0) return 1;
    if (X <= N - 1) return pot(X, N);

    if (vis[N][X]) return memo[N][X];
    vis[N][X] = 1;
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        ans += solve(i, X - N + 1) * pot(N - 1, N - i) % mod * fact[N] % mod * pot(fact[N - i] * fact[i] % mod, mod - 2) % mod;
    }
    return memo[N][X] = ans % mod;
}
void solve() {
    fact.pb(1);
    for (int i = 0; i < 600; i++) {
        fact.pb(fact[i] * (i + 1) % mod);
    }
    int N, X;
    cin >> N >> X;
    cout << solve(N, X) << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}