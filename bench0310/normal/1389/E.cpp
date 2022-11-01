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
        ll m,d,w;
        cin >> m >> d >> w;
        ll a=(w/gcd(d-1,w));
        ll y=min(m,d);
        //cout << "a=" << a << endl;
        //cout << "y=" << y << endl;
        ll res=((y/a)*((y/a)-1)/2)*a+(y%a)*((y-1)/a);
        cout << res << "\n";
    }
    return 0;
}