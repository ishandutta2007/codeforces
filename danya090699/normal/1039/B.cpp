#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    srand(time(0));
    int n, k;
    cin>>n>>k;
    int l=1, r=n;
    while(1)
    {
        int q=r-l+1;
        if(q/2+1+k*2<q)
        {
            int mid=(l+r)>>1;
            cout<<l<<" "<<mid<<"\n";
            string re;
            cin>>re;
            if(re=="Yes")
            {
                l=max(1ll, l-k), r=min(n, mid+k);
            }
            else
            {
                l=max(1ll, mid+1-k), r=min(n, r+k);
            }
        }
        else
        {
            int p=l+rand()%q;
            cout<<p<<" "<<p<<"\n";
            string re;
            cin>>re;
            if(re=="Yes") break;
            else
            {
                l=max(1ll, l-k), r=min(n, r+k);
            }
        }
    }
}