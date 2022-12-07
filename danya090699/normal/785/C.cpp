#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    if(m>n) m=n;
    int l=-1, r=2e9;
    while(r-l>1)
    {
        int mid=(l+r)/2, le=n;
        if(mid>1) le-=(mid-1)*mid/2;
        if(le>m+mid) l=mid;
        else r=mid;
    }
    cout<<r+m;
}