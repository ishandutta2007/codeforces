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
        ll r,b,d;
        cin >> r >> b >> d;
        ll c=min(r,b);
        ll mx=c*d;
        if(abs(r-b)<=mx) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}