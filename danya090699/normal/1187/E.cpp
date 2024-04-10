#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz];
int n, si[sz], dow[sz], up[sz];
void dfs(int v, int pr)
{
    si[v]=1, dow[v]=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs(ne, v), si[v]+=si[ne], dow[v]+=dow[ne];
    }
    dow[v]+=si[v];
}
void dfs2(int v, int pr)
{
    int su=up[v];
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) su+=dow[ne];
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            up[ne]=su-dow[ne]+(n-si[ne])+(si[v]-si[ne]);
            dfs2(ne, v);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, 0), dfs2(0, 0);
    int an=0;
    for(int a=0; a<n; a++) an=max(an, dow[a]+up[a]);
    cout<<an;
}