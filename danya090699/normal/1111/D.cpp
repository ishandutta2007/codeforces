#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7, sz=1e5+10;
int fact[sz], rfact[sz];
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
    string s;
    cin>>s;
    int n=s.size();

    fact[0]=1;
    for(int a=1; a<=n; a++) fact[a]=(1ll*fact[a-1]*a)%mod;
    for(int a=0; a<=n; a++) rfact[a]=po(fact[a], mod-2);

    map <char, int> ma;
    for(int a=0; a<n; a++) ma[s[a]]++;
    int m=0, q[ma.size()];
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        q[m]=(*it).second, (*it).second=m, m++;
    }
    int an[m][m], n2=n/2, x=(1ll*fact[n2]*fact[n2])%mod;
    for(int a=0; a<m; a++) x=(1ll*x*rfact[q[a]])%mod;
    for(int a=0; a<m; a++)
    {
        int dp[m+1][n2+1];
        for(int b=0; b<=m; b++) for(int c=0; c<=n2; c++) dp[b][c]=0;
        dp[0][0]=1;
        for(int b=0; b<m; b++)
        {
            for(int c=0; c<=n2; c++)
            {
                if(dp[b][c])
                {
                    dp[b+1][c]+=dp[b][c];
                    if(dp[b+1][c]>=mod) dp[b+1][c]-=mod;

                    if(b!=a and c+q[b]<=n2)
                    {
                        dp[b+1][c+q[b]]+=dp[b][c];
                        if(dp[b+1][c+q[b]]>=mod) dp[b+1][c+q[b]]-=mod;
                    }
                }
            }
        }
        int dpr[n2+1], dpr2[n2+1];
        for(int b=0; b<=n2; b++) dpr[b]=0, dpr2[b]=0;
        dpr[0]=1;
        for(int b=m-1; b>=a; b--)
        {
            an[a][b]=0;
            for(int c=0; c<=n2; c++)
            {
                if(dpr[c])
                {
                    int add=(1ll*dpr[c]*dp[b][n2-c])%mod;

                    an[a][b]=(an[a][b]+1ll*x*add)%mod;

                    dpr2[c]+=dpr[c];
                    if(dpr2[c]>=mod) dpr2[c]-=mod;

                    if(b!=a and c+q[b]<=n2)
                    {
                        dpr2[c+q[b]]+=dpr[c];
                        if(dpr2[c+q[b]]>=mod) dpr2[c+q[b]]-=mod;
                    }
                }
            }
            for(int c=0; c<=n2; c++) dpr[c]=dpr2[c], dpr2[c]=0;

            an[a][b]=(an[a][b]*2)%mod;
        }
    }

    int qq;
    cin>>qq;
    for(int a=0; a<qq; a++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        x=ma[s[x]], y=ma[s[y]];
        if(x>y) swap(x, y);
        printf("%d\n", an[x][y]);
    }
}