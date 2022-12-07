#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int po(int x, int y, int mod)
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
int f2(int a, int b, int mod)//a  mod 
{
    int n=sqrt(mod)+1;
    map <int, int> ma;
    int x=1;
    for(int i=0; i<n; i++) x=(1ll*x*a)%mod;
    for(int i=1, cu=x; i<=n; i++)
    {
        ma[cu]=i, cu=(1ll*cu*x)%mod;
    }
    for(int i=0, cu=b; i<=n; i++, cu=(1ll*cu*a)%mod)
    {
        if(ma.count(cu)) return ma[cu]*n-i;
    }
    return -1;
}
int f(int a, int k, int mod)//mod 
{
    int g=3;
    int y=f2(po(g, k, mod), a, mod);
    if(y!=-1) return po(g, y, mod);
    else return -1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int k;
    cin>>k;
    int dp[k], ma[k][k];
    for(int a=0; a<k; a++)
    {
        dp[a]=0;
        for(int b=0; b<k; b++) ma[a][b]=0;
    }
    dp[k-1]=1;
    for(int a=0; a<k; a++)
    {
        cin>>ma[k-1-a][k-1];
        if(a) ma[a][a-1]=1;
    }
    int n, m;
    cin>>n>>m;
    n-=k;
    while(n)
    {
        if(n&1)
        {
            int dp2[k];
            for(int a=0; a<k; a++) dp2[a]=0;
            for(int a=0; a<k; a++)
            {
                for(int b=0; b<k; b++) dp2[b]=(dp2[b]+1ll*dp[a]*ma[a][b])%(mod-1);
            }
            for(int a=0; a<k; a++) dp[a]=dp2[a];
        }
        n>>=1;
        int te[k][k];
        for(int a=0; a<k; a++)
        {
            for(int b=0; b<k; b++)
            {
                te[a][b]=0;
                for(int c=0; c<k; c++) te[a][b]=(te[a][b]+1ll*ma[a][c]*ma[c][b])%(mod-1);
            }
        }
        for(int a=0; a<k; a++) for(int b=0; b<k; b++) ma[a][b]=te[a][b];
    }
    cout<<f(m, dp[k-1], mod);
}