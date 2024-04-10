#include <bits/stdc++.h>

#define ll long long
const ll MAX_N = 1e5 + 1, MOD = 1e9 + 7;
using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    ll dp[k][n + 1];
    vector<ll> v[n + 1];
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= i; j++) if (i % j == 0) v[i].push_back(j);
    }
    for (ll i = 0; i <= n; i++) dp[0][i] = 1;
    for (ll i = 1; i < k; i++) {
        for (ll j = 1; j <= n; j++) {
            ll s = 0;
            for (ll p = 0; p < v[j].size(); p++) {
                s += dp[i - 1][v[j][p]];
                s %= MOD;
            }
            dp[i][j] = s;
        }
    }
    ll cnt = 0;
    for (ll i = 1; i <= n; i++) {
        cnt += dp[k - 1][i];
        cnt %= MOD;
    }
    cout << cnt;
    return 0;
}