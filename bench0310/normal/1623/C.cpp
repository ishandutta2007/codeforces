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
        vector<ll> h(n+1,0);
        for(int i=1;i<=n;i++) cin >> h[i];
        ll l=0,r=1000000001;
        while(l<r-1)
        {
            ll m=(l+r)/2;
            vector<ll> y=h;
            bool ok=1;
            for(int i=n;i>=1;i--)
            {
                ok&=(y[i]>=m);
                if(i>=3)
                {
                    ll mx=max(ll(0),min(h[i],y[i]-m))/3;
                    y[i]-=3*mx;
                    y[i-1]+=mx;
                    y[i-2]+=2*mx;
                }
            }
            if(ok) l=m;
            else r=m;
        }
        cout << l << "\n";
    }
    return 0;
}