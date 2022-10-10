#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())

long r, g;
const long mod = 1e9 + 7;
long findh() {
    long ll = 0, rr = 1000;
    while (ll < rr) {
        long mid = ll + (rr - ll + 1) / 2;
        if (mid * (mid + 1) / 2 > r + g) rr = mid - 1;
        else ll = mid;
    }
    return ll;
}

ve<long> dp[2];
long h;
void process() {
    h = findh();
    dp[0].resize(r + 1);
    dp[0][0] = 1;
    for (int i = 0, t = 0; i < h; ++i, t ^= 1) {
        dp[!t] = dp[t];
        for (int f = 0; f + i + 1 <= r; ++f) {
            dp[!t][f + i + 1] = (dp[!t][f + i + 1] + dp[t][f]) % mod;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> r >> g;
    process();
    long ans = 0;
    for (long i = r; i + g >= h * (h + 1) / 2 and i >= 0; --i)
        ans = (ans + dp[h & 1][i]) % mod;
    cout << ans;

    return 0;
}