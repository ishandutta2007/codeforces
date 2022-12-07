#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t, n, a, b, k;
    cin>>t>>n>>a>>b>>k;
    int qa=n/2+n%2, qb=n/2;
    int l=0, r=t+1;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        int q1=min(qa, (qa*a)/mid);
        q1=min(q1, k);
        int os=0;
        if(q1<k and q1<qa) os=qa*a-q1*mid;

        if(k-q1<=qb)
        {
            if((k-q1)*mid-os<=qb*b) l=mid;
            else r=mid;
        }
        else r=mid;
    }
    cout<<l;
}