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
        const ll mod=1000000007;
        ll b=1;
        ll r=0;
        while(k)
        {
            if(k&1) r=(r+b)%mod;
            b=(b*n)%mod;
            k/=2;
        }
        cout << r << "\n";
    }
    return 0;
}