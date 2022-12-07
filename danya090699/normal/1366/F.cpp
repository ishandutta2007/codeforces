#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7, sz=2e3+10, inf=1e18;
int dp[sz][sz];
struct el
{
    int k, b, l;
};
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q, an=0;
    cin>>n>>m>>q;
    vector <pair <int, int> > sv[n];
    for(int a=0; a<m; a++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        sv[u].push_back({v, w});
        sv[v].push_back({u, w});
    }
    for(int a=0; a<=n; a++) for(int b=0; b<n; b++) dp[a][b]=-inf;
    dp[0][0]=0;
    for(int a=0; a<n; a++)
    {
        int ma=0;
        for(int v=0; v<n; v++)
        {
            for(int b=0; b<sv[v].size(); b++)
            {
                int ne=sv[v][b].first, w=sv[v][b].second;
                dp[a+1][ne]=max(dp[a+1][ne], dp[a][v]+w);
                ma=max(ma, dp[a+1][ne]);
            }
        }
        if(a<q) an=(an+ma)%mod;
    }
    vector <pair <int, int> > sp;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int k=sv[a][b].second;
            sp.push_back({k, dp[n][a]-k*n});
        }
    }
    sort(sp.begin(), sp.end());
    vector <el> hull;
    for(int a=0; a<sp.size(); a++)
    {
        int k=sp[a].first, b=sp[a].second;
        while(hull.size())
        {
            int k2=hull.back().k, b2=hull.back().b, l2=hull.back().l;
            if(k==k2)
            {
                if(b>b2) hull.pop_back();
                else break;
            }
            else
            {
                int l;
                if(b<b2) l=(b2-b)/(k-k2)+1;
                else l=-(b-b2)/(k-k2);

                if(l<=l2) hull.pop_back();
                else
                {
                    hull.push_back({k, b, l});
                    break;
                }
            }
        }
        if(hull.size()==0) hull.push_back({k, b, -inf});
    }
    for(int a=0; a<hull.size(); a++)
    {
        int lg=hull[a].l, rg=(a+1<hull.size()) ? hull[a+1].l-1 : inf;
        int l=max(n+1, lg), r=min(q, rg);
        if(l<=r)
        {
            int x=(hull[a].k*l+hull[a].b)+(hull[a].k*r+hull[a].b), y=r-l+1;
            if(x&1) y/=2;
            else x/=2;

            an=(an+1ll*(x%mod)*(y%mod))%mod;
        }
    }
    cout<<an;
}