#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int inf=(1<<30);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<array<int,2>> dp(n+1,{inf,inf});
        dp[0][0]=0;
        dp[1][1]=a[1];
        for(int i=2;i<=n;i++)
        {
            dp[i][0]=min(dp[i-2][1],dp[i-1][1]);
            dp[i][1]=min(dp[i-2][0]+a[i-1]+a[i],dp[i-1][0]+a[i]);
        }
        cout << min(dp[n][0],dp[n][1]) << "\n";
    }
    return 0;
}