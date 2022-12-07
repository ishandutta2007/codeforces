#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
vector <int> sv[sz], cy[sz];
vector <pair <int, int> > to[sz];
bool us[sz];
int pr[sz], h[sz], dow[sz], up[sz];
void dfs(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0)
        {
            pr[ne]=v, h[ne]=h[v]+1, dfs(ne);
        }
    }
}
void dfs2(int v)
{
    for(int a=0; a<cy[v].size(); a++)
    {
        int u=cy[v][a];
        int ne=cy[v][(a+1)%cy[v].size()];
        dow[u]=0;
        if(u!=v) to[u].push_back(make_pair(u, 0));
        for(int b=0; b<sv[u].size(); b++)
        {
            int u2=sv[u][b];
            if(u2!=pr[u] and u2!=ne and u2!=cy[v].back())
            {
                dfs2(u2), dow[u]=max(dow[u], dow[u2]+1);
                to[u].push_back(make_pair(u2, dow[u2]+1));
            }
        }
        dow[v]=max(dow[v], dow[u]+min(a, int(cy[v].size())-a));
    }
}
void dfs3(int v)
{
    to[v].push_back(make_pair(v, up[v]));
    multiset <int, greater <int> > l, r;
    int q=cy[v].size();
    for(int a=0; a<q; a++)
    {
        int u=cy[v][a];
        for(int b=0; b<to[u].size(); b++)
        {
            int va=to[u][b].second;
            if(a<=q/2) l.insert(va+a);
            else r.insert(va+q-a);
        }
    }
    for(int a=0; a<q; a++)
    {
        int u=cy[v][a];
        for(int b=0; b<to[u].size(); b++)
        {
            int u2=to[u][b].first, va=to[u][b].second;
            l.erase(l.find(va+a));
            int ma=(*l.begin())-a;
            if(r.size()) ma=max(ma, (*r.begin())+a);
            if(u2==u)
            {
                if(u!=v) up[u]=ma;
            }
            else up[u2]=ma+1;
            l.insert(va+a);
        }
        int ne=cy[v][(a+q/2+1)%q];
        for(int b=0; b<to[u].size(); b++)
        {
            int va=to[u][b].second;
            l.erase(l.find(va+a));
            r.insert(va-a);
        }
        for(int b=0; b<to[ne].size(); b++)
        {
            int va=to[ne][b].second;
            r.erase(r.find(va+q-(a+q/2+1)));
            l.insert(va+a+q/2+1);
        }
    }
    for(int a=0; a<q; a++)
    {
        int u=cy[v][a];
        for(int b=0; b<to[u].size(); b++)
        {
            int ne=to[u][b].first;
            if(ne!=u) dfs3(ne);
        }
    }
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
    pr[0]=0, h[0]=0, dfs(0);
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int v=a, u=sv[a][b];
            if(h[u]<h[v] and pr[v]!=u)
            {
                while(v!=u)
                {
                    cy[u].push_back(v), v=pr[v];
                }
            }
        }
    }
    for(int a=0; a<n; a++)
    {
        cy[a].push_back(a);
        reverse(cy[a].begin(), cy[a].end());
    }
    dfs2(0);
    up[0]=0, dfs3(0);
    for(int a=0; a<n; a++) printf("%d ", max(dow[a], up[a]));
}