#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10, mod=1e9+7;
int ne[sz][10], h[sz], va[sz], up[sz][20], prsy[sz];
bool comp(int u, int v)
{
    if(h[u]!=h[v]) return h[u]<h[v];
    else
    {
        for(int i=19; i>=0; i--)
        {
            if(up[u][i]!=up[v][i])
            {
                u=up[u][i], v=up[v][i];
            }
        }
        return prsy[u]<prsy[v];
    }
}
bool comp2(pair <int, int> a, pair <int, int> b)
{
    if(a.first!=b.first) return comp(a.first, b.first);
    else return a.second<b.second;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector <pair <int, int> > sv[n];
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back({v, a+1});
        sv[v].push_back({u, a+1});
    }
    int di[n], q=1;
    for(int i=0; i<10; i++) ne[0][i]=-1;
    di[0]=0;
    for(int a=1; a<=n; a++) di[a]=-1;
    set <pair <int, int>, bool(*)(pair <int, int>, pair <int, int>) > se(&comp2);
    se.insert({0, 0});
    while(se.size())
    {
        int v=(*se.begin()).second;
        //cout<<di[v]<<" ";
        se.erase(se.begin());
        for(int a=0; a<sv[v].size(); a++)
        {
            int nex=sv[v][a].first, x=sv[v][a].second;
            vector <int> ch;
            while(x) ch.push_back(x%10), x/=10;
            reverse(ch.begin(), ch.end());
            int u=di[v];
            for(int b=0; b<ch.size(); b++)
            {
                int sy=ch[b];
                //cout<<sy<<" ";
                if(ne[u][sy]==-1)
                {
                    ne[u][sy]=q, prsy[q]=sy, up[q][0]=u, h[q]=h[u]+1, va[q]=(1ll*va[u]*10+sy)%mod;
                    for(int i=1; i<20; i++) up[q][i]=up[up[q][i-1]][i-1];
                    for(int i=0; i<10; i++) ne[q][i]=-1;
                    q++;
                }
                u=ne[u][sy];
            }
            //cout<<u<<" ";
            if(di[nex]==-1 or comp(u, di[nex]))
            {
                if(di[nex]!=-1) se.erase({di[nex], nex});
                di[nex]=u;
                se.insert({di[nex], nex});
            }
        }
    }
    for(int a=1; a<n; a++) printf("%d\n", va[di[a]]);
}