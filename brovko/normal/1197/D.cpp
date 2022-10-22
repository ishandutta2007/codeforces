#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, k, a[300005], dp[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];

    int ans=0;

    for(int i=0;i<n;i++)
    {
        int s=0;
        if(i)
            s=max(s, dp[i-1]);

        for(int j=1;j<=min(m, n-i);j++)
        {
            s+=a[i+j-1];
            dp[i+j-1]=max(dp[i+j-1], s-k);
        }
    }

    for(int i=0;i<n;i++)
        ans=max(ans, dp[i]);

    cout << ans;
}