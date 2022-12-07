#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int us[sz], pr[sz], h[sz], sq=1;
void dfs(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(!us[ne]) pr[ne]=v, h[ne]=h[v]+1, dfs(ne);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    while(sq*sq<n) sq++;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0);
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int u=a, v=sv[a][b];
            if(h[u]>h[v]) swap(u, v);
            if(h[v]-h[u]+1>=sq)
            {
                cout<<"2\n"<<h[v]-h[u]+1<<"\n";
                while(v!=u)
                {
                    printf("%d ", v+1), v=pr[v];
                }
                printf("%d", u+1);
                return 0;
            }
        }
    }
    vector <int> sp[sq-1];
    for(int a=0; a<n; a++) sp[h[a]%(sq-1)].push_back(a);
    cout<<"1\n";
    for(int a=0; a<sq-1; a++)
    {
        if(sp[a].size()>=sq)
        {
            for(int b=0; b<sq; b++) printf("%d ", sp[a][b]+1);
            return 0;
        }
    }
}