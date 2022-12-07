#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, an=0;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int i=60; i>=0; i--)
    {
        int dp[n+1][k+1], x=an+(1ll<<i);
        for(int a=0; a<=n; a++) for(int b=0; b<=k; b++) dp[a][b]=0;
        dp[0][0]=1;
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<k; b++)
            {
                if(dp[a][b])
                {
                    int su=0;
                    for(int c=a; c<n; c++)
                    {
                        su+=ar[c];
                        if((su&x)==x) dp[c+1][b+1]=1;
                    }
                }
            }
        }
        if(dp[n][k]) an=x;
    }
    cout<<an;
}