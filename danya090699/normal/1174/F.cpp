#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz], sp[sz];
int pr[sz], si[sz], hld[sz];
void dfs(int v)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v]) pr[ne]=v, dfs(ne), si[v]+=si[ne];
    }
}
void dfs2(int v)
{
    int be=-1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v])
        {
            if(be==-1 or si[ne]>si[be]) be=ne;
        }
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v])
        {
            if(ne==be) hld[ne]=hld[v];
            else hld[ne]=ne;
            sp[hld[ne]].push_back(ne);
            dfs2(ne);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    //ifstream in("input.txt");
    int n;
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        //in>>u>>v;
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    sp[0].push_back(0);
    dfs(0), dfs2(0);
    int h=0, v=0, mh;
    cout<<"d 1\n";
    cin>>mh;
    while(h<mh)
    {
        int lh=h+sp[v].size()-1;
        cout<<"d "<<sp[v].back()+1<<"\n";
        int re, up;
        cin>>re;
        if(lh<=mh) up=(re-(mh-lh))/2;
        else up=(lh-mh)+(re-(lh-mh))/2;

        v=sp[v][sp[v].size()-1-up], h=lh-up;

        if(h==mh) break;

        cout<<"s "<<v+1<<"\n";
        cin>>re;
        v=re-1, h++;
    }
    cout<<"! "<<v+1<<"\n";
}