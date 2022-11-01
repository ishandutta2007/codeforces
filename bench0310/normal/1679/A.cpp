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
        if((n&1)||n==2) cout << "-1\n";
        else
        {
            n/=2;
            ll c=(n&1?(n-3)/2:n/2);
            ll b=c+(n&1);
            ll x=(c/3);
            cout << b-x << " " << b << "\n";
        }
    }
    return 0;
}