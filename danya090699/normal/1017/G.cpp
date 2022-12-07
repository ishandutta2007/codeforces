#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, bl=2500;
vector <int> sv[sz];
int n, q, pr[sz], h[sz], bq[sz];
bool co[sz], us[sz];
vector <pair <int, int> > sv2[sz];
vector <int> st;
void build(int v)
{
    if(us[v])
    {
        if(st.size())
        {
            int u=st.back();
            sv2[u].push_back(make_pair(v, (h[v]-h[u])-(bq[v]-bq[u])));
        }
        st.push_back(v);
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        bq[ne]=bq[v]+co[v], h[ne]=h[v]+1, build(ne);
    }
    if(us[v]) st.pop_back();
}
int q1[sz];
bool q2[sz];
void dfs(int v)
{
    q1[v]++;
    for(int a=0; a<sv2[v].size(); a++)
    {
        int ne=sv2[v][a].first, lef=sv2[v][a].second;
        if(lef) sv2[v][a].second--;
        else dfs(ne);
    }
}
void dfs2(int v)
{
    q2[v]=1, q1[v]=0;
    for(int a=0; a<sv2[v].size(); a++)
    {
        int ne=sv2[v][a].first;
        int d=h[ne]-h[v];
        sv2[v][a].second=d;
        dfs2(ne);
    }
}
void recover(int v, bool del, int bl)
{
    if(del) co[v]=0;
    int nbl=bl;
    if(us[v]) nbl=q1[v];
    if(co[v]==0 and nbl)
    {
        co[v]=1, nbl--;
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        recover(ne, (del|q2[ne]), nbl);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>q;
    for(int a=1; a<n; a++)
    {
        scanf("%d", &pr[a]);
        pr[a]--;
        sv[pr[a]].push_back(a);
    }
    int zap[q][2];
    for(int a=0; a<q; a++)
    {
        scanf("%d%d", &zap[a][0], &zap[a][1]);
        zap[a][1]--;
    }
    for(int a=0; a<q; a+=bl)
    {
        int rg=min(a+bl, q);
        for(int b=a; b<rg; b++) us[zap[b][1]]=1;
        h[0]=0, bq[0]=0, build(0);

        for(int b=a; b<rg; b++)
        {
            int ty=zap[b][0], v=zap[b][1];
            if(ty==1) dfs(v);
            if(ty==2) dfs2(v);
            if(ty==3)
            {
                bool an=0;
                if(q2[v]==0) an=co[v];
                if(q1[v]) an=1;
                if(an) printf("black\n");
                else printf("white\n");
            }
        }

        recover(0, q2[0], 0);
        for(int b=0; b<n; b++)
        {
            us[b]=0, q1[b]=0; q2[b]=0;
            if(sv2[b].size()) sv2[b].clear();
        }
    }
}