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
        ll s,n,k;
        cin >> s >> n >> k;
        bool res=![&]()->bool
        {
            if(k>s) return 1;
            if(k==s) return 0;
            ll x=(n/k);
            ll c=x*2*k+(n%k);
            if(c<=s) return 1;
            return 0;
        }();
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}