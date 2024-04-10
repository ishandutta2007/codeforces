#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector <int> sv[n];
        int mask[n];
        for(int a=0; a<n; a++) mask[a]=0;
        for(int a=0; a<m; a++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            sv[u].push_back(v);
        }
        vector <int> an;
        for(int a=0; a<n; a++)
        {
            int i;
            if((mask[a]&3)==0) i=0;
            else if((mask[a]&3)==1) i=1;
            else i=2;

            if(i==2) an.push_back(a);

            for(int b=0; b<sv[a].size(); b++)
            {
                int to=sv[a][b];
                mask[to]|=(1<<i);
            }
        }
        printf("%d\n", an.size());
        for(int a=0; a<an.size(); a++) printf("%d ", an[a]+1);
        printf("\n");
    }
}