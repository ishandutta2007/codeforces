#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e5+10;
int h[sz], n, su=0, A, R, M;
int f(int x)
{
    int an=0;
    for(int a=0; a<n; a++)
    {
        if(h[a]>x and su<n*x) an+=(h[a]-x)*M;

        if(h[a]<x and su>=n*x) an+=(x-h[a])*M;
    }

    if(su<n*x) an+=A*(n*x-su);
    else an+=R*(su-n*x);

    return an;
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>A>>R>>M;
    M=min(M, A+R);
    int an=4e18;
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &h[a]);
        su+=h[a];
    }
    int l=0, r=su/n;
    while(r-l>2)
    {
        int p1=(l+r)>>1, p2=p1+1;
        if(f(p1)>f(p2)) l=p1;
        else r=p2;
    }
    for(int a=l; a<=r; a++) an=min(an, f(a));

    l=su/n+1, r=1e9+10;
    while(r-l>2)
    {
        int p1=(l+r)>>1, p2=p1+1;
        if(f(p1)>f(p2)) l=p1;
        else r=p2;
    }
    for(int a=l; a<=r; a++) an=min(an, f(a));

    cout<<an;
}