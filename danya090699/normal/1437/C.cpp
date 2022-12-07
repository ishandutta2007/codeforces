#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[n];
        for(int a=0; a<n; a++) cin>>ar[a];
        int dp[n+1][n*2];
        for(int a=0; a<=n; a++) for(int b=0; b<n*2; b++) dp[a][b]=inf;
        dp[0][0]=0;
        sort(ar, ar+n);
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<n*2; b++)
            {
                for(int c=b+1; c<n*2; c++) dp[a+1][c]=min(dp[a+1][c], dp[a][b]+abs(ar[a]-c));
            }
        }
        int an=inf;
        for(int a=0; a<n*2; a++) an=min(an, dp[n][a]);
        cout<<an<<"\n";
    }
}