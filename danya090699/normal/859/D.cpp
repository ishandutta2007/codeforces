#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int m=(1<<n);
    int sm[m][m];
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<m; b++) cin>>sm[a][b];
    }
    double pro[n+1][m][m], dp[n+1][m][m];
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<m; b++)
        {
            if(a==b) pro[n][a][b]=1;
            else pro[n][a][b]=0;
            dp[n][a][b]=0;
        }
    }
    for(int a=n-1; a>=0; a--)
    {
        for(int b=0; b<(1<<a); b++)
        {
            for(int c=0; c<m; c++)
            {
                pro[a][b][c]=0;
                for(int d=0; d<m; d++)
                {
                    pro[a][b][c]+=pro[a+1][2*b][c]*pro[a+1][2*b+1][d]*(sm[c][d]/100.0);
                    pro[a][b][c]+=pro[a+1][2*b][d]*pro[a+1][2*b+1][c]*(sm[c][d]/100.0);
                }
            }
        }
        for(int b=0; b<(1<<a); b++)
        {
            for(int c=0; c<m; c++)
            {
                dp[a][b][c]=0;
                for(int d=0; d<m; d++)
                {
                    dp[a][b][c]=max(dp[a][b][c], dp[a+1][2*b][c]+dp[a+1][2*b+1][d]);
                    dp[a][b][c]=max(dp[a][b][c], dp[a+1][2*b][d]+dp[a+1][2*b+1][c]);
                }
                dp[a][b][c]+=pro[a][b][c]*(1<<(n-a-1));
            }
        }
    }
    double an=0;
    for(int a=0; a<m; a++) an=max(an, dp[0][0][a]);
    cout<<fixed<<setprecision(10)<<an;
}