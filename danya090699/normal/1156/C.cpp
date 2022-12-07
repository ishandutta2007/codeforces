#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, z, yk=0;
    cin>>n>>z;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    sort(ar, ar+n);
    int l=0, r=n/2+1;
    while(r-l>1)
    {
        int mid=(l+r)>>1, ok=1;
        for(int a=0; a<mid; a++) if(ar[n-mid+a]-ar[a]<z) ok=0;
        if(ok) l=mid;
        else r=mid;
    }
    cout<<l;
}