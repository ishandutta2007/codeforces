#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int l=0, r=n;
    while(r-l>1)
    {
        int mid=(l+r)>>1, le=n, re=0;
        while(le)
        {
            int q=min(le, mid);
            le-=q, re+=q;
            le-=le/10;
        }
        if(re*2>=n) r=mid;
        else l=mid;
    }
    cout<<r;
}