#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n, k, l1, r1, l2, r2, an=1e18;
        cin>>n>>k>>l1>>r1>>l2>>r2;
        int l=max(l1, l2), r=min(r1, r2), ll=min(l1, l2), rr=max(r1, r2);

        for(int a=1; a<=n; a++)
        {
            int su=0, q=0, add;
            if(l<r) su=(r-l)*a, add=((rr-ll)-(r-l))*a;
            else q=(l-r)*a, add=(rr-ll)*a;

            if(su<k)
            {
                int d=min(add, k-su);
                su+=d, q+=d;
            }
            if(su<k) q+=(k-su)*2;

            an=min(an, q);
        }
        cout<<an<<"\n";
    }
}