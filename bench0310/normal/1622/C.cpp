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
        ll k;
        cin >> n >> k;
        vector<ll> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        ranges::sort(a);
        ll m=a[1];
        vector<ll> sum(n+1,0);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        auto ifloor=[&](ll x,ll y)->ll
        {
            if(x>=0) return (x/y);
            else return (x/y)-((x%y)!=0);
        };
        ll res=(1ll<<60);
        for(int r=n+1;r>=2;r--)
        {
            ll s=(sum[r-1]-sum[1]);
            ll lim=m-ifloor(k-s,n-r+2);
            res=min(res,n-r+1+max(ll(0),lim));
        }
        cout << res << "\n";
    }
    return 0;
}