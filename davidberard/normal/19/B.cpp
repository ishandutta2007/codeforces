#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const ll INF = 0x3f3f3f3f3f3f3f3fll;
ll dp[4020];

ll t[2010], c[2010];
int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    ll tsum = 0;
    memset(dp, INF, sizeof dp);
    dp[0] = 0;
    for(int i=1; i<=n; ++i) {
        cin >> t[i] >> c[i];
        for(int j=4019; j-t[i]-1>=0; --j) {
            dp[j] = min(dp[j], dp[j-t[i]-1]+c[i]);
        }
    }
    ll ans = INF;
    for(int j=n; j<4019; ++j) {
        ans = min(ans, dp[j]);
    }
    cout << ans << "\n";
    return 0;
}