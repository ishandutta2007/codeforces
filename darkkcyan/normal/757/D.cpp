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

#define NN 75
#define maxm 20
#define MM (1LL<<maxm)
#define mod ((long) 1e9 + 7)

int n;
string s;
int dp[NN][MM];

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < NN; ++i) dp[i][0] = 1;
    cin >> n >> s;

    for (int i = 0; i < n; ++i) s[i] -= '0';

    long ans = 0;
    int i;
    for (i = 0; i < n and s[i] == 0; ++i);
    if (i >= n) {
        cout << 0;
        return 0;
    }
    int num = 0;
    for (int f = i; f < n; ++f) {
        num = (num << 1) + s[f];
        if (num > 20) break;
        dp[f][1 << (num - 1)] ++;
    }
    for (int i = 0; i < n; ++i) {
        int f;
        for (f = i + 1; f < n and s[f] == 0; ++f);
        if (f >= n) break;
        int num = 0;
        for (int g = f; g < n; ++g) {
            num = (num << 1) + s[g];
            if (num > 20) break;
            int tn = 1 << (num - 1);
            for (int h = 0; h < MM; ++h)
                dp[g][h | tn] = (dp[g][h | tn] + dp[i][h]) % mod;
        }
    }

    for (int i = 1; i < MM; i = i << 1 | 1)
    for (int f = 0; f < n; ++f) {
        ans = (ans + dp[f][i]) % mod;
//        clog << bitset<4>(i) << ' ' << f << ' ' << dp[f][i] << endl;
    }
    cout << ans;

    return 0;
}