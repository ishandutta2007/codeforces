#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    auto x=[](ll a)->ll
    {
        a++;
        ll res=0;
        for(ll i=0;a>(1ll<<i);i++)
        {
            ll r=(1ll<<i);
            ll c=(r*(a/(2*r)));
            ll s=(a%(2*r));
            c+=max(0ll,s-r);
            if(c&1) res|=(1ll<<i);
        }
        return res;
    };
    auto y=[&](ll a,ll b)->ll{return (x(b)^x(a-1));};
    ll res=0;
    while(n--)
    {
        ll a,b;
        cin >> a >> b;
        res^=y(a,a+b-1);
    }
    cout << "bt"[res>0] << "olik\n";
    return 0;
}