#include <bits/stdc++.h>
using namespace std;
const int nmax=1e5,mod=1e9+7;
long long t,k;
long long dp0[nmax+5],dp1[nmax+5],dp[nmax+5];///dp[i] = in cate mod poate manca "i" portii
int main()
{
    cin>>t>>k;
    dp0[1]=1;
    dp1[k]=1;
    dp[1]=dp0[1]+dp1[1];
    for(int i=2;i<=nmax;i++)
    {
        dp0[i]=(dp0[i-1]+dp1[i-1])%mod;
        if(i>k)
            dp1[i]=dp[i-k];
        dp[i]=(dp0[i]+dp1[i])%mod;
    }
    for(int i=1;i<=nmax;i++)
        dp[i]=(dp[i-1]+dp[i])%mod;
    while(t--)
    {
        int st,dr;
        cin>>st>>dr;
        cout<<(dp[dr]-dp[st-1]+mod)%mod<<"\n";
    }
    return 0;
}
/**
**/