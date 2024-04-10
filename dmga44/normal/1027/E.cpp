#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mod 998244353
#define MAXN 505

ll dp[MAXN][MAXN][2],res,ac[MAXN][MAXN];

void solve(int n,int d)
{
    dp[0][d][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=min(i,d);j++)
        {
            if(j!=d)
            {
                dp[i][d][1]=(dp[i][d][1]+dp[i-j][d][1])%mod;
                dp[i][d][0]=(dp[i][d][0]+dp[i-j][d][0])%mod;
            }
            else
                dp[i][d][1]=(dp[i][d][1]+(dp[i-j][d][0]+dp[i-j][d][1]))%mod;
        }
    for(int i=0;i<=n;i++)
    {
        dp[i][d][0]=(dp[i][d][0]*2)%mod;
        dp[i][d][1]=(dp[i][d][1]*2)%mod;
    }
}

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll inter=qp(b,e/2);
    inter=(inter*inter)%mod;
    if(e&1)
        inter=(inter*b)%mod;
    return inter;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        solve(n,i);
    for(int i=n;i;i--)
        for(int j=1;j<=n;j++)
            ac[j][i]=(ac[j][i+1]+dp[j][i][1])%mod;
    for(int i=1;i<=n;i++)
    {
        ll c=dp[n][i][1];
        res=(res+(c*qp(2,n-1)))%mod;
        if(i*n>=k)
        {
            ll x=((k-1)/i)+1;
            res=(res+mod-((c*((ac[n][x]*qp(2,mod-2))%mod))%mod))%mod;
        }
    }
    db(res)

    return 0;
}