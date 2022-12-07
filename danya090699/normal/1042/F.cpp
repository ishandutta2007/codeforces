#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10, inf=1e9;
vector <int> sv[sz];
int n, k, an=0, dp[sz];
void dfs(int v, int pr)
{
    int mi=inf, ma=-inf, smq=0;
    if(sv[v].size()==1) dp[v]=1, an++;
    else
    {
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a];
            if(ne!=pr)
            {
                dfs(ne, v);
                if(dp[ne]<=k/2) ma=max(ma, dp[ne]), smq++;
                else mi=min(mi, dp[ne]);
            }
        }
        if(smq) an-=smq-1;
        if(mi!=inf and ma!=-inf)
        {
            if(mi+ma<=k) an--, dp[v]=mi+1;
            else dp[v]=ma+1;
        }
        else if(mi!=inf) dp[v]=mi+1;
        else dp[v]=ma+1;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=0; a<n; a++)
    {
        if(sv[a].size()>1)
        {
            dfs(a, a);
            break;
        }
    }
    cout<<an;
}