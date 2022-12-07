#include <bits/stdc++.h>
using namespace std;
int n, m, *an;
vector <int> *sv, *co;
void dfs(int v, int pr)
{
    set <int> us;
    for(int a=0; a<co[v].size(); a++) if(an[co[v][a]]!=-1) us.insert(an[co[v][a]]);
    int yk=1;
    for(int a=0; a<co[v].size(); a++)
    {
        if(an[co[v][a]]==-1)
        {
            while(us.find(yk)!=us.end()) yk++;
            an[co[v][a]]=yk;
            yk++;
        }
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs(ne, v);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    sv=new vector <int>[n], co=new vector <int>[n], an=new int[m];
    for(int a=0; a<n; a++)
    {
        int q;
        scanf("%d", &q);
        for(int b=0; b<q; b++)
        {
            int x;
            scanf("%d", &x);
            x--;
            co[a].push_back(x);
        }
    }
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=0; a<m; a++) an[a]=-1;
    dfs(0, -1);
    for(int a=0; a<m; a++) if(an[a]==-1) an[a]=1;
    int ma=0;
    for(int a=0; a<m; a++) ma=max(ma, an[a]);
    cout<<ma<<"\n";
    for(int a=0; a<m; a++) cout<<an[a]<<" ";
}