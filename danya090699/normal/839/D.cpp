//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10, mod=1e9+7;
int q[sz], q2[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    for(int a=0; a<sz; a++)
    {
        q[a]=0, q2[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        q[x]++;
    }
    long long dp[n+1][2];
    dp[0][0]=1, dp[0][1]=0;
    for(int a=0; a<n; a++)
    {
        dp[a+1][0]=(dp[a][0]*2)%mod;
        dp[a+1][1]=(0ll+dp[a][1]+dp[a][1]+dp[a][0])%mod;
    }
    for(int a=sz-1; a>=2; a--)
    {
        int cq=0;
        for(int b=a; b<sz; b+=a) cq+=q[b];
        q2[a]=dp[cq][1];
        for(int b=a+a; b<sz; b+=a)
        {
            q2[a]-=q2[b];
            if(q2[a]<0) q2[a]+=mod;
        }
        an+=(1ll*q2[a]*a)%mod;
        an%=mod;
    }
    cout<<an;
}