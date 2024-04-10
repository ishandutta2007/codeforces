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
        ll n;
        cin >> n;
        auto ok=[&]()->bool
        {
            ll s=0;
            ll z=n;
            while(z)
            {
                s+=(z%10);
                z/=10;
            }
            return (gcd(n,s)>1);
        };
        while(ok()==0) n++;
        cout << n << "\n";
    }
    return 0;
}