#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int f(int x, int k)
{
    vector <int> ch;
    if(x==0) ch.push_back(0);
    while(x) ch.push_back(x%10), x/=10;
    reverse(ch.begin(), ch.end());
    int n=ch.size();
    int dp[n+1][1<<10][2], dp2[n+1][1<<10][2];
    for(int a=0; a<=n; a++) for(int b=0; b<(1<<10); b++) for(int i=0; i<2; i++) dp[a][b][i]=0, dp2[a][b][i]=0;
    dp[0][0][0]=1, dp2[0][0][0]=0;
    for(int a=0; a<n; a++)
    {
        int st=1;
        for(int b=0; b<n-a-1; b++) st=(1ll*st*10)%mod;
        for(int b=0; b<(1<<10); b++)
        {
            for(int i=0; i<2; i++)
            {
                for(int c=0; c<10; c++)
                {
                    int cu=(1ll*st*c)%mod;
                    int nb=(b|(1<<c));
                    if(b==0 and c==0) nb=0;
                    if(i==0)
                    {
                        if(ch[a]==c)
                        {
                            dp[a+1][nb][0]=(dp[a+1][nb][0]+dp[a][b][i])%mod;
                            dp2[a+1][nb][0]=(dp2[a+1][nb][0]+dp2[a][b][i]+1ll*dp[a][b][i]*cu)%mod;
                        }
                        else if(ch[a]>c)
                        {
                            dp[a+1][nb][1]=(dp[a+1][nb][1]+dp[a][b][i])%mod;
                            dp2[a+1][nb][1]=(dp2[a+1][nb][1]+dp2[a][b][i]+1ll*dp[a][b][i]*cu)%mod;
                        }
                    }
                    else
                    {
                        dp[a+1][nb][1]=(dp[a+1][nb][1]+dp[a][b][i])%mod;
                        dp2[a+1][nb][1]=(dp2[a+1][nb][1]+dp2[a][b][i]+1ll*dp[a][b][i]*cu)%mod;
                    }
                }
            }
        }
    }
    int an=0;
    for(int a=0; a<(1<<10); a++)
    {
        if(__builtin_popcount(a)<=k)
        {
            for(int i=0; i<2; i++) an=(an+dp2[n][a][i])%mod;
        }
    }
    return an;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int l, r, k;
    cin>>l>>r>>k;
    int re=f(r, k)-f(l-1, k);
    if(re<0) re+=mod;
    cout<<re;
}