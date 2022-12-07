#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <pair <int, int> > sv[sz];
vector <int> nu[sz];
int us[sz], tout[sz], cu, timer;
void dfs(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, w=sv[v][a].second;
        if(us[ne]==0 and w>cu) dfs(ne);
    }
    tout[v]=timer++;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        sv[u].push_back({v, w});
        nu[u].push_back(a+1);
    }
    int l=-1, r=1e9+10;
    while(r-l>1)
    {
        int mid=(l+r)>>1, ok=1;
        for(int a=0; a<n; a++) tout[a]=-1, us[a]=0;
        timer=0, cu=mid;
        for(int a=0; a<n; a++)
        {
            if(us[a]==0) dfs(a);
        }
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<sv[a].size(); b++)
            {
                int u=a, v=sv[a][b].first, w=sv[a][b].second;
                if(w>cu and tout[u]<tout[v]) ok=0;
            }
        }
        if(ok) r=mid;
        else l=mid;
    }
    for(int a=0; a<n; a++) tout[a]=-1, us[a]=0;
    timer=0, cu=r;
    for(int a=0; a<n; a++)
        {
            if(us[a]==0) dfs(a);
        }
    vector <int> sp;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int u=a, v=sv[a][b].first, w=sv[a][b].second;
            if(w<=cu and tout[u]<tout[v]) sp.push_back(nu[a][b]);
        }
    }
    cout<<r<<" "<<sp.size()<<"\n";
    for(int a=0; a<sp.size(); a++) printf("%d ", sp[a]);
}