#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            a[i]+=i;
        }
        vector<vector<int>> dp(n+1,vector<int>(n+2,n));
        dp[n][n+1]=0;
        vector<vector<int>> best(n+1,vector<int>(n+2,n));
        best[n][n+1]=0;
        for(int i=n-1;i>=1;i--)
        {
            vector<int> c(n+1,0);
            int now=0;
            for(int j=i+1;j<=a[i];j++)
            {
                dp[i][j]=now+best[j][max(j+1,a[i]+1)];
                c[a[j]]++;
                now++;
                now-=c[j];
            }
            best[i][n]=dp[i][n];
            for(int j=n-1;j>=i+1;j--) best[i][j]=min(best[i][j+1],dp[i][j]);
            //for(int j=i+1;j<=n;j++) cout << "[" << i << "," << j << "]: " << dp[i][j] << endl;
        }
        cout << best[1][2] << "\n";
    }
    return 0;
}