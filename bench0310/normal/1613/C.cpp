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
        ll h;
        cin >> n >> h;
        vector<ll> a(n+1,0);
        for(int i=0;i<n;i++) cin >> a[i];
        a[n]=(1ll<<60);
        ll l=0,r=h;
        while(l<r-1)
        {
            ll m=(l+r)/2;
            ll x=0;
            for(int i=0;i<n;i++) x+=min(m,a[i+1]-a[i]);
            if(x>=h) r=m;
            else l=m;
        }
        cout << r << "\n";
    }
    return 0;
}