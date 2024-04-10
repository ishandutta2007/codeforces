#include <bits/stdc++.h>
using namespace std;
const int sz=2e4+10, inf=1e9;
struct re
{
    int fr, to, cap;
};
vector <int> sv[sz];
vector <re> sp;
bool us[sz];
int s, s2, t;
void add_edge(int u, int v, int cap)
{
    sv[u].push_back(sp.size());
    sp.push_back({u, v, cap});
    sv[v].push_back(sp.size());
    sp.push_back({v, u, 0});
}
int dfs(int v, int flow)
{
    us[v]=1;
    if(v==t) return flow;
    for(int a=0; a<sv[v].size(); a++)
    {
        int i=sv[v][a];
        int ne=sp[i].to;
        if(us[ne]==0 and sp[i].cap>0)
        {
            int re=dfs(ne, min(flow, sp[i].cap));
            if(re)
            {
                sp[i].cap-=re;
                sp[i^1].cap+=re;
                return re;
            }
        }
    }
    return 0;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    s=n+m, s2=n+m+1, t=n+m+2;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        add_edge(u, n+a, 1);
        add_edge(v, n+a, 1);
        add_edge(n+a, t, 1);
    }
    add_edge(s, s2, m);
    for(int a=0; a<n; a++) add_edge(s2, a, 0);
    int flow=0, an=0;
    while(flow<m)
    {
        for(int a=0; a<sp.size(); a++)
        {
            if(sp[a].fr==s2 and sp[a].to!=s) sp[a].cap++;
        }
        an++;
        while(1)
        {
            for(int a=0; a<n+m+3; a++) us[a]=0;
            int add=dfs(s, inf);
            if(add) flow+=add;
            else break;
        }
    }
    cout<<an<<"\n";
    for(int a=0; a<m*6; a+=6)
    {
        int u=sp[a].fr+1, v=sp[a+2].fr+1;
        if(sp[a].cap) swap(u, v);
        printf("%d %d\n", u, v);
    }
}