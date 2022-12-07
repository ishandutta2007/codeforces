#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e5+10;
vector <pair <int, int> > sv[sz];
bool ok=1;
int us[sz], va[sz], su[2], nu=-1, an[sz];
void dfs(int v, int h)
{
    us[v]=h, su[h]+=va[v];
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first;
        if(us[ne]==-1) dfs(ne, (h+1)%2);
        else if(us[v]==us[ne]) nu=sv[v][a].second;
    }
}
void dfs2(int v, int pr)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, num=sv[v][a].second;
        if(us[ne]==0)
        {
            dfs2(ne, num);
            va[v]-=an[num];
        }
    }
    if(pr!=-1) an[pr]=va[v];
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<n; a++)
    {
        us[a]=-1;
        scanf("%lld", &va[a]);
    }
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        sv[u].push_back(make_pair(v, a));
        sv[v].push_back(make_pair(u, a));
    }
    dfs(0, 0);
    if(nu==-1)
    {
        if(su[0]==su[1]) dfs2(0, -1);
        else ok=0;
    }
    else
    {
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<sv[a].size(); b++)
            {
                int v=sv[a][b].first;
                if(sv[a][b].second==nu and v<a)
                {
                    int di=su[us[a]^1]-su[us[a]];
                    if(abs(di)%2==0)
                    {
                        an[nu]=-di/2, va[a]+=di/2, va[v]+=di/2;
                    }
                    else ok=0;
                }
            }
        }
    }
    if(ok)
    {
        for(int a=0; a<n; a++) us[a]=0;
        dfs2(0, -1);
        cout<<"YES\n";
        for(int a=0; a<m; a++) printf("%lld\n", an[a]);
    }
    else cout<<"NO";
}