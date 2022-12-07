#include <bits/stdc++.h>
using namespace std;
const int sz=201, mod=998244353;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int dp[sz][2], dp2[sz][2];
    for(int a=0; a<sz; a++) for(int i=0; i<2; i++) dp[a][i]=0, dp2[a][i]=0;
    dp[0][0]=1;
    for(int a=0; a<n; a++)
    {
        int x, su=(dp[0][0]+dp[0][1])%mod;
        scanf("%d", &x);
        dp2[0][0]=0, dp2[0][1]=0;
        for(int b=1; b<sz; b++)
        {
            if(x==-1 or x==b) dp2[b][0]=su;
            else dp2[b][0]=0;
            su=(su+dp[b][0])%mod;
            su=(su+dp[b][1])%mod;

        }
        su=0;
        for(int b=sz-1; b>0; b--)
        {
            su=(su+dp[b][1])%mod;
            if(x==-1 or x==b) dp2[b][1]=(su+dp[b][0])%mod;
            else dp2[b][1]=0;
        }
        for(int b=0; b<sz; b++) for(int i=0; i<2; i++) dp[b][i]=dp2[b][i], dp2[b][i]=0;

    }
    int an=0;
    for(int a=1; a<sz; a++) an=(an+dp[a][1])%mod;
    cout<<an;
}