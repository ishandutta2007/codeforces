#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
vector <int> sv[sz], sv2[sz];
int tin[sz], fup[sz], timer=1, an=0;
bool us[sz];
void dfs(int v, int pr)
{
    tin[v]=timer, fup[v]=timer, timer++;
    //cout<<v<<" ";
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            if(tin[ne]) fup[v]=min(fup[v], tin[ne]);
            else
            {
                dfs(ne, v);
                fup[v]=min(fup[v], fup[ne]);
            }
        }
    }
}
void dfs2(int v, int cu)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0)
        {
            if(fup[ne]>tin[v])
            {
                sv2[cu].push_back(ne);
                //cout<<cu<<" "<<ne<<"\n";
                dfs2(ne, ne);
            }
            else dfs2(ne, cu);
        }
    }
}
int dfs3(int v)
{
    int be=0;
    for(int a=0; a<sv2[v].size(); a++)
    {
        int ne=sv2[v][a];
        int cu=dfs3(ne);
        an=max(an, be+cu+1), be=max(be, cu+1);
    }
    return be;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, -1);
    dfs2(0, 0);
    dfs3(0);
    cout<<an;
}