#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ull k;

    cin >> n >> k;

    vector<ull> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    vector<int> ans(n);
    int shift = 0;
    for (int i = 0; i < n; ) {
        if (dp[n - i - 1] < k) {
            k -= dp[n - i - 1];
            ans[i] = shift + 2;
            ans[i + 1] = shift + 1;
            shift += 2;
            i += 2;
        } else {
            ans[i] = shift + 1;
            ++shift;
            ++i;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}