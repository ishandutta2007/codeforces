#include <bits/stdc++.h>
using namespace std;
const int sz=1e3+10;
vector <int> sv[sz];
int n, si[sz], ty[sz], va[sz], cu[2]={0, 0}, add[2]={1, 1};
void dfs(int v, int pr)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs(ne, v), si[v]+=si[ne];
    }
}
int find_ce(int v, int pr)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr and si[ne]>n/2) return find_ce(ne, v);
    }
    if(pr!=-1) si[pr]=n-si[v];
    return v;
}
void dfs2(int v, int pr)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            if(ty[v]) ty[ne]=1;
            cu[ty[ne]]+=add[ty[ne]], va[ne]=cu[ty[ne]];
            cout<<v+1<<" "<<ne+1<<" "<<va[ne]-va[v]<<"\n";
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
        cin>>u>>v;
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, -1);
    int c=find_ce(0, -1), bg=-1;
    for(int a=0; a<sv[c].size(); a++)
    {
        int ne=sv[c][a];
        if(si[ne]>=(n-1)/3 and bg==-1) bg=ne;
    }
    if(bg==-1)
    {
        int su=0;
        for(int a=0; a<sv[c].size(); a++)
        {
            int ne=sv[c][a];
            if(su+si[ne]<=n-1-su-si[ne]) su+=si[ne], ty[ne]=1;
            else
            {
                if(su<n-1-su-si[ne]) ty[ne]=1;
                break;
            }
        }
    }
    else ty[bg]=1;

    for(int a=0; a<sv[c].size(); a++)
    {
        int ne=sv[c][a];
        if(ty[ne]==0) add[1]+=si[ne];
    }
    dfs2(c, -1);
}