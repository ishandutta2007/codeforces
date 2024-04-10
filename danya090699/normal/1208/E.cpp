#include <bits/stdc++.h>
using namespace std;
struct el
{
    int i, va, ty;
};
main()
{
    //freopen("input.txt", "r", stdin);
    int n, w;
    cin>>n>>w;
    multiset <int, greater <int> > se[n];
    vector <el> sp[w+1];
    for(int a=0; a<n; a++)
    {
        int m;
        scanf("%d", &m);
        if(m*2<=w) se[a].insert(0);
        else
        {
            sp[0].push_back({a, 0, 1});
            sp[w-m].push_back({a, 0, -1});
            sp[m].push_back({a, 0, 1});
        }
        for(int b=0; b<m; b++)
        {
            int x;
            scanf("%d", &x);
            sp[b].push_back({a, x, 1});
            sp[b+w-m+1].push_back({a, x, -1});
        }
    }
    long long su=0;
    for(int a=0; a<w; a++)
    {
        for(int b=0; b<sp[a].size(); b++)
        {
            el cu=sp[a][b];
            if(se[cu.i].size()) su-=(*se[cu.i].begin());
            if(cu.ty==1) se[cu.i].insert(cu.va);
            else se[cu.i].erase(se[cu.i].find(cu.va));
            if(se[cu.i].size()) su+=(*se[cu.i].begin());
        }
        printf("%lld ", su);
    }
}