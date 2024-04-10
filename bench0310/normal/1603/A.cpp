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
        bool ok=1;
        ll l=1;
        ll lim=(1ll<<30);
        for(int i=1;i<=n;i++)
        {
            ll a;
            cin >> a;
            if(l<lim) l=lcm(l,i+1);
            ok&=((a%l)!=0);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}