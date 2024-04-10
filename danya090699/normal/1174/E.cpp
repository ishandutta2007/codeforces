#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int st=0;
    while((1<<(st+1))<=n) st++;
    int dp[st+1], dp2[st+1];
    for(int a=0; a<=st; a++) dp[a]=0, dp2[a]=0;
    dp[st]=1;
    for(int a=1; a<n; a++)
    {
        for(int b=0; b<=st; b++)
        {
            int va=dp[b];
            if(va)
            {
                int q=n/(1<<b);
                if(q>a) dp2[b]=(dp2[b]+1ll*va*(q-a))%mod;
                if(b)
                {
                    int q2=n/(1<<(b-1))-q;
                    dp2[b-1]=(dp2[b-1]+1ll*va*q2)%mod;
                }
            }
        }
        for(int b=0; b<=st; b++) dp[b]=dp2[b], dp2[b]=0;
    }
    int an=dp[0];
    if((1<<(st-1))*3<=n)
    {
        int dp[st][2], dp2[st][2];
        for(int a=0; a<st; a++) for(int i=0; i<2; i++) dp[a][i]=0, dp2[a][i]=0;
        dp[st-1][1]=1;
        for(int a=1; a<n; a++)
        {
            for(int b=0; b<st; b++)
            {
                for(int i=0; i<2; i++)
                {
                    int va=dp[b][i];
                    if(va)
                    {
                        int x=(1<<b);
                        if(i) x*=3;

                        int q=n/x;
                        if(q>a) dp2[b][i]=(dp2[b][i]+1ll*va*(q-a))%mod;
                        if(b)
                        {
                            int q2=n/(x/2)-q;
                            dp2[b-1][i]=(dp2[b-1][i]+1ll*va*q2)%mod;
                        }

                        if(i)
                        {
                            int q=n/(1<<b)-n/((1<<b)*3);
                            dp2[b][0]=(dp2[b][0]+1ll*va*q)%mod;
                        }
                    }
                }
            }
            for(int b=0; b<st; b++) for(int i=0; i<2; i++) dp[b][i]=dp2[b][i], dp2[b][i]=0;

            //cout<<dp[0][0]<<" "<<dp[0][1]<<"\n";
        }
        an=(an+dp[0][0])%mod;
    }
    cout<<an;
}