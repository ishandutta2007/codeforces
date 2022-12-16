#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll x;
    cin >> x;
    if (x == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<ll> pf;
    for (ll i=2; i*i<=x; ++i) {
        if (x%i == 0) {
            pf.push_back(i);
            while (x%i == 0) {
                x /= i;
            }
        }
    }
    if (x != 1) {
        pf.push_back(x);
    }

    if (pf.size() > 1) {
        cout << 1 << endl;
        return 0;
    }
    cout << pf[0] << endl;
    return 0;
}