#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=100;
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> c(n+1,0);
        for(int i=1;i<=n;i++) cin >> c[i];
        vector<int> cnt(n+1,0);
        for(int i=1;i<=n;i++) cnt[i]=(c[i]==c[i-1]?cnt[i-1]:0)+1;
        vector<vector<int>> dp(n+1,vector<int>(N+1,n));
        for(int i=1;i<=N;i++) dp[0][i]=0;
        auto mn=[](int &a,int b){a=min(a,b);};
        for(int i=1;i<k;i++)
        {
            if(cnt[i]==i) dp[i][c[i]]=0;
            for(int j=1;j<=N;j++) mn(dp[i][j],1);
        }
        for(int i=k;i<=n;i++)
        {
            mn(dp[i][c[i]],dp[i-cnt[i]][c[i]]);
            for(int j=1;j<=N;j++) mn(dp[i][j],dp[i-k][j]+1);
        }
        int res=n;
        for(int j=1;j<=N;j++) mn(res,dp[n][j]);
        cout << res << "\n";
    }
    return 0;
}