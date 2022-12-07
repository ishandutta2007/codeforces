#include <bits/stdc++.h>
#define int long long
using namespace std;
int mo(int x)
{
    if(x<0) return -x;
    else return x;
}
void solve(int *f, int n, int su)
{
    int p=lower_bound(f, f+n, -su)-f;
    int an=1e18;
    if(p!=n) an=min(an, mo(f[p]+su));
    if(p!=0) an=min(an, mo(f[p-1]+su));
    printf("%lld\n", an);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q, su=0;
    cin>>n>>m>>q;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        if(a%2==0) su+=x;
        else su-=x;
    }
    int ar[m];
    for(int a=0; a<m; a++) scanf("%lld", &ar[a]);
    int n2=m-n+1;
    int f[n2], cu=0;
    for(int a=0; a<n; a++)
    {
        if(a%2==0) cu-=ar[a];
        else cu+=ar[a];
    }
    f[0]=cu;
    for(int a=n; a<m; a++)
    {
        cu+=ar[a-n];
        cu=-cu;
        if(n%2==0) cu+=ar[a];
        else cu-=ar[a];
        f[a-n+1]=cu;
    }
    sort(f, f+n2);
    solve(f, n2, su);
    for(int a=0; a<q; a++)
    {
        int l, r, x;
        scanf("%lld%lld%lld", &l, &r, &x);
        l--, r--;
        int l1=l, l2=l;
        if(l%2==0) l1--;
        else l2--;
        su+=(r-l1+1)/2*x;
        su-=(r-l2+1)/2*x;
        solve(f, n2, su);
    }
}