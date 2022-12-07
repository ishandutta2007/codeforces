#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10, mod=1e9+7;
int dp[sz][sz];
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, an=0;
    cin>>n>>k;
    dp[0][0]=1;
    for(int a=0; a<k; a++)
    {
        for(int b=0; b<=min(a, n); b++)
        {
            dp[a+1][b]=(dp[a+1][b]+1ll*b*dp[a][b])%mod;
            if(b+1<=n) dp[a+1][b+1]=(dp[a+1][b+1]+1ll*(n-b)*dp[a][b])%mod;
        }
    }
    for(int a=0; a<=min(k, n); a++)
    {
        an=(an+1ll*dp[k][a]*po(2, n-a))%mod;
    }
    cout<<an;
}