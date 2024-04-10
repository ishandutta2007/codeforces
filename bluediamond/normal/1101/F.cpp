#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 400 + 1;

int n, q;
int a[N];
int dp[N][N][N]; /// dp[l][r][cnt]

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            dp[i][j][0] = (a[j] - a[i]);
            for (int cnt = 1; cnt <= j - i - 1; cnt++)
            {
                dp[i][j][cnt] = dp[i][j][cnt - 1];
                for (int p = i + 1; p < j && p <= i + 50; p++)
                {
                    dp[i][j][cnt] = min(dp[i][j][cnt], max(a[p] - a[i], dp[p][j][cnt - 1]));
                }
            }
        }
    }
    ll res = 0LL;
    for (int i = 1; i <= q; i++)
    {
        ll l, r, consume, stop;
        cin >> l >> r >> consume >> stop;
        l--;
        r--;
        if (stop > r - l - 1)
        {
            stop = r - l - 1;
        }
        res = max(res, consume * (ll) dp[l][r][stop]);
  ///      cout << consume * dp[l][r][stop] << "\n";
    }
    cout << res << "\n";
}