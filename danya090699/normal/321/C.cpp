//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int n, si[sz], cuq;
char an[sz];
vector <int> sv[sz];
void siz(int v, int pr)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            siz(ne, v);
            si[v]+=si[ne];
        }
    }
}
int find_ce(int v, int pr)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr and si[ne]>cuq/2) return find_ce(ne, v);
    }
    if(pr!=-1) si[pr]=cuq-si[v];
    return v;
}
void dfs(int v, int q, char sy)
{
    siz(v, -1);
    cuq=q;
    int ce=find_ce(v, -1);
    an[ce]=sy;
    while(sv[ce].size()>0)
    {
        int ne=sv[ce].back();
        for(int a=0; a<sv[ne].size(); a++) if(sv[ne][a]==ce) sv[ne].erase(sv[ne].begin()+a);
        sv[ce].pop_back();
        dfs(ne, si[ne], sy+1);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, n, 'A');
    for(int a=0; a<n; a++) cout<<an[a]<<" ";
}