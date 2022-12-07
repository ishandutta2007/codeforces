#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ma[m][m], dp[m], dp2[m];
    for(int a=0; a<m; a++)
    {
        dp[a]=0, dp2[a]=0;
        for(int b=0; b<m; b++) ma[a][b]=0;
    }
    for(int a=1; a<m; a++) ma[a][a-1]=1;
    ma[0][0]=1, ma[0][m-1]=1, dp[0]=1;

    while(n)
    {
        if(n&1)
        {
            for(int a=0; a<m; a++)
            {
                for(int b=0; b<m; b++) dp2[b]=(dp2[b]+dp[a]*ma[a][b])%mod;
            }
            for(int a=0; a<m; a++) dp[a]=dp2[a], dp2[a]=0;
        }
        n>>=1;
        int te[m][m];
        for(int a=0; a<m; a++) for(int b=0; b<m; b++) te[a][b]=0;
        for(int a=0; a<m; a++)
        {
            for(int b=0; b<m; b++)
            {
                for(int c=0; c<m; c++) te[a][b]=(te[a][b]+ma[a][c]*ma[c][b])%mod;
            }
        }
        for(int a=0; a<m; a++) for(int b=0; b<m; b++) ma[a][b]=te[a][b];
    }
    cout<<dp[0];
}