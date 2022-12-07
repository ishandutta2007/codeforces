#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, s;
        scanf("%lld%lld", &n, &s);
        pair <int, int> ar[n];
        for(int a=0; a<n; a++) scanf("%lld%lld", &ar[a].first, &ar[a].second);
        sort(ar, ar+n);
        int l=ar[n/2].first, r=2e9;
        while(r-l>1)
        {
            int mid=(l+r)>>1, ll=n/2, rr=n/2, lef=s;
            vector <int> sp;
            for(int a=0; a<n; a++)
            {
                if(ar[a].second<mid) ll--, lef-=ar[a].first;
                else if(ar[a].first>mid) rr--, lef-=ar[a].first;
                else sp.push_back(ar[a].first);
            }
            if(ll>=0 and rr>=0)
            {
                for(int a=0; a<sp.size(); a++)
                {
                    if(a<ll) lef-=sp[a];
                    else lef-=mid;
                }
                if(lef>=0) l=mid;
                else r=mid;
            }
            else r=mid;
        }
        printf("%lld\n", l);
    }
}