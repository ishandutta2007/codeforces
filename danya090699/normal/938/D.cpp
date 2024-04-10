#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector <pair <int, int> > sv[n];
    for(int a=0; a<m; a++)
    {
        int u, v, pr;
        scanf("%lld%lld%lld", &u, &v, &pr);
        u--, v--;
        sv[u].push_back(make_pair(v, pr));
        sv[v].push_back(make_pair(u, pr));
    }
    set <pair <int, int> > se;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a]);
        se.insert(make_pair(ar[a], a));
    }
    while(se.size())
    {
        int v=(*se.begin()).second;
        se.erase(se.begin());
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a].first, pr=sv[v][a].second*2;
            if(ar[ne]>ar[v]+pr)
            {
                se.erase(make_pair(ar[ne], ne));
                ar[ne]=ar[v]+pr;
                se.insert(make_pair(ar[ne], ne));
            }
        }
    }
    for(int a=0; a<n; a++) printf("%lld ", ar[a]);
}