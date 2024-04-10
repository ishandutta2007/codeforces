#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++) scanf("%d",&v[i]);
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int o=0;o<n;o++)
    {
        for(int i=0;o+i<n;i++)
        {
            dp[i][o+i]=1+dp[i+1][o+i];
            if(i+1<=o+i&&v[i+1]==v[i]) dp[i][o+i]=min(dp[i][o+i],1+dp[i+2][o+i]);
            for(int j=i+2;j<=o+i;j++) if(v[j]==v[i]) dp[i][o+i]=min(dp[i][o+i],dp[i+1][j-1]+dp[j+1][o+i]);
        }
    }
    printf("%d\n",dp[0][n-1]);
    return 0;
}