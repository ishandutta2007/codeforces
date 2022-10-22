#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, c, a[200005], b[200005], dp[200005][2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    n--;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];
    dp[0][1]=1e18;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=min(dp[i-1][0], dp[i-1][1])+a[i-1];
        dp[i][1]=min(dp[i-1][0]+c, dp[i-1][1])+b[i-1];
    }
    for(int i=0;i<=n;i++)
        cout << min(dp[i][0], dp[i][1]) << ' ';
}