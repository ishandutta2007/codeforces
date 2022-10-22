#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll s(ll x)
{
    ll l = 1, r = x;
    while(l < r)
    {
        ll mid = (l + r)/2;
        if(mid * mid < x)
        {
            l = mid + 1;
        }
        else r = mid;
    }

    return l;
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        bool flag = false;
        if(s(n) * s(n) == n && s(n)%2 == 0) flag = true;
        if(s(2*n) * s(2*n) == 2 * n) flag = true;

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}