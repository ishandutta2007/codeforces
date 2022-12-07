//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, inf=1e9;
int n, m, si[sz], cuq, pre[sz], red[sz];
vector <int> sv[sz], di[sz];
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
    int fo=0, lef=cuq-1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            lef-=si[ne];
            if(si[ne]>cuq/2)
            {
                fo=1;
                return find_ce(ne, v);
            }
        }
    }
    if(fo==0)
    {
        if(pr!=-1) si[pr]=lef;
        return v;
    }
}
void dis(int v, int pr, int h)
{
    di[v].push_back(h);
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dis(ne, v, h+1);
    }
}
void dfs(int v, int pr, int q)
{
    cuq=q;
    siz(v, -1);
    int ce=find_ce(v, -1);
    pre[ce]=pr;
    dis(ce, -1, 0);
    for(int a=0; a<sv[ce].size(); a++)
    {
        int ne=sv[ce][a];
        for(int b=0; b<sv[ne].size(); b++) if(sv[ne][b]==ce) sv[ne].erase(sv[ne].begin()+b);
    }
    while(sv[ce].size()>0)
    {
        int ne=sv[ce].back();
        dfs(ne, ce, si[ne]);
        sv[ce].pop_back();
    }
}
void pai(int v)
{
    int cu=v;
    for(int a=di[v].size()-1; a>=0; a--)
    {
        red[cu]=min(red[cu], di[v][a]);
        cu=pre[cu];
    }
}
int que(int v)
{
    int re=inf, cu=v;
    for(int a=di[v].size()-1; a>=0; a--)
    {
        re=min(re, red[cu]+di[v][a]);
        cu=pre[cu];
    }
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, -1, n);
    for(int a=0; a<n; a++) red[a]=inf;
    pai(0);
    for(int a=0; a<m; a++)
    {
        int t, v;
        scanf("%d%d", &t, &v);
        v--;
        if(t==1) pai(v);
        else printf("%d\n", que(v));
    }
}