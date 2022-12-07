#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=5e5+10, mod=1e9+7;
vector <int> sv[sz];
bool us[sz];
int q;
void dfs(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs(ne);
    }
}
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    int va[n];
    for(int a=0; a<n; a++) scanf("%lld", &va[a]);
    map <int, vector <pair <int, int> > > ma;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        ma[va[u]^va[v]].push_back(make_pair(u, v));
    }
    int an=(1ll*po(2, n)*(((1ll<<k)-ma.size())%mod))%mod;
    //cout<<ma.size();
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        vector <int> ve;
        vector <pair <int, int> > &re=(*it).second;
        for(int a=0; a<re.size(); a++)
        {
            int u=re[a].first, v=re[a].second;
            sv[u].push_back(v), sv[v].push_back(u);
            ve.push_back(u), ve.push_back(v);
        }
        int gq=0, vq=0;
        for(int a=0; a<ve.size(); a++)
        {
            int v=ve[a];
            if(us[v]==0)
            {
                gq++, dfs(v);
            }
        }
        for(int a=0; a<ve.size(); a++)
        {
            int v=ve[a];
            if(us[v]) vq++;
            us[v]=0, sv[v].clear();
        }
        an=(an+1ll*po(2, n-vq)*po(2, gq))%mod;
    }
    cout<<an;
}