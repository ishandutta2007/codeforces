#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    while(q)
    {
        q--;
        int n, m, an=1e9;
        scanf("%d%d", &n, &m);
        char fi[n][m+1];
        int ve[n], go[m];
        for(int a=0; a<n; a++) ve[a]=0;
        for(int a=0; a<m; a++) go[a]=0;
        for(int a=0; a<n; a++)
        {
            scanf("%s", fi[a]);
            for(int b=0; b<m; b++) if(fi[a][b]=='.') ve[a]++, go[b]++;
        }
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<m; b++)
            {
                int cu=ve[a]+go[b];
                if(fi[a][b]=='.') cu--;
                an=min(an, cu);
            }
        }
        printf("%d\n", an);
    }
}