#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    const int inf=(1<<30);
    while(q--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        vector<vector<int>> dp(2*n+1,vector<int>(n+1,inf));
        for(int i=0;i<=2*n;i++) dp[i][0]=0;
        for(int i=1;i<=2*n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+abs(a[j]-i));
            }
        }
        cout << dp[2*n][n] << "\n";
    }
    return 0;
}