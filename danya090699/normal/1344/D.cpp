#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=4e18;
int f(int a, int d)
{
    int l=-1, r=a;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(a-3*mid*mid-3*mid-1>=d) l=mid;
        else r=mid;
    }
    return l+1;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    int lg=-inf, rg=inf;
    while(rg-lg>1)
    {
        int mid=(lg+rg)/2, su=0;
        for(int a=0; a<n; a++) su+=f(ar[a], mid);
        if(su<=k) rg=mid;
        else lg=mid;
    }
    int an[n];
    for(int a=0; a<n; a++) an[a]=f(ar[a], rg), k-=an[a];
    for(int a=0; a<n; a++)
    {
        if(an[a]<ar[a] and k)
        {
            int add=ar[a]-3*an[a]*an[a]-3*an[a]-1;
            if(add==lg) an[a]++, k--;
        }
    }
    for(int a=0; a<n; a++) printf("%lld ", an[a]);
}