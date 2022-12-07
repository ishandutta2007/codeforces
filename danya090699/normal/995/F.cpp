#include <bits/stdc++.h>
using namespace std;
const int sz=3e3+10, mod=1e9+7;
int n, d, dp[sz][sz], tr[sz][sz];
vector <int> sv[sz];
void dfs(int v)
{
    int m=sv[v].size();
    int su[m];
    for(int a=0; a<m; a++) su[a]=0;
    for(int a=0; a<m; a++) dfs(sv[v][a]);
    for(int a=0; a<n; a++)
    {
        dp[v][a]=1;
        for(int b=0; b<m; b++)
        {
            int ne=sv[v][b];
            su[b]=(su[b]+dp[ne][a])%mod;
            dp[v][a]=(1ll*dp[v][a]*su[b])%mod;
        }
    }
}

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
int rev(int x){return po(x, mod-2);}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>d;
    for(int a=1; a<n; a++)
    {
        int v;
        cin>>v;
        sv[v-1].push_back(a);
    }
    dfs(0);
    for(int a=0; a<=n; a++)
    {
        tr[a][0]=1, tr[a][a]=1;
        for(int b=1; b<a; b++) tr[a][b]=(tr[a-1][b-1]+tr[a-1][b])%mod;
    }
    for(int a=1; a<n; a++) dp[0][a]=(dp[0][a]+dp[0][a-1])%mod;
    int x=1, an=0;
    for(int a=0; a<n; a++)
    {
        if(a<d)
        {
            x=(1ll*x*(d-a))%mod;
            x=(1ll*x*rev(a+1))%mod;
            for(int b=a-1; b>=0; b--)
            {
                int q=(1ll*dp[0][b]*tr[a+1][b+1])%mod;
                dp[0][a]-=q;
                if(dp[0][a]<0) dp[0][a]+=mod;
            }
            an=(an+1ll*dp[0][a]*x)%mod;
        }
        else break;
    }
    cout<<an;
}