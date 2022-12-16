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
        ll x = 9;
        ll amt = 0;
        while (x <= b) {
            ++amt;
            x=x*10+9;
        }
        cout << a*amt << endl;
    }
    return 0;
}