#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        ll a, b;
        cin >> a >> b;
        ll x = abs(b-a);
        int i = 0;
        for (i=0; i*(i+1)/2 < x; ++i);
        //cerr << " i " << i << " x " << x << endl;
        assert (i*(i+1)/2 >= x);
        ll sum = i*(i+1)/2;
        if (x%2 == sum%2) {
            cout << i << endl;
        } else {
            while (x%2 != (i*(i+1)/2)%2) ++i;
            cout << i << endl;
        }
    }
    return 0;
}