#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int l[n][m], r[n][m], dp[m][m];
    for(int a=0; a<n; a++)
    {
        int q;
        cin>>q;
        for(int b=0; b<q; b++)
        {
            int lg, rg;
            cin>>lg>>rg;
            lg--, rg--;
            for(int c=lg; c<=rg; c++)
            {
                l[a][c]=lg, r[a][c]=rg;
            }
        }
    }
    for(int len=1; len<=m; len++)
    {
        for(int lg=0; lg+len<=m; lg++)
        {
            int rg=lg+len-1;
            dp[lg][rg]=0;
            for(int p=lg; p<=rg; p++)
            {
                int q=0;
                for(int a=0; a<n; a++) q+=(l[a][p]>=lg and r[a][p]<=rg);
                int cu=q*q;
                if(p!=lg) cu+=dp[lg][p-1];
                if(p!=rg) cu+=dp[p+1][rg];
                dp[lg][rg]=max(dp[lg][rg], cu);
            }
        }
    }
    cout<<dp[0][m-1];
}