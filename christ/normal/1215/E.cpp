#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
ll pre[20][20], go[1 << 20][20], cnt[20];
ll dp[1 << 20];
int main() {
    int n;
    scanf ("%d",&n);
    vector<int> a(n);
    for (auto &au : a) {
        scanf ("%d",&au);
        --au;
        for (int i = 0; i < 20; i++) if (i != au) pre[i][au] += cnt[i];
        cnt[au]++;
    }
    for (int i = 0; i < 20; i++) {
        for (int mask = 1; mask < (1 << 20); mask++) if ((mask>>i&1)^1) {
            int bit = __builtin_ctz(mask);
            go[mask][i] = go[mask^(1<<bit)][i] + pre[bit][i];
        }
    }
    for (int mask = 1; mask < (1 << 20); mask++) {
        dp[mask] = LLONG_MAX;
        for (int i = 0; i < 20; i++) if (mask>>i&1) dp[mask] = min(dp[mask],dp[mask^(1<<i)]+go[mask^(1<<i)][i]);
    }
    printf ("%lld\n",dp[(1 << 20)-1]);
    return 0;
}