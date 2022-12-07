#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz], sp[2];
int n, m, k, us[sz], h[sz], pr[sz], u=-1;
void dfs(int v)
{
    sp[h[v]&1].push_back(v);
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(!us[ne])
        {
            pr[ne]=v, h[ne]=h[v]+1, dfs(ne);
        }
        else if(ne!=pr[v] and h[ne]<h[v])
        {
            if(h[v]-h[ne]+1<=k)
            {
                cout<<2<<"\n"<<h[v]-h[ne]+1<<"\n";
                while(1)
                {
                    printf("%d ", v+1);
                    if(v==ne) break;
                    v=pr[v];
                }
                exit(0);
            }
            else u=v;
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m>>k;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0);
    cout<<1<<"\n";
    if(u!=-1)
    {
        for(int a=0; a<(k+1)/2; a++)
        {
            printf("%d ", u+1);
            u=pr[pr[u]];
        }
    }
    else
    {
        int i=(sp[0].size()>sp[1].size()) ? 0 : 1;
        for(int a=0; a<(k+1)/2; a++) printf("%d ", sp[i][a]+1);
    }
}