#include <bits/stdc++.h>
using namespace std;
const int sz=2e3+10, mod=1e9+7;
int dp[2][sz][sz], suf[2][sz][sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    if(n==1 and m==1)
    {
        cout<<1;
        return 0;
    }
    for(int a=0; a<n; a++)
    {
        char s[m+1];
        scanf("%s", s);
        for(int b=0; b<m; b++) if(s[b]=='R') suf[0][a][b]++, suf[1][b][a]++;
        for(int b=m-2; b>=0; b--) suf[0][a][b]+=suf[0][a][b+1];
    }
    for(int a=0; a<m; a++)
    {
        for(int b=n-2; b>=0; b--) suf[1][a][b]+=suf[1][a][b+1];
    }
    dp[0][0][0]=1, dp[1][0][0]=1;
    for(int l=0; l<n+m-1; l++)
    {
        for(int a=0; a<n; a++)
        {
            int b=l-a;
            if(b>=0 and b<m)
            {
                if(b and (a or (b>1))) dp[0][a][b]=(dp[0][a][b]+dp[0][a][b-1])%mod;
                if(a and (b or (a>1))) dp[1][a][b]=(dp[1][a][b]+dp[1][a-1][b])%mod;

                int va=dp[0][a][b];
                //if(va) cout<<"0 "<<a<<" "<<b<<": "<<va<<"\n";
                if(va and a<n)
                {
                    dp[1][a+1][b]=(dp[1][a+1][b]+va)%mod;
                    if(suf[1][b][a+1])
                    {
                        //cout<<"!";
                        int r=n-suf[1][b][a+1];
                        dp[1][r][b]-=va;
                        if(dp[1][r][b]<0) dp[1][r][b]+=mod;
                    }
                }
                va=dp[1][a][b];
                //if(va) cout<<"1 "<<a<<" "<<b<<": "<<va<<"\n";
                if(va and b<m)
                {
                    dp[0][a][b+1]=(dp[0][a][b+1]+va)%mod;
                    if(suf[0][a][b+1])
                    {
                        int r=m-suf[0][a][b+1];
                        dp[0][a][r]-=va;
                        if(dp[0][a][r]<0) dp[0][a][r]+=mod;
                    }
                }
            }
        }
    }
    cout<<(dp[0][n-1][m-1]+dp[1][n-1][m-1])%mod;
}