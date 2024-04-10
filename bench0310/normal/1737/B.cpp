#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto s=[&](ll p)->ll
    {
        ll l=0,r=(1ll<<30);
        while(l<r-1)
        {
            ll m=(l+r)/2;
            if(m*m<=p) l=m;
            else r=m;
        }
        ll res=3*(l-1);
        for(ll i=0;i<3;i++) res+=(l*l+i*l<=p);
        return res;
    };
    int t;
    cin >> t;
    while(t--)
    {
        ll l,r;
        cin >> l >> r;
        cout << s(r)-s(l-1) << "\n";
    }
    return 0;
}