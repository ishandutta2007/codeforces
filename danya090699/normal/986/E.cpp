#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, mod=1e9+7;
vector <int> sv[sz];
int va[sz], h[sz], pr[sz], hld[sz], si[sz];
int up[sz][20], tin[sz], timer=0;
int lca(int u, int v)
{
    if(u==v) return u;
    if(tin[u]>tin[v]) swap(u, v);
    for(int i=19; i>=0; i--)
    {
        int ne=up[v][i];
        if(tin[ne]>tin[u]) v=ne;
    }
    return pr[v];
}
unordered_map <int, vector <int> > d[sz], d2[sz], st;
vector <pair <int, int> > sp;
void find_di(int x)
{
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0)
        {
            int q=0;
            while(x%a==0)
            {
                x/=a, q++;
            }
            sp.push_back(make_pair(a, q));
        }
    }
    if(x>1) sp.push_back(make_pair(x, 1));
}
void dfs(int v)
{
    si[v]=1, tin[v]=timer, timer++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v])
        {
            pr[ne]=v, h[ne]=h[v]+1, dfs(ne), si[v]+=si[ne];
            if(si[ne]>si[sv[v][0]]) swap(sv[v][0], sv[v][a]);
        }
    }
}
void dfs2(int v)
{
    find_di(va[v]);
    for(int a=0; a<sp.size(); a++)
    {
        int x=sp[a].first, q=sp[a].second, nu=hld[v];
        if(st.find(x)==st.end()) st[x].push_back(1);
        vector <int> &ve=st[x];
        for(int b=0; b<q; b++) ve.push_back((1ll*ve.back()*x)%mod);
        d2[hld[v]][x].push_back(h[v]), d[hld[v]][st[x][q]].push_back(h[v]);
    }
    sp.clear();
    vector <int> ve;
    for(int a=0; a<sv[v].size(); a++) if(sv[v][a]!=pr[v]) ve.push_back(sv[v][a]);
    for(int a=0; a<ve.size(); a++)
    {
        int ne=ve[a];
        if(si[ne]>si[ve[0]]) swap(ve[0], ve[a]);
    }
    if(ve.size()) hld[ve[0]]=hld[v];
    for(int a=1; a<ve.size(); a++) hld[ve[a]]=ve[a];
    for(int a=0; a<ve.size(); a++) dfs2(ve[a]);
}
int an;
int f(vector <int> &ve, int x)
{
    return upper_bound(ve.begin(), ve.end(), x)-ve.begin();
}
void go(int v, int u)
{
    while(1)
    {
        int nu=hld[v];
        for(int a=0; a<sp.size(); a++)
        {
            int x=sp[a].first, q=sp[a].second;
            if(d2[nu].find(x)!=d2[nu].end())
            {
                vector <int> &ve=d2[nu][x];
                int qq=f(d2[nu][x], h[v]), su=0;
                if(h[nu]<=h[u]) qq-=f(d2[nu][x], h[u]);

                for(int b=1; b<q; b++)
                {
                    int cu=f(d[nu][st[x][b]], h[v]);
                    if(h[nu]<=h[u]) cu-=f(d[nu][st[x][b]], h[u]);
                    su+=b*cu, qq-=cu;
                }

                su+=q*qq;
                an=(1ll*an*st[x][su])%mod;
            }
        }
        if(h[nu]<=h[u]) break;
        v=pr[nu];
    }
}
int main()
{
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
    for(int a=0; a<n; a++) scanf("%d", &va[a]);
    pr[0]=0, h[0]=0, dfs(0);
    for(int a=0; a<n; a++) up[a][0]=pr[a];
    for(int i=1; i<20; i++)
    {
        for(int a=0; a<n; a++) up[a][i]=up[up[a][i-1]][i-1];
    }
    hld[0]=0, dfs2(0);

    int m;
    cin>>m;
    for(int a=0; a<m; a++)
    {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);
        u--, v--;
        int u2=lca(u, v);
        find_di(x);
        an=__gcd(x, va[u2]);
        go(v, u2);
        go(u, u2);
        printf("%d\n", an);
        sp.clear();
    }
}