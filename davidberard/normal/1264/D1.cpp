#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

/*
 * dp[l][r] = sum of substring l, r
 * dp[l][r] += ways where we throw away left
 *          += ways where we throw away right
 *          -= ways where we throw away both (i.e. avoid double counting)
 *          += ways where we do both correctly + extra points we get
 */

const int N = 2020;
const ll MOD = 998244353;

char s[N];
ll dp[N][N];
int amt[N];
ll tpow[N];
int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> (s+1);
    n = strlen(s+1);
    tpow[0] = 1;
    for (int i=1; i<=n+1; ++i) {
        amt[i] = amt[i-1]+(s[i] == '?');
        tpow[i] = tpow[i-1]*2%MOD;
    }
    for (int i=2; i<=n; ++i) {
        for (int j=1; i+j-1<=n; ++j) {
            int l = j, r = j+i-1;
            if (s[l] != '(') {
                dp[l][r] += dp[l+1][r];
            }
            if (s[r] != ')') {
                dp[l][r] += dp[l][r-1];
            }
            if (s[l] != '(' && s[r] != ')') {
                dp[l][r] -= dp[l+1][r-1];
            }
            if (s[l] != ')' && s[r] != '(') {
                dp[l][r] += dp[l+1][r-1] + tpow[amt[r-1]-amt[l]];
            }
            dp[l][r] %= MOD;
        }
    }
    cout << dp[1][n] << "\n";

    return 0;
}