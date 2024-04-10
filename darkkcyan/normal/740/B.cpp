#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define vi ve<int>
#define ii pair<int, int>
#define sz(v) ((int) v.size())

int n, m;
vi a;
ve<ii> b;
void read() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    b.resize(m);
    for (int i = 0; i < m; ++i) cin >> b[i].xx >> b[i].yy, --b[i].xx, --b[i].yy;
}

ve<long> dp;
long process() {
    dp.resize(m, -inf(long));
    long ans = 0;
    for (int i = 0; i < m; ++i) {
        long s = 0;
        for (int f = b[i].xx; f <= b[i].yy; ++f) s += a[f];
        dp[i] = s;
        for (int f = i - 1; f >= 0; --f) {
            dp[i] = max(dp[i], dp[f] + s);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    read();
    cout << process();

    return 0;
}