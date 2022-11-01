#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<vector<int>> v(k,vector<int>(n+1,0));
    vector<vector<int>> pos(k,vector<int>(n+1,0));
    for(int o=0;o<k;o++)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&v[o][i]);
            pos[o][v[o][i]]=i;
        }
    }
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            bool ok=1;
            for(int o=0;o<k;o++) if(!(pos[o][v[0][j]]<pos[o][v[0][i]])) ok=0;
            if(ok) dp[i]=max(dp[i],dp[j]+1);
        }
    }
    int res=0;
    for(int i=1;i<=n;i++) res=max(res,dp[i]);
    printf("%d\n",res);
    return 0;
}