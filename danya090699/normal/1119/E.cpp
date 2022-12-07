#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);

    int l=0, r=1e18;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        int q[n], lef=mid;
        for(int a=n-1; a>=0; a--)
        {
            q[a]=min(lef, ar[a]/2);
            lef-=q[a];
        }
        if(lef) r=mid;
        else
        {
            int d=0, ok=1;
            for(int a=0; a<n; a++)
            {
                d+=ar[a]-q[a]*2;
                if(d<q[a]) ok=0;
                else d-=q[a];
            }
            if(ok) l=mid;
            else r=mid;
        }
    }
    cout<<l;
}