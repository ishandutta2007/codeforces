#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for(ll &x:a) cin >> x;
        ranges::sort(a);
        auto f=[&](ll t)->ll
        {
            ll y=(a[0]+t)*(a[n-1]+t)-(n-1)*t*t;
            for(int i=1;i<n-1;i++) y+=min((a[0]+t)*(a[i]+t),(a[n-1]+t)*(a[i]+t));
            return y;
        };
        auto tp=[&](ll x)->int
        {
            ll b=f(x),c=f(x+1);
            return ((b==c)?0:(b<c?1:-1));
        };
        ll l=-2000000,r=2000000;
        if(tp(l)>=0&&tp(r-1)<=0)
        {
            while(l<r-2)
            {
                ll m=midpoint(l,r);
                if(tp(m)>=0) l=m;
                else r=m+1;
            }
            cout << f(l+1) << "\n";
        }
        else cout << "INF\n";
    }
    return 0;
}