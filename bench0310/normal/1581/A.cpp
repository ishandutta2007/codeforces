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
        int n;
        cin >> n;
        const ll mod=1000000007;
        ll r=1;
        for(ll i=3;i<=2*n;i++) r=(r*i)%mod;
        cout << r << "\n";
    }
    return 0;
}