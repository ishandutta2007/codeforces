#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int gr[sz];
vector <int> sv[sz];
void dfs(int v)
{
    bool us[sv[v].size()+1];
    for(int a=0; a<=sv[v].size(); a++) us[a]=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(gr[ne]==-1) dfs(ne);
        if(gr[ne]<=sv[v].size()) us[gr[ne]]=1;
    }
    for(int a=0; ; a++)
    {
        if(us[a]==0)
        {
            gr[v]=a;
            break;
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int h[n], xo[n];
    for(int a=0; a<n; a++) scanf("%d", &h[a]), xo[a]=0, gr[a]=-1;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
    }
    for(int a=0; a<n; a++)
    {
        if(gr[a]==-1) dfs(a);
        xo[gr[a]]^=h[a];
    }
    for(int a=n-1; a>=0; a--)
    {
        if(xo[a])
        {
            int be=-1;
            for(int b=0; b<n; b++)
            {
                if(gr[b]==a and (xo[a]^h[b])<h[b]) be=b;
            }
            h[be]=xo[a]^h[be], xo[a]=0;
            for(int b=0; b<sv[be].size(); b++)
            {
                int ne=sv[be][b];
                h[ne]=xo[gr[ne]]^h[ne], xo[gr[ne]]=0;
            }
            cout<<"WIN\n";
            for(int b=0; b<n; b++) printf("%d ", h[b]);
            return 0;
        }
    }
    cout<<"LOSE";
}