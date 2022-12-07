#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10, mod=1e9+7;
int dp[sz][sz*2];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n-1];
    for(int a=0; a<n-1; a++) cin>>ar[a];
    for(int a=0; a<n; a++)
    {
        dp[a][0]=0, dp[a][1]=0;
        if(a!=0) dp[a][1]=1;
        int q=1;
        for(int b=2; b<=2*n; b++)
        {
            if(a!=0)
            {
                dp[a][b]=dp[a-1][b-1]-q;
                if(dp[a][b]<0) dp[a][b]+=mod;
            }
            dp[a][b-2]=(dp[a][b-2]+q)%mod;
            if(a+b-2<n-1) q=(1ll*q*ar[a+b-2])%mod;
            else q=0;
        }
    }
    for(int a=1; a<=2*n-2; a++)
    {
        int q=1, an=0;
        for(int b=0; b<n; b++)
        {
            an=(an+1ll*q*dp[b][a])%mod;
            if(b!=n-1) q=(1ll*q*ar[b])%mod;
        }
        if(an%2) an+=mod;
        cout<<an/2<<" ";
    }
}