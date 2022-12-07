#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz];
int tin[sz], timer=0, up[sz][20], h[sz];
void dfs(int v)
{
    tin[v]=timer++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=up[v][0]) up[ne][0]=v, h[ne]=h[v]+1, dfs(ne);
    }
}
int lca(int u, int v)
{
    if(tin[u]>tin[v]) swap(u, v);
    for(int i=19; i>=0; i--)
    {
        int ne=up[v][i];
        if(tin[ne]>tin[u]) v=ne;
    }
    if(v!=u) v=up[v][0];
    return v;
}
int s[sz];
pair <int, int> di[sz];
vector <pair <int, int> > tr[sz];
bool comp(int a, int b)
{
    return tin[a]<tin[b];
}
bool comp2(pair <int, int> a, pair <int, int> b)
{
    int f1=a.first/s[a.second], f2=b.first/s[b.second];
    if(f1!=f2) return f1<f2;
    if(a.second!=b.second) return a.second<b.second;
    return a.first<b.first;
}
bool comp3(int a, int b)
{
    if(comp2(di[a], di[b])) return true;
    if(comp2(di[b], di[a])) return false;
    return a<b;
}
main()
{
    s[sz-1]=1;
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0);
    for(int i=1; i<20; i++)
    {
        for(int a=0; a<n; a++) up[a][i]=up[up[a][i-1]][i-1];
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int k, m;
        scanf("%d%d", &k, &m);
        int vi[k], que[m];
        vector <int> sp, st(1, 0), ve(1, 0);
        for(int b=0; b<k; b++)
        {
            scanf("%d%d", &vi[b], &s[b]);
            vi[b]--, sp.push_back(vi[b]);
        }
        for(int b=0; b<m; b++)
        {
            scanf("%d", &que[b]);
            que[b]--, sp.push_back(que[b]);
        }
        sort(sp.begin(), sp.end(), comp);
        sp.push_back(0);

        for(int b=0; b<sp.size(); b++)
        {
            int u=sp[b], lc=lca(u, st.back());
            while(h[st.back()]>h[lc])
            {
                int v=st.back();
                ve.push_back(v);
                st.pop_back();
                int pr=st.back();
                if(h[pr]<h[lc]) pr=lc;

                tr[v].push_back({pr, h[v]-h[pr]});
                tr[pr].push_back({v, h[v]-h[pr]});
            }
            if(st.back()!=lc) st.push_back(lc);
            if(st.back()!=u) st.push_back(u);
        }
        for(int b=0; b<ve.size(); b++) di[ve[b]]={1e9, sz-1};

        multiset <int, bool(*)(int, int)> se(&comp3);

        for(int b=0; b<k; b++)
        {
            di[vi[b]]={s[b]-1, b};
            se.insert(vi[b]);
        }

        while(se.size())
        {
            int v=*se.begin();
            se.erase(se.begin());
            for(int a=0; a<tr[v].size(); a++)
            {
                int ne=tr[v][a].first;
                pair <int, int> va=di[v];
                va.first+=tr[v][a].second;
                if(comp2(va, di[ne]))
                {
                    se.erase(ne);
                    di[ne]=va;
                    se.insert(ne);
                }
            }
        }
        for(int b=0; b<m; b++) printf("%d ", di[que[b]].second+1);
        printf("\n");

        for(int b=0; b<ve.size(); b++) tr[ve[b]].clear();
    }
}