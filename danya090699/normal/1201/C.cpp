#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    sort(ar, ar+n);
    int l=ar[n/2], r=ar[n/2]+k+1;
    while(r-l>1)
    {
        int mid=(l+r)>>1, su=0;
        for(int a=n/2; a<n; a++) su+=max(mid-ar[a], 0ll);
        if(su<=k) l=mid;
        else r=mid;
    }
    cout<<l;
}