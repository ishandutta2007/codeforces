#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define xx first
#define yy second
#define long long long
#define sz(v) ((int)v.size())
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
typedef ve<int> vi;
typedef pair<int, int> ii;

int n, k;
vi a;
ve<vi> dp, tr;

void printans(int i, int f) {
    if (i == -1) return;
    printans(i - 1, tr[i][f]);
    cout << f << ' ';
}

int main() {
    #ifndef ONLINE_JUDGE
    #define filename "file"
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    dp.resize(n, vi(500 + 1, 1e6));
    tr.resize(n, vi(500 + 1, -1));

    for (int i = a[0]; i <= 500; ++i) dp[0][i] = i - a[0];
    for (int i = 1; i < n; ++i) {
        for (int f = a[i]; f <= 500; ++f) {
            for (int g = max(0, k - f); g <= 500; ++g) {
                int t = dp[i - 1][g] + f - a[i];
                if (t >= dp[i][f]) continue;
                dp[i][f] = t;
                tr[i][f] = g;
            }
        }
    }

    clog << "done";
    int ansind = min_element(dp[n - 1].bb, dp[n - 1].ee) - dp[n - 1].bb;
    cout << dp[n - 1][ansind] << '\n';
    printans(n - 1, ansind);

    return 0;
}