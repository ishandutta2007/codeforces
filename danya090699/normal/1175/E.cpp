#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
int up[sz][20];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<n; a++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        up[l][0]=max(up[l][0], r);
    }
    for(int a=1; a<sz; a++) up[a][0]=max(up[a][0], a), up[a][0]=max(up[a][0], up[a-1][0]);

    for(int i=1; i<20; i++)
    {
        for(int a=0; a<sz; a++) up[a][i]=up[up[a][i-1]][i-1];
    }

    for(int a=0; a<m; a++)
    {
        int l, r, an=0;
        scanf("%d%d", &l, &r);
        for(int i=19; i>=0; i--)
        {
            int ne=up[l][i];
            if(ne<r) l=ne, an+=(1<<i);
        }
        l=up[l][0], an++;
        if(l<r) printf("-1\n");
        else printf("%d\n", an);
    }
}