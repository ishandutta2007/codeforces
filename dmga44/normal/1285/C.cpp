#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll x;
    cin >> x;
    pii res=pii(1e13,1e13);
    for(ll i=1;i<=(1e6+5);i++)
        if(x%i==0)
        {
            ll r1=i;
            ll r2=x/i;
            if(__gcd(r1,r2)==1 && max(r1,r2)<max(res.first,res.second))
                res=pii(r1,r2);
        }
    cout << res.first << ' ' << res.second << '\n';

    return 0;
}