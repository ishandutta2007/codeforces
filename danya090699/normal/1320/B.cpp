#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector <int> sv[n], rsv[n];
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        rsv[v].push_back(u);
    }
    int k;
    cin>>k;
    int way[k];
    for(int a=0; a<k; a++)
    {
        scanf("%d", &way[a]);
        way[a]--;
    }
    int di[n];
    for(int a=0; a<n; a++) di[a]=-1;
    di[way[k-1]]=0;
    queue <int> qu;
    qu.push(way[k-1]);
    while(qu.size())
    {
        int v=qu.front();
        for(int a=0; a<rsv[v].size(); a++)
        {
            int ne=rsv[v][a];
            if(di[ne]==-1)
            {
                di[ne]=di[v]+1, qu.push(ne);
            }
        }
        qu.pop();
    }
    int mi=0, ma=0;
    for(int a=0; a+1<k; a++)
    {
        int f=way[a], to=way[a+1];
        if(di[f]>di[to])
        {
            int q=0;
            for(int b=0; b<sv[f].size(); b++)
            {
                int v=sv[f][b];
                if(di[f]>di[v]) q++;
            }
            if(q>1) ma++;
        }
        else mi++, ma++;
    }
    cout<<mi<<" "<<ma;
}