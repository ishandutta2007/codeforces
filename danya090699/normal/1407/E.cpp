#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int di[n], c[n];
    for(int a=0; a<n; a++) di[a]=-1, c[a]=-1;
    di[n-1]=0;
    vector <pair <int, int> > sv[n];
    queue <int> qu;
    qu.push(n-1);
    for(int a=0; a<m; a++)
    {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        u--, v--;
        sv[v].push_back({u, t});
    }
    while(qu.size())
    {
        int v=qu.front();
        for(int a=0; a<sv[v].size(); a++)
        {
            int u=sv[v][a].first, t=sv[v][a].second;
            if(di[u]==-1)
            {
                if(c[u]==-1) c[u]=t^1;
                else if(c[u]==t)
                {
                    di[u]=di[v]+1;
                    qu.push(u);
                }
            }
        }
        qu.pop();
    }
    cout<<di[0]<<"\n";
    for(int a=0; a<n; a++) printf("%d", (c[a]==-1) ? 1 : c[a]);
}