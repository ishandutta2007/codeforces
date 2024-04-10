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
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        auto f=[&](ll k)->ll
        {
            return (k+1)*a-(k*(k+1)/2)*b*d;
        };
        if(a>b*c) cout << "-1\n";
        else if(a<=b) cout << a << "\n";
        else if(c<d) cout << a << "\n";
        else
        {
            ll l=-1,r=(c/d);
            //for(ll i=0;i<=(c/d);i++) cout << "f(" << i << ")=" << f(i) << endl;
            while(l<r-1)
            {
                ll m=(l+r)/2;
                if(a-b*d*m-b*d>=0) l=m;
                else r=m;
            }
            cout << f(l+1) << "\n";
        }
    }
    return 0;
}