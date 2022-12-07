#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, x, pos, an=1;
    cin>>n>>x>>pos;
    int l=0, r=n, lq=x-1, rq=n-x;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(pos==mid) l=mid+1;
        else if(pos<mid)
        {
            if(rq==0)
            {
                cout<<0;
                return 0;
            }
            an=1ll*an*rq%mod;
            rq--;
            r=mid;
        }
        else
        {
            if(lq==0)
            {
                cout<<0;
                return 0;
            }
            an=1ll*an*lq%mod;
            lq--;
            l=mid+1;
        }
    }
    for(int a=1; a<=lq+rq; a++) an=1ll*an*a%mod;
    cout<<an;
}