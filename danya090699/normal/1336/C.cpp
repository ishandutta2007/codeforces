#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
main()
{
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin>>s>>t;
    int n=s.size(), m=t.size(), dp[n+1], dp2[n+1], an=0;
    for(int a=0; a<=n; a++) dp[a]=1, dp2[a]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b+a<=n; b++)
        {
            //if(dp[b]) cout<<b<<" "<<b+a<<" "<<dp[b]<<"\n";
            if(b)
            {
                if(b-1>=m or s[a]==t[b-1]) dp2[b-1]=(dp2[b-1]+dp[b])%mod;
            }
            if(b+a<n)
            {
                if(b+a>=m or s[a]==t[b+a]) dp2[b]=(dp2[b]+dp[b])%mod;
            }
        }
        for(int b=0; b<=n; b++) dp[b]=dp2[b], dp2[b]=0;
        if(a+1>=m) an=(an+dp[0])%mod;
    }
    cout<<an;
}