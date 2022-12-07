#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=2e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n+1];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    ar[n]=inf;
    sort(ar, ar+n);
    int d[n];
    for(int a=0; a<n; a++)
    {
        d[a]=ar[a+1]-ar[a];
        //cout<<d[a]<<" ";
    }
    sort(d, d+n);
    int pref[n];
    pref[0]=d[0];
    for(int a=1; a<n; a++) pref[a]=d[a]+pref[a-1];
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int l, r;
        scanf("%lld%lld", &l, &r);
        int le=r+1-l;
        int p=upper_bound(d, d+n, le)-d;
        //cout<<p<<" ";
        int an=(n-p)*le;
        if(p) an+=pref[p-1];
        printf("%lld ", an);
    }
}