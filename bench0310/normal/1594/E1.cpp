#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll k;
    cin >> k;
    const ll mod=1000000007;
    auto fpow=[&](ll b,ll e)->ll
    {
        ll r=1;
        while(e)
        {
            if(e&1) r=(r*b)%mod;
            b=(b*b)%mod;
            e/=2;
        }
        return r;
    };
    cout << (6*fpow(4,(1ll<<k)-2))%mod << "\n";
    return 0;
}