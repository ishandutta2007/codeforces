#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    set <int> sv[n];
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].insert(v);
        sv[v].insert(u);
    }
    int an[2][n], fo1=-1, fo2;
    for(int a=0; a<n; a++)
    {
        if(sv[a].size()<n-1)
        {
            for(int b=0; b<n; b++)
            {
                if(b!=a)
                {
                    if(sv[a].find(b)==sv[a].end())
                    {
                        fo1=a, fo2=b;
                        break;
                    }
                }
            }
        }
    }
    if(fo1!=-1)
    {
        cout<<"YES\n";
        int yk=3;
        an[0][fo1]=1, an[0][fo2]=2, an[1][fo1]=1, an[1][fo2]=1;
        for(int a=0; a<n; a++)
        {
            if(a!=fo1 and a!=fo2) an[0][a]=yk, an[1][a]=yk-1, yk++;
        }
        for(int i=0; i<2; i++)
        {
            for(int a=0; a<n; a++) printf("%d ", an[i][a]);
            printf("\n");
        }
    }
    else cout<<"NO";
}