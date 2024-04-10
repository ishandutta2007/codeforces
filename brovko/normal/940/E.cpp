#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, c, a[100005], dp[100005], st[100005][20];

int get(int l, int r)
{
    int ans = 1e9;

    for(int i = 19; i >= 0; i--)
        if(l + (1ll << i) - 1 < r)
    {
        ans = min(ans, st[l][i]);
        l += (1ll << i);
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        st[i][0] = a[i];

    for(int j = 1; j < 20; j++)
        for(int i = 0; i + (1ll << j) - 1 < n; i++)
            st[i][j] = min(st[i][j - 1], st[i + (1ll << j - 1)][j - 1]);

    for(int i = c - 1; i < n; i++)
        dp[i] = max(dp[i - 1], dp[max(i - c, 0ll)] + get(i - c + 1, i + 1));

    int ans = -dp[n - 1];
    for(int i = 0; i < n; i++)
        ans += a[i];
    cout << ans;
}