#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int va[n+1], dp2[n][n+1], dp[n][n+1][n+1][2];
    va[0]=0;
    for(int a=1; a<=n; a++) cin>>va[a];

    for(int l=0; l<n; l++) for(int i=0; i<2; i++) dp[l][0][0][i]=0;

    for(int a=1; a<=n; a++)
    {
        for(int l=0; l+a<=n; l++)
        {
            dp2[l][a]=0;
            for(int q=0; q<=a; q++)
            {
                for(int i=0; i<2; i++)
                {
                    dp[l][a][q][i]=-inf;
                    if(q and s[l+a-1]-'0'==i) dp[l][a][q][i]=dp[l][a-1][q-1][i];
                    for(int b=1; b<a; b++)
                    {
                        if(a-b>=q)
                        {
                            dp[l][a][q][i]=max(dp[l][a][q][i], dp[l][a-b][q][i]+dp2[l+(a-b)][b]);
                        }
                    }
                    dp2[l][a]=max(dp2[l][a], dp[l][a][q][i]+va[q]);
                }
            }
            //cout<<dp2[l][a]<<" ";
            dp[l][a][0][0]=dp2[l][a];
            dp[l][a][0][1]=dp2[l][a];
        }
        //cout<<"\n";
    }
    cout<<dp2[0][n];
}