#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, p;
    cin>>n>>p;
    int st[n+1];
    st[0]=1;
    for(int a=1; a<=n; a++) st[a]=(st[a-1]*2)%mod;
    int dp[n+1][n+1][n+1];
    for(int a=0; a<=n; a++) for(int b=0; b<=n; b++) for(int c=0; c<=n; c++) dp[a][b][c]=0;
    dp[0][0][0]=1;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        for(int b=0; b<=a; b++)
        {
            for(int c=0; b+c<=a; c++)
            {
                if(x==0 or x==-1)
                {
                    int va=(1ll*st[a-b-c]*dp[a][b][c])%mod;
                    va=(1ll*va*st[b])%mod;
                    if(c==0) dp[a+1][b+1][c]=(dp[a+1][b+1][c]+va)%mod;
                    else
                    {
                        dp[a+1][b][c]=(dp[a+1][b][c]+1ll*va*st[c-1])%mod;
                        dp[a+1][b+1][c]=(dp[a+1][b+1][c]+1ll*va*st[c-1])%mod;
                    }

                }
                if(x==1 or x==-1)
                {
                    int va=(1ll*st[a-b-c]*dp[a][b][c])%mod;
                    va=(1ll*va*st[c])%mod;
                    if(b==0) dp[a+1][b][c+1]=(dp[a+1][b][c+1]+va)%mod;
                    else
                    {
                        dp[a+1][b][c]=(dp[a+1][b][c]+1ll*va*st[b-1])%mod;
                        dp[a+1][b][c+1]=(dp[a+1][b][c+1]+1ll*va*st[b-1])%mod;
                    }
                }
            }
        }
    }
    int an=0;
    for(int a=0; a<=n; a++)
    {
        for(int b=0; b+a<=n; b++)
        {
            if((a+b)%2==p) an=(an+dp[n][a][b])%mod;
        }
    }
    cout<<an;
}