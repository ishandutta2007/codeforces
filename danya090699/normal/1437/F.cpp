#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    sort(ar, ar+n, greater <int>());
    int to[n], add[n];
    for(int a=0; a<n; a++)
    {
        to[a]=a+1;
        add[a]=1;
        while(to[a]<n and ar[to[a]]*2>ar[a])
        {
            add[a]=1ll*add[a]*(to[a]-1)%mod;
            to[a]++;
        }
    }
    int dp[n+1];
    for(int a=0; a<=n; a++) dp[a]=0;
    dp[0]=1;
    for(int a=0; a<n; a++)
    {
        int x=dp[a];
        for(int b=a; b<n; b++)
        {
            dp[to[b]]=(dp[to[b]]+1ll*x*add[b])%mod;
            x=1ll*x*b%mod;
        }
    }
    int an=dp[n], x=1;
    for(int a=n-1; a; a--)
    {
        x=1ll*x*a%mod;
        an=(an+1ll*x*dp[a])%mod;
    }
    cout<<an;
}