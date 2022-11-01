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
        ll k,x;
        cin >> k >> x;
        ll l=0,r=2*k-1;
        auto f=[&](ll c)->ll
        {
            if(c<=k) return (c*(c+1)/2);
            else return (k*k-(2*k-1-c)*(2*k-1-c+1)/2);
        };
        while(l<r-1)
        {
            ll m=(l+r)/2;
            if(f(m)<x) l=m;
            else r=m;
        }
        cout << r << "\n";
    }
    return 0;
}