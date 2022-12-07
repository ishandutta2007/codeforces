#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;
    int dp[n+1][k*2+1], pr[n+1][k*2+1];
    for(int a=0; a<=n; a++) for(int b=0; b<=k*2; b++) dp[a][b]=0;
    dp[0][k]=1;
    for(int a=0; a<n; a++)
    {
        char sy;
        cin>>sy;
        int add;
        if(sy=='W') add=1;
        if(sy=='L') add=-1;
        if(sy=='D') add=0;
        for(int b=1; b<k*2; b++)
        {
            if(dp[a][b])
            {
                if(sy=='?')
                {
                    for(int c=-1; c<=1; c++)
                    {
                        dp[a+1][b+c]=1;
                        pr[a+1][b+c]=c;
                    }
                }
                else
                {
                    dp[a+1][b+add]=1;
                    pr[a+1][b+add]=add;
                }
            }
        }
    }
    int cu=-1;
    if(dp[n][0]) cu=0;
    if(dp[n][k*2]) cu=k*2;
    if(cu==-1) cout<<"NO";
    else
    {
        char an[n];
        for(int a=n-1; a>=0; a--)
        {
            int add=pr[a+1][cu];
            if(add==1) an[a]='W';
            if(add==-1) an[a]='L';
            if(add==0) an[a]='D';
            cu-=add;
        }
        for(int a=0; a<n; a++) cout<<an[a];
    }
}