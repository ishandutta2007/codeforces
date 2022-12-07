#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e6+10, sz2=1e5+10;
vector <pair <int, int> > sv[sz], sv2[sz];
vector <int> svr[sz], tout;
bool us[sz];
int cq=0, cnu[sz], csi[sz], dp[sz];
int f[sz2], f2[sz2];
void dfs(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first;
        if(us[ne]==0) dfs(ne);
    }
    tout.push_back(v);
}
void dfsr(int v)
{
    cnu[v]=cq;
    for(int a=0; a<svr[v].size(); a++)
    {
        int ne=svr[v][a];
        if(cnu[ne]==-1) dfsr(ne);
    }
}
int get(int v)
{
    if(dp[v]==-1)
    {
        dp[v]=-2;
        for(int a=0; a<sv2[v].size(); a++)
        {
            int ne=sv2[v][a].first, va=sv2[v][a].second;
            int x=get(ne);
            if(x!=-2) dp[v]=max(dp[v], csi[v]+va+get(ne));
        }
    }
    return dp[v];
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v, pri;
        scanf("%lld%lld%lld", &u, &v, &pri);
        u--, v--;
        sv[u].push_back(make_pair(v, pri));
        svr[v].push_back(u);
    }
    for(int a=0; a<n; a++)
    {
        cnu[a]=-1;
        if(us[a]==0) dfs(a);
    }
    for(int a=0; a<n; a++)
    {
        int v=tout.back();
        if(cnu[v]==-1)
        {
            dp[cq]=-1;
            dfsr(v), cq++;
        }
        tout.pop_back();
    }
    f[1]=0, f2[1]=0;
    for(int a=2; a<sz2; a++)
    {
        f[a]=f[a-1]+(a-1);
        f2[a]=f[a]+f2[a-1];
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int v=sv[a][b].first, va=sv[a][b].second;
            if(cnu[v]==cnu[a])
            {
                int l=0, r=sz2;
                while(r-l>1)
                {
                    int mid=(l+r)>>1;
                    if(f[mid]<=va) l=mid;
                    else r=mid;
                }
                csi[cnu[v]]+=l*va-f2[l];
            }
            else sv2[cnu[v]].push_back(make_pair(cnu[a], va));
        }
    }
    int s, an=0;
    cin>>s;
    dp[cnu[s-1]]=csi[cnu[s-1]];
    for(int a=0; a<cq; a++)
    {
        an=max(an, get(a));
    }
    cout<<an;
}