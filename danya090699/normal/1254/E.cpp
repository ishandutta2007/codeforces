#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10, mod=1e9+7;
void err()
{
    cout<<0;
    exit(0);
}
int pr[sz], tin[sz], timer=0;
vector <int> sv[sz];
set <int> se[sz];
void dfs(int v)
{
    tin[v]=timer++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v]) pr[ne]=v, dfs(ne);
    }
}
vector <pair <int, int> > re[sz];
int pre[sz], nex[sz], first[sz], last[sz], fact[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    fact[0]=1;
    for(int a=1; a<=n; a++) fact[a]=(1ll*fact[a-1]*a)%mod;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
        se[u].insert(v);
        se[v].insert(u);
    }
    dfs(0);
    for(int a=0; a<n; a++) first[a]=-1, last[a]=-1;
    for(int a=0; a<n; a++)
    {
        int u;
        scanf("%d", &u);
        if(u)
        {
            u--;
            int v=a, rev=0;
            if(u==v) err();
            if(tin[u]>tin[v]) swap(u, v), rev=1;

            vector <int> pa, pa2;
            while(tin[v]>tin[u]) pa2.push_back(v), v=pr[v];
            while(u!=v) pa.push_back(u), u=pr[u];
            pa.push_back(u);
            while(pa2.size()) pa.push_back(pa2.back()), pa2.pop_back();
            if(rev) reverse(pa.begin(), pa.end());

            for(int a=0; a+1<pa.size(); a++)
            {
                auto it=se[pa[a]].find(pa[a+1]);
                if(it==se[pa[a]].end()) err();
                se[pa[a]].erase(it);
            }

            first[pa[0]]=pa[1];
            last[pa.back()]=pa[pa.size()-2];

            for(int a=1; a+1<pa.size(); a++)
            {
                re[pa[a]].push_back({pa[a-1], pa[a+1]});
            }
        }
    }
    int an=1;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            pre[sv[a][b]]=-1;
            nex[sv[a][b]]=-1;
        }
        for(int b=0; b<re[a].size(); b++)
        {
            pre[re[a][b].second]=re[a][b].first;
            nex[re[a][b].first]=re[a][b].second;
        }
        int q=0, pq=0, same=0;
        for(int b=0; b<sv[a].size(); b++)
        {
            int v=sv[a][b];
            if(pre[v]==-1)
            {
                while(nex[v]!=-1) v=nex[v], q++;
                q++, pq++;
                if(sv[a][b]==first[a] and v==last[a]) same=1;
            }
        }
        if(q!=sv[a].size()) err();
        if(pq>1)
        {
            if(same) err();
            if(first[a]!=-1) pq--;
            if(last[a]!=-1) pq--;
            an=(1ll*an*fact[pq])%mod;
        }
    }
    cout<<an;
}