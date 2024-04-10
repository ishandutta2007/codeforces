#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll x, y, z;
    cin >> x >> y >> z;
    ll a, b, c;
    cin >> a >> b >> c;
    if(x > a) {
        cout << "NO" << endl;
        return 0;
    }
    a -= x;
    b += a;
    if(y > b) {
        cout << "NO" << endl;
        return 0;
    }
    b -= y;
    c += b;
    if(z > c) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}