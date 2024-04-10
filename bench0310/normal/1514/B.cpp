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
        ll res=1;
        for(int i=0;i<k;i++) res=(res*n)%mod;
        cout << res << "\n";
    }
    return 0;
}