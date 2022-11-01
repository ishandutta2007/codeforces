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
        ll p,a,b,c;
        cin >> p >> a >> b >> c;
        auto f=[&](ll x)->ll{return ((p+x-1)/x);};
        ll res=min(min(a*f(a),b*f(b)),c*f(c));
        cout << res-p << "\n";
    }
    return 0;
}