#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define int ll
using namespace std;
static const int mod = 998244353;
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
    string a;
    cin >> a;
    int zero = 0;
    int k = 0;
    bool prec = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '0') zero++;
        if (i && a[i] == '1' && a[i - 1] == '1' && !prec) {
            k++;
            prec = 1;
        } else
            prec = 0;
    }
    cout << binom(zero + k, k) << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fact.pb(1);
    for (int i = 0; i < 1000010; i++) fact.pb(fact.back() * (i + 1) % mod);
    for (int x : fact) inv_fact.pb(pot(x, mod - 2));

    int T;
    cin >> T;
    while (T--) solve();
}