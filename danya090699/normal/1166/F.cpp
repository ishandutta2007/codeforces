#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
map <int, int> col[sz];
int cnu[sz];
vector <int> sp[sz];
set <int> sv[sz];
void merge(int u, int v)
{
    if(sp[u].size()<sp[v].size()) swap(u, v);
    while(sp[v].size())
    {
        sp[u].push_back(sp[v].back());
        cnu[sp[v].back()]=u;
        sp[v].pop_back();
    }
    for(auto it=sv[v].begin(); it!=sv[v].end(); it++) sv[u].insert(*it);
    sv[v].clear();
}
void add(int u, int v, int c)
{
    if(col[u].find(c)!=col[u].end())
    {
        int v1=cnu[v], v2=cnu[col[u][c]];
        if(v1!=v2) merge(v1, v2);
    }
    else col[u][c]=v;

    sv[cnu[u]].insert(v);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, colors, q;
    cin>>n>>m>>colors>>q;
    for(int a=0; a<n; a++)
    {
        cnu[a]=a, sp[a].push_back(a);
    }
    for(int a=0; a<m; a++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        add(u, v, w), add(v, u, w);
    }
    for(int a=0; a<q; a++)
    {
        char ty[2];
        int u, v;
        scanf("%s%d%d", ty, &u, &v);
        u--, v--;
        if(ty[0]=='?')
        {
            if(cnu[u]==cnu[v] or sv[cnu[u]].count(v)) printf("Yes\n");
            else printf("No\n");
        }
        else
        {
            int w;
            scanf("%d", &w);
            add(u, v, w), add(v, u, w);
        }
    }
}