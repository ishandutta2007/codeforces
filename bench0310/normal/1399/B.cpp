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
        ll x=(1<<30);
        vector<ll> a(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            x=min(x,a[i]);
        }
        ll y=(1<<30);
        vector<ll> b(n);
        for(int i=0;i<n;i++)
        {
            cin >> b[i];
            y=min(y,b[i]);
        }
        ll res=0;
        for(int i=0;i<n;i++)
        {
            ll z=min(a[i]-x,b[i]-y);
            res+=(z+a[i]-x+b[i]-y-2*z);
        }
        cout << res << "\n";
    }
    return 0;
}