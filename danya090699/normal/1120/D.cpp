#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz];
int va[sz], dp[sz][2], us[sz][2], ok[sz], an=0;
void dfs(int v, int pr)
{
    int su=0, ma=0, chq=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v), chq++;
            su+=dp[ne][0], ma=max(ma, dp[ne][0]-dp[ne][1]);
        }
    }
    dp[v][1]=su-ma;
    if(chq) dp[v][0]=min(va[v]+dp[v][1], su);
    else dp[v][0]=va[v];
}
void dfs2(int v, int pr)
{
    int su=0, ma=0, q=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            su+=dp[ne][0];
            int dif=dp[ne][0]-dp[ne][1];
            if(dif>ma) ma=dif, q=1;
            else if(dif==ma) q++;
        }
    }
    if(us[v][0] and va[v]+dp[v][1]==dp[v][0]) ok[v]=1, an++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            int dif=dp[ne][0]-dp[ne][1];
            if(us[v][1] or va[v]+dp[v][1]==dp[v][0])
            {
                if(dif==ma) us[ne][1]=1;
                if(dif<ma or (dif==ma and q>1)) us[ne][0]=1;
            }
            if(us[v][0] and su==dp[v][0]) us[ne][0]=1;

            dfs2(ne, v);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++) scanf("%lld", &va[a]);
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, 0), us[0][0]=1, dfs2(0, 0);
    cout<<dp[0][0]<<" "<<an<<"\n";
    for(int a=0; a<n; a++) if(ok[a]) printf("%lld ", a+1);
}