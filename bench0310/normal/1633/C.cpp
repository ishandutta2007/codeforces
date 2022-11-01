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
        ll hc,dc,mhp,matt;
        cin >> hc >> dc >> mhp >> matt;
        ll k,w,a;
        cin >> k >> w >> a;
        bool ok=0;
        for(ll i=0;i<=k;i++)
        {
            ll att=dc+i*w;
            ll hp=hc+(k-i)*a;
            ll x=(mhp+att-1)/att;
            ll y=(hp+matt-1)/matt;
            ok|=(x<=y);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}