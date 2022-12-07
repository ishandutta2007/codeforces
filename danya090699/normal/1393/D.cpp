#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    char fi[n][m+1];
    for(int a=0; a<n; a++) scanf("%s", fi[a]);
    int top[n][m], bot[n][m], l[n][m], r[n][m];
    for(int a=0; a<m; a++) top[0][a]=1;
    for(int a=1; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            if(fi[a][b]==fi[a-1][b]) top[a][b]=top[a-1][b]+1;
            else top[a][b]=1;
        }
    }
    for(int a=0; a<m; a++) bot[n-1][a]=1;
    for(int a=n-2; a>=0; a--)
    {
        for(int b=0; b<m; b++)
        {
            if(fi[a][b]==fi[a+1][b]) bot[a][b]=bot[a+1][b]+1;
            else bot[a][b]=1;
        }
    }
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<n; b++)
        {
            if(a==0 or fi[b][a]!=fi[b][a-1]) l[b][a]=1;
            else l[b][a]=min(l[b][a-1]+1, min(top[b][a], bot[b][a]));
        }
    }
    for(int a=m-1; a>=0; a--)
    {
        for(int b=0; b<n; b++)
        {
            if(a==m-1 or fi[b][a]!=fi[b][a+1]) r[b][a]=1;
            else r[b][a]=min(r[b][a+1]+1, min(top[b][a], bot[b][a]));
        }
    }
    long long an=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++) an+=min(l[a][b], r[a][b]);
    }
    cout<<an;
}