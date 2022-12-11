#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i < 1000; ++i) {
        for (ll j = 0; j < 10000; ++j) {
            ll k = i*1234567ll + j*123456ll;
            if (k > n) continue;
            k = n - k;
            if (k%1234 == 0) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}