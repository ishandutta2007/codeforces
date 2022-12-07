#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, m;
        scanf("%d%d", &n, &m);
        long long w[n];
        for(int a=0; a<n; a++) scanf("%lld", &w[a]);
        vector <int> sv[n];
        for(int a=0; a<m; a++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            sv[v].push_back(u);
        }
        map <vector <int>, long long> ma;
        for(int a=0; a<n; a++)
        {
            if(sv[a].size())
            {
                sort(sv[a].begin(), sv[a].end());
                ma[sv[a]]+=w[a];
            }
        }
        long long an=0;
        for(auto it=ma.begin(); it!=ma.end(); it++) an=__gcd(an, (*it).second);
        printf("%lld\n", an);
    }
}