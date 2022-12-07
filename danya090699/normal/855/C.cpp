//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, mod=1e9+7;
vector <int> sv[sz];
int n, m, k, x;
int dp[11][sz][3], dp2[11][sz][3];
void dfs(int v, int pr)
{
    for(int a=0; a<=10; a++)
    {
        for(int b=0; b<3; b++)
        {
            dp[a][v][b]=0;
        }
    }
    dp[0][v][0]=k-1;
    dp[1][v][1]=1;
    dp[0][v][2]=m-k;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v);
            for(int b=0; b<=10; b++)
            {
                for(int c=0; c+b<=10; c++)
                {
                    int v0=(0ll+dp[c][ne][0]+dp[c][ne][1]+dp[c][ne][2])%mod;
                    int v1=dp[c][ne][0];
                    int v2=(dp[c][ne][0]+dp[c][ne][2])%mod;

                    dp2[c+b][v][0]+=(dp[b][v][0]*1ll*v0)%mod;
                    if(dp2[c+b][v][0]>=mod) dp2[c+b][v][0]-=mod;

                    dp2[c+b][v][1]+=(dp[b][v][1]*1ll*v1)%mod;
                    if(dp2[c+b][v][1]>=mod) dp2[c+b][v][1]-=mod;

                    dp2[c+b][v][2]+=(dp[b][v][2]*1ll*v2)%mod;
                    if(dp2[c+b][v][2]>=mod) dp2[c+b][v][2]-=mod;
                }
            }
            for(int b=0; b<=10; b++)
            {
                for(int c=0; c<3; c++)
                {
                    dp[b][v][c]=dp2[b][v][c];
                    dp2[b][v][c]=0;
                }
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    cin>>k>>x;
    dfs(0, -1);
    int an=0;
    for(int a=0; a<=x; a++)
    {
        for(int b=0; b<3; b++)
        {
            an+=dp[a][0][b];
            if(an>=mod) an-=mod;
        }
    }
    cout<<an;
}