#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=3e5+10, inf=1e18;
vector <pair <int, int> > sv[sz];
int us[sz], pr[sz], di[sz];
void dfs(int v)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, w=sv[v][a].second;
        if(ne!=pr[v])
        {
            pr[ne]=v, di[ne]=di[v]+w, dfs(ne);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<n-1; a++)
    {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        u--, v--;
        sv[u].push_back(make_pair(v, w));
        sv[v].push_back(make_pair(u, w));
    }
    pr[0]=-1, di[0]=0, dfs(0);
    vector <int> sp, di2;
    int cu=n-1;
    while(cu!=-1)
    {
        us[cu]=1, sp.push_back(cu), cu=pr[cu];
    }
    bool good=0;
    for(int a=0; a<sp.size(); a++)
    {
        int v=sp[a], q=0;
        di2.push_back(0);
        for(int b=0; b<sv[v].size(); b++)
        {
            int ne=sv[v][b].first, w=sv[v][b].second;
            if(us[ne]==0)
            {
                di2.back()=w, q++;
                if(sv[ne].size()>1) good=1;
            }
        }
        if(q>1) good=1;
    }
    multiset <int, greater <int> > pref;
    int be=-inf;
    for(int a=0; a<sp.size(); a++)
    {
        int v=sp[a];
        if(a>0)
        {
            int u=sp[a-1];
            if(di2[a]==0 and di2[a-1]==0) pref.erase(pref.find(-di[u]));
        }
        if(pref.size())
        {
            int cu=di2[a]+di[v]+(*pref.begin());
            be=max(be, cu);
        }
        if(a>0)
        {
            int u=sp[a-1];
            if(di2[a]==0 and di2[a-1]==0) pref.insert(-di[u]);
        }
        pref.insert(di2[a]-di[v]);
    }
    for(int a=0; a<m; a++)
    {
        int x;
        scanf("%lld", &x);
        int an=di[n-1];
        if(good==0)
        {
            an=min(an, di[n-1]+be+x);
        }
        printf("%lld\n", an);
    }
}