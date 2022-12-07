#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e5+10, mod=1e9+7;
vector <int> sv[sz];
int n, w[sz], an=0;
vector <pair <int, int> > sp[sz];
void dfs(int v, int pr)
{
    sp[v].push_back({w[v], 1});
    if(pr!=-1)
    {
        for(int a=0; a<sp[pr].size(); a++)
        {
            int va=__gcd(sp[v].back().first, sp[pr][a].first);
            if(va==sp[v].back().first) sp[v].back().second+=sp[pr][a].second;
            else sp[v].push_back({va, sp[pr][a].second});
        }
    }
    for(int a=0; a<sp[v].size(); a++) an=(an+sp[v][a].first*sp[v][a].second)%mod;
    //cout<<v<<" "<<an<<"\n";
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs(ne, v);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n; a++) scanf("%lld", &w[a]);
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, -1);
    cout<<an;
}