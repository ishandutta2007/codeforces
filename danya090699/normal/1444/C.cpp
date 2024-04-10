#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
vector <int> sv[sz];
int com[sz], bad[sz], cnu[sz], cq=0, c[sz];
void dfs(int v)
{
    cnu[v]=cq;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(com[v]==com[ne])
        {
            if(cnu[ne]==-1)
            {
                c[ne]=c[v]^1, dfs(ne);
            }
            else if(c[ne]!=(c[v]^1)) bad[com[v]]=1;
        }
    }
}

vector <pair <int, int> > sv2[sz];
int c2[sz], ok;
void dfs2(int v)
{
    for(int a=0; a<sv2[v].size(); a++)
    {
        int ne=sv2[v][a].first, w=sv2[v][a].second;
        if(c2[ne]==-1)
        {
            c2[ne]=c2[v]^w, dfs2(ne);
        }
        else if(c2[ne]!=(c2[v]^w)) ok=0;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &com[a]);
        com[a]--;
    }
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=0; a<n; a++) cnu[a]=-1, c2[a]=-1;
    for(int a=0; a<n; a++)
    {
        if(cnu[a]==-1)
        {
            dfs(a), cq++;
        }
    }
    long long an=0;
    for(int a=0; a<k; a++) if(!bad[a]) an++;
    an=an*(an-1)/2;

    map <pair <int, int>, vector <pair <int, int> > > ma;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int to=sv[a][b], c1=com[a], c2=com[to];
            if(c1!=c2 and bad[c1]==0 and bad[c2]==0)
            {
                if(c1>c2) swap(c1, c2);
                ma[{c1, c2}].push_back({a, to});
            }
        }
    }

    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        vector <pair <int, int> > &re=(*it).second;
        vector <int> ve;
        for(int a=0; a<re.size(); a++)
        {
            int u=re[a].first, v=re[a].second;

            ve.push_back(cnu[u]);
            ve.push_back(cnu[v]);

            sv2[cnu[u]].push_back({cnu[v], c[u]^c[v]^1});
        }

        ok=1;
        for(int a=0; a<ve.size(); a++)
        {
            if(c2[ve[a]]==-1) c2[ve[a]]=0, dfs2(ve[a]);
        }
        if(!ok) an--;

        for(int a=0; a<ve.size(); a++)
        {
            c2[ve[a]]=-1;
            sv2[ve[a]].clear();
        }
    }
    cout<<an;
}