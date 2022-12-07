#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int dp[n+1][n+1], tr[n+1][n+1], st[n+1], st2[n+1];
    st[0]=1, st2[0]=1;
    for(int a=1; a<=n; a++)
    {
        st[a]=(1ll*st[a-1]*k)%mod;
        st2[a]=(1ll*st2[a-1]*(k-1))%mod;
    }
    for(int a=0; a<=n; a++)
    {
        tr[a][0]=1, tr[a][a]=1;
        for(int b=1; b<a; b++) tr[a][b]=(tr[a-1][b-1]+tr[a-1][b])%mod;

        for(int b=0; b<=n; b++) dp[a][b]=0;
    }
    dp[0][0]=1;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<=n; b++)
        {
            if(dp[a][b])
            {
                //cout<<a<<" "<<b<<" "<<dp[a][b]<<"\n";
                int c=0;
                if(b==0) c=1;
                //cout<<c;
                for(c; c+b<=n; c++)
                {
                    int v1=(1ll*tr[n-b][c]*st2[n-b-c])%mod;
                    int v2=st[b];
                    if(c==0) v2-=st2[b];
                    if(v2<0) v2+=mod;
                    int add=(1ll*v1*v2)%mod;
                    ///cout<<v1<<" "<<v2;
                    dp[a+1][b+c]=(dp[a+1][b+c]+1ll*dp[a][b]*add)%mod;
                }
            }
        }
    }
    cout<<dp[n][n];
}