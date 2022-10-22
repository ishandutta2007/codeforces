#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll x, y; cin >> x >> y;
        if(x > y) cout << x + y << "\n";
        else if(x == y) cout << x << "\n";
        else
        {
            ll a = y/x;
            ll k = (y - a*x)/2;
            cout << y - k << "\n";
        }
    }
}