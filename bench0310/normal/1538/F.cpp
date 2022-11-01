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
        int l,r;
        cin >> l >> r;
        auto f=[&](ll n)->ll
        {
            ll p=9;
            ll c=0;
            while(p<=n)
            {
                c+=(1+(n-p)/(p+1));
                p=10*p+9;
            }
            return c;
        };
        cout << f(r-1)-f(l-1)+r-l << "\n";
    }
    return 0;
}