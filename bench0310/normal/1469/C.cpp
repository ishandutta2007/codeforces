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
        vector<ll> h(n+1,0);
        for(int i=1;i<=n;i++) cin >> h[i];
        bool res=[&]()->bool
        {
            ll a=h[1];
            ll b=h[1];
            for(int i=2;i<=n;i++)
            {
                ll c=a-k+1;
                ll d=b+k-1;
                c=max(c,h[i]);
                d=max(d,h[i]);
                c=min(c,h[i]+k-1);
                d=min(d,h[i]+k-1);
                if(c>d) return 0;
                if(a-d>=k||c-b>=k) return 0;
                tie(a,b)={c,d};
            }
            return (a<=h[n]&&h[n]<=b);
        }();
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}