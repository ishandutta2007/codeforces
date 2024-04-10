#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
main()
{
    //freopen("input.txt", "r", stdin);
    int q[2]={1, 0}, l, r, an=0;
    cin>>l>>r;
    l--, r--;
    for(int i=0; i<60; i++)
    {
        int ty=(i&1)^1, lg=q[ty], rg=q[ty]+(1ll<<i)-1, d=(1ll<<i)-1-q[ty];
        lg=max(lg, l-d), rg=min(rg, r-d);
        if(lg<=rg)
        {
            int x=lg*2+ty+rg*2+ty, y=rg-lg+1;
            if(x%2==0) x/=2;
            else y/=2;
            an=(an+(x%mod)*(y%mod))%mod;
        }
        q[ty]+=(1ll<<i);
    }
    cout<<an;
}