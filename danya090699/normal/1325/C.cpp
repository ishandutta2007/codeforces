#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <pair <int, int> > sv[n];
    int an[n], q=0;
    for(int a=0; a<n; a++) an[a]=-1;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back({v, a});
        sv[v].push_back({u, a});
    }
    for(int a=0; a<n; a++)
    {
        if(sv[a].size()>2)
        {
            for(int b=0; b<3; b++) an[sv[a][b].second]=q++;
            break;
        }
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int i=sv[a][b].second;
            if(an[i]==-1) an[i]=q++;
        }
    }
    for(int a=0; a<n-1; a++) printf("%d\n", an[a]);
}