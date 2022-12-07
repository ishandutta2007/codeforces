#include <bits/stdc++.h>
using namespace std;
const int sz=105, mod=1e9+7;
int si[sz], dp[sz][sz][sz], dp2[sz][sz], tr[sz][sz];
vector <int> sv[sz];
void dfs(int v, int pr)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs(ne, v);
    }
    dp[v][1][0]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            for(int b=1; b<=si[v]; b++)
            {
                for(int c=0; c<si[v]; c++)
                {
                    for(int d=1; d<=si[ne]; d++)
                    {
                        for(int e=0; e<si[ne]; e++)
                        {
                            dp2[b+d][c+e]=(dp2[b+d][c+e]+1ll*dp[v][b][c]*dp[ne][d][e])%mod;
                            dp2[b][c+e+1]=(dp2[b][c+e+1]+1ll*dp[v][b][c]*((1ll*dp[ne][d][e]*d)%mod))%mod;
                        }
                    }
                }
            }
            si[v]+=si[ne];
            for(int b=1; b<=si[v]; b++)
            {
                for(int c=0; c<si[v]; c++)
                {
                    dp[v][b][c]=dp2[b][c], dp2[b][c]=0;
                }
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<=n; a++)
    {
        tr[a][0]=1, tr[a][a]=1;
        for(int b=1; b<a; b++) tr[a][b]=(tr[a-1][b-1]+tr[a-1][b])%mod;
    }
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, -1);
    int an[n];
    an[n-1]=1;
    for(int a=n-2; a>=0; a--)
    {
        an[a]=0;
        for(int b=1; b<=n; b++) an[a]=(an[a]+1ll*dp[0][b][n-a-1]*b)%mod;
        for(int b=0; b<(n-a-2); b++) an[a]=(1ll*an[a]*n)%mod;
        for(int b=a+1; b<n; b++)
        {
            an[a]-=(1ll*an[b]*tr[b][a])%mod;
            if(an[a]<0) an[a]+=mod;
        }
    }
    for(int a=0; a<n; a++) cout<<an[a]<<" ";
}