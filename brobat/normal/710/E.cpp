#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 20001100
#define MOD 1000000007

int n, x, y;
int dp[MAXN];

void solve() {
    cin >> n >> x >> y;
    dp[1] = x;
    dp[2] = x + min(x, y);
    dp[4] = dp[2] + min(2*x, y);
    dp[3] = min(dp[2] + x, dp[4] + x);
    for(int i = 6; i <= n + 5; i += 2) {
        dp[i] = min(dp[i/2] + y, dp[i-2] + 2*x);
        dp[i-1] = min(dp[i-2] + x, dp[i] + x);
    }
    cout << dp[n];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t; cin >> t; while(t--)
    {solve();}
    return 0;
}