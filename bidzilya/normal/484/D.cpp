#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<long long> > dp(2, vector<long long>(n));
    dp[0][0] = -a[0];
    dp[1][0] = a[0];
    for (int i = 1; i < n; ++i) {
        dp[0][i] = -a[i] + max(dp[0][i - 1] + a[i - 1], dp[1][i - 1] - a[i - 1]);
        dp[1][i] = a[i] + max(dp[0][i - 1] + a[i - 1], dp[1][i - 1] - a[i - 1]);
        if (a[i] > a[i - 1]) {
            dp[0][i] = max(dp[0][i], dp[0][i - 1]);
        } else if (a[i] < a[i - 1]) {
            dp[1][i] = max(dp[1][i], dp[1][i - 1]);
        }
    }
    cout << max(dp[0][n - 1] + a[n - 1], dp[1][n - 1] - a[n - 1]) << endl;

    return 0;
}