#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
static const int mod = 1e9 + 7;
vector<int> fact, inv_fact;
int pot(int a, int b) {
    if (b == 0) return 1;
    int x = pot(a, b / 2);
    if (b % 2) return x * x % mod * a % mod;
    return x * x % mod;
}
int binom(int n, int k) {
    return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}
void solve() {
    int N;
    cin >> N;
    int tot = 0;
    for (int i = 0; i <= N; i++) {
        int a;
        cin >> a;
        if (a == 0) continue;
        tot += binom(i + a, i + 1);
    }
    cout << tot % mod << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fact.pb(1);
    for (int i = 1; i < 400010; i++) {
        fact.pb(fact.back() * i % mod);
    }
    for (int x : fact) {
        inv_fact.pb(pot(x, mod - 2));
    }
    int T = 1;
    // cin >> T;
    while (T--) solve();
}