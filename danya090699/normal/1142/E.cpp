#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz], rsv[sz], tout, sp[sz];
int us[sz], cnu[sz], cq=0, in[sz];
void dfs(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs(ne);
    }
    tout.push_back(v);
}
void dfs2(int v)
{
    cnu[v]=cq;
    sp[cq].push_back(v);
    for(int a=0; a<rsv[v].size(); a++)
    {
        int ne=rsv[v][a];
        if(cnu[ne]==-1) dfs2(ne);
    }
}
main()
{
    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        rsv[v].push_back(u);
    }
    for(int a=0; a<n; a++)
    {
        cnu[a]=-1;
        if(us[a]==0) dfs(a);
    }
    reverse(tout.begin(), tout.end());
    for(int a=0; a<n; a++)
    {
        int v=tout[a];
        if(cnu[v]==-1)
        {
            dfs2(v), cq++;
        }
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int u=cnu[a], v=cnu[sv[a][b]];
            if(u!=v) in[v]++;
        }
    }
    deque <int> qu;
    for(int a=0; a<cq; a++) if(in[a]==0) qu.push_back(a);
    while(qu.size()>1)
    {
        printf("? %d %d", sp[qu[0]].back()+1, sp[qu[1]].back()+1);
        cout<<endl;
        int i;
        scanf("%d", &i);
        if(i) swap(qu[0], qu[1]);
        int c=qu[0], v=sp[c].back();
        sp[c].pop_back();
        if(sp[c].size()==0) qu.pop_front();
        for(int a=0; a<sv[v].size(); a++)
        {
            int c2=cnu[sv[v][a]];
            if(c2!=c)
            {
                in[c2]--;
                if(in[c2]==0) qu.push_back(c2);
            }
        }
    }
    cout<<"! "<<sp[qu[0]].back()+1<<endl;
}