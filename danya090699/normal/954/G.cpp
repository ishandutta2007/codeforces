#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, ra, k;
    cin>>n>>ra>>k;
    int ar[n+1], cu=0;
    for(int a=0; a<=n; a++) ar[a]=0;
    for(int a=0; a<n; a++)
    {
        int q;
        scanf("%lld", &q);
        int l=max(0ll, a-ra), r=min(n, a+ra+1);
        ar[l]+=q, ar[r]-=q;
    }
    for(int a=0; a<n; a++)
    {
        cu+=ar[a], ar[a]=cu;
    }
    int l=0, r=2e18;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        int add[n+1], le=k;
        for(int a=0; a<=n; a++) add[a]=0, cu=0;
        for(int a=0; a<n; a++)
        {
            cu+=add[a];
            if(ar[a]+cu<mid)
            {
                int q=mid-(ar[a]+cu);
                cu+=q, add[min(n, a+2*ra+1)]-=q;
                if(le>=0) le-=q;
            }
        }
        if(le<0) r=mid;
        else l=mid;
    }
    cout<<l;
}