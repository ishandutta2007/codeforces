#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <pair <int, int> > sv[sz];
int cnu[sz], csi[sz], cq=0;
void dfs(int v)
{
    cnu[v]=cq, csi[cq]++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, ty=sv[v][a].second;
        if(cnu[ne]==-1 and ty) dfs(ne);
    }
}
int us[sz], q, su;
void dfs2(int v)
{
    us[v]=1, q++, su+=csi[cnu[v]];
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, ty=sv[v][a].second;
        if(us[ne]==0 and ty==0) dfs2(ne);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v, ty;
        scanf("%d%d%d", &u, &v, &ty);
        u--, v--;
        sv[u].push_back({v, ty});
        sv[v].push_back({u, ty});
    }
    for(int a=0; a<n; a++) cnu[a]=-1;
    for(int a=0; a<n; a++) if(cnu[a]==-1) dfs(a), cq++;
    long long an=0;
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            q=0, su=0, dfs2(a);
            an+=1ll*q*(su-1);
        }
    }
    cout<<an;
}