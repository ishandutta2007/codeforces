#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int QQ;
    cin >> QQ;
    while(QQ--) {
        ll n, a, b;
        cin >> n >> a >> b;
        ll c = 0;
        if(b > 2*a) {
            c = a*n;
        } else {
            c = a*(n%2) + b*(n/2);
        }
        cout << c << "\n";
    }
    return 0;
}