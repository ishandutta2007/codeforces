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
        for(ll x=n;;x++)
        {
            bool ok=1;
            ll a=x;
            while(a)
            {
                ll b=(a%10);
                if(b!=0) ok&=((x%b)==0);
                a/=10;
            }
            if(ok)
            {
                cout << x << "\n";
                break;
            }
        }
    }
    return 0;
}