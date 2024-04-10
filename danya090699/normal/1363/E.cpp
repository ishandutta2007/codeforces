#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz];
int su[sz], w[sz];
long long an=0;
void dfs(int v, int pr)
{
    int tot=abs(su[v]);
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            w[ne]=min(w[ne], w[v]), dfs(ne, v);
            su[v]+=su[ne], tot+=abs(su[ne]);
        }
    }
    an+=1ll*w[v]*(tot-abs(su[v]));
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x, y;
        scanf("%d%d%d", &w[a], &x, &y);
        su[a]=x-y;
    }
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, 0);
    if(su[0]==0) cout<<an;
    else cout<<-1;
}