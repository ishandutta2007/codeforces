#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector <int> sv[n];
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    int c[n];
    pair <int, int> sp[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &c[a]);
        c[a]--;
        sp[a]={c[a], a};
    }
    bool us[n], ok=1;
    for(int a=0; a<n; a++) us[a]=0;
    for(int a=0; a<n; a++)
    {
        int q=c[a];
        for(int b=0; b<sv[a].size(); b++)
        {
            int v=sv[a][b];
            if(c[v]==c[a]) ok=0;
            if(c[v]<c[a] and !us[c[v]]) us[c[v]]=1, q--;
        }
        if(q) ok=0;
        for(int b=0; b<sv[a].size(); b++)
        {
            int v=sv[a][b];
            us[c[v]]=0;
        }
    }
    if(ok)
    {
        sort(sp, sp+n);
        for(int a=0; a<n; a++) printf("%d ", sp[a].second+1);
    }
    else cout<<"-1";
}