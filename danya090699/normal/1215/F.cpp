#include <bits/stdc++.h>
using namespace std;
const int sz=2e6;
vector <int> sv[sz], rsv[sz], tout;
int us[sz], cnu[sz], cq=0;
void add(int u, int v)
{
    sv[u^1].push_back(v);
    rsv[v].push_back(u^1);
    sv[v^1].push_back(u);
    rsv[u].push_back(v^1);
}
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
    for(int a=0; a<rsv[v].size(); a++)
    {
        int ne=rsv[v][a];
        if(cnu[ne]==-1) dfs2(ne);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, p, M, m;
    cin>>n>>p>>M>>m;
    for(int a=0; a<n; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        add(u*2, v*2);
    }
    for(int a=0; a<p; a++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--, r--;
        if(l) add(a*2+1, (l+p)*2);
        if(r+1<M) add(a*2+1, (r+1+p)*2+1);
    }
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        add(u*2+1, v*2+1);
    }
    for(int a=0; a+1<M; a++) add((a+p)*2, (a+p+1)*2+1);
    for(int a=0; a<(p+M)*2; a++)
    {
        cnu[a]=-1;
        if(us[a]==0) dfs(a);
    }
    reverse(tout.begin(), tout.end());
    for(int a=0; a<tout.size(); a++)
    {
        int v=tout[a];
        if(cnu[v]==-1) dfs2(v), cq++;
    }
    vector <int> an;
    int f=0;
    for(int a=0; a<(p+M); a++)
    {
        int tr=cnu[a*2], fa=cnu[a*2+1];
        if(tr==fa)
        {
            cout<<-1;
            return 0;
        }
        if(tr>fa)
        {
            if(a<p) an.push_back(a+1);
            else f++;
        }
    }
    if(f==0) f=1;
    cout<<an.size()<<" "<<f<<"\n";
    for(int a=0; a<an.size(); a++) printf("%d ", an[a]);
}