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
        ll n,k;
        cin >> n >> k;
        auto mv=[&](ll a,ll x)->ll
        {
            a=(a-1+x+n)%n;
            return a+1;
        };
        if((n%2)==0) cout << mv(1,k-1) << "\n";
        else cout << mv(1,k-1+(k-1)/(n/2)) << "\n";
    }
    return 0;
}