#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x:a) cin >> x;
    ranges::sort(a);
    cout << [&]()->ll
    {
        ll res=(1ll<<60);
        ll lim=(1ll<<50);
        for(ll c=1;;c++)
        {
            ll now=0;
            ll t=1;
            for(int i=0;i<n;i++)
            {
                if(i>0)
                {
                    if(t>=(lim+c-1)/c) return res;
                    t*=c;
                }
                now+=abs(a[i]-t);
            }
            res=min(res,now);
            if(t>=a[n-1]) break;
        }
        return res;
    }() << "\n";
    return 0;
}