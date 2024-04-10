#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        map<array<ll,2>,ll> m;
        for(int i=0;i<n;i++)
        {
            ll x,y,a,b;
            cin >> x >> y >> a >> b;
            ll dx=(a-x);
            ll dy=(b-y);
            ll g=gcd(dx,dy);
            dx/=g; dy/=g;
            m[{dx,dy}]++;
        }
        ll res=0;
        for(auto [z,c]:m)
        {
            auto [a,b]=z;
            if(m.find({-a,-b})!=m.end()) res+=(c*m[{-a,-b}]);
        }
        cout << res/2 << "\n";
    }
    return 0;
}