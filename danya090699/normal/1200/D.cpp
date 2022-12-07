#include <bits/stdc++.h>
using namespace std;
const int inf=1e8;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    char fi[n][n+1];
    for(int a=0; a<n; a++) scanf("%s", fi[a]);
    int add[n][n+1];
    for(int a=0; a<n; a++) for(int b=0; b<=n; b++) add[a][b]=0;
    for(int a=0; a<n; a++)
    {
        int l=inf, r=-inf;
        for(int b=0; b<n; b++)
        {
            if(fi[a][b]=='B') l=min(l, b), r=max(r, b);
        }
        if(r-l<k)
        {
            int lx=0, rx=n-1, ly=0, ry=n-1;
            if(l!=inf)
            {
                lx=max(0, a-k+1), rx=a;
                ly=max(0, r-k+1), ry=l;
            }
            //cout<<lx<<" "<<rx<<" "<<ly<<" "<<ry<<"\n";
            for(int b=lx; b<=rx; b++) add[b][ly]++, add[b][ry+1]--;
        }
    }
    for(int a=0; a<n; a++)
    {
        int l=inf, r=-inf;
        for(int b=0; b<n; b++)
        {
            if(fi[b][a]=='B') l=min(l, b), r=max(r, b);
        }
        if(r-l<k)
        {
            int lx=0, rx=n-1, ly=0, ry=n-1;
            if(l!=inf)
            {
                ly=max(0, a-k+1), ry=a;
                lx=max(0, r-k+1), rx=l;
            }
            for(int b=lx; b<=rx; b++) add[b][ly]++, add[b][ry+1]--;
        }
    }
    int an=0;
    for(int a=0; a<n; a++)
    {
        int cu=0;
        for(int b=0; b<n; b++)
        {
            cu+=add[a][b], an=max(an, cu);
            //cout<<cu<<" ";
        }
    }
    cout<<an;
}