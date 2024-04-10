#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], us[n], q0=n/2, q1=n-q0;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
    }
    int dp[n+1][n+1][n+1][2];
    for(int a=0; a<=n; a++)
    {
        for(int q0=0; q0<=n; q0++)
        {
            for(int q1=0; q1<=n; q1++)
            {
                for(int i=0; i<2; i++) dp[a][q0][q1][i]=inf;
            }
        }
    }
    //cout<<q0<<" "<<q1<<"\n";
    dp[0][q0][q1][0]=0, dp[0][q0][q1][1]=0;
    for(int a=0; a<n; a++)
    {
        int l=0, r=1;
        if(ar[a]!=0) l=ar[a]&1, r=l;
        for(int q0=0; q0<=n; q0++)
        {
            for(int q1=0; q1<=n; q1++)
            {
                for(int i=0; i<2; i++)
                {
                    int va=dp[a][q0][q1][i];
                    //cout<<va<<"\n";
                    if(va!=inf)
                    {
                        //cout<<a;
                        for(int j=l; j<=r; j++)
                        {
                            if(j==0 and q0)
                            {
                                dp[a+1][q0-1][q1][j]=min(dp[a+1][q0-1][q1][j], va+(i^j));
                            }
                            if(j==1 and q1)
                            {
                                dp[a+1][q0][q1-1][j]=min(dp[a+1][q0][q1-1][j], va+(i^j));
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<min(dp[n][0][0][0], dp[n][0][0][1]);
}