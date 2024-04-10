#include <bits/stdc++.h>
#define int long long
using namespace std;
int SUM(int x, int y, int mod)
{
    return (x+y<mod) ? x+y : x+y-mod;
}
int DIF(int x, int y, int mod)
{
    return (x-y>=0) ? x-y : x-y+mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, su=0;
    long long su2=0;
    cin>>n>>k;
    bool dp[n+1][k];
    for(int a=0; a<=n; a++) for(int b=0; b<k; b++) dp[a][b]=0;
    dp[0][0]=1;
    for(int a=0; a<n; a++)
    {
        int x, y;
        cin>>x>>y;
        for(int b=0; b<k; b++)
        {
            if(dp[a][b])
            {
                int b2=DIF(su, b, k);
                for(int c=0; c<k; c++)
                {
                    int c2=DIF((su+x+y)%k, c, k);
                    if(DIF(c, b, k)<=x and DIF(c2, b2, k)<=y) dp[a+1][c]=1;
                }
            }
        }
        su=(su+x+y)%k;
        su2+=x+y;
    }
    long long an=0;
    for(int a=0; a<k; a++)
    {
        if(dp[n][a])
        {
            int a2=DIF(su, a, k);
            an=max(an, (su2-a-a2)/k);
        }
    }
    cout<<an;
}