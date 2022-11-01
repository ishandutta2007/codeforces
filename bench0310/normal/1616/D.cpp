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
        vector<ll> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        ll x;
        cin >> x;
        for(int i=1;i<=n;i++) a[i]-=x;
        int res=n;
        vector<ll> sum(n+1,0);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        auto s=[&](int l,int r)->ll{return (sum[r]-sum[l-1]);};
        int l=1;
        while(l<=n)
        {
            ll m=-(1ll<<60);
            for(int r=l;r<=n+1;r++)
            {
                if(r==n+1)
                {
                    l=n+1;
                    break;
                }
                if(r>l) m=max(m,s(l,r-2));
                if(s(l,r)-m<0)
                {
                    res--;
                    l=r+1;
                    break;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}