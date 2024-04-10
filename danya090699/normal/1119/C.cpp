#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[2][n][m], ok=1;
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<n; a++) for(int b=0; b<m; b++) scanf("%d", &ar[i][a][b]);
    }
    for(int a=0; a<n; a++)
    {
        int su[2]={0, 0};
        for(int b=0; b<m; b++) su[0]^=ar[0][a][b], su[1]^=ar[1][a][b];
        if(su[0]!=su[1]) ok=0;
    }
    for(int a=0; a<m; a++)
    {
        int su[2]={0, 0};
        for(int b=0; b<n; b++) su[0]^=ar[0][b][a], su[1]^=ar[1][b][a];
        if(su[0]!=su[1]) ok=0;
    }
    if(ok) cout<<"Yes";
    else cout<<"No";
}